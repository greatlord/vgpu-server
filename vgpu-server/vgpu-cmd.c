
#define _CRT_SECURE_NO_WARNINGS
#define CL_TARGET_OPENCL_VERSION 220

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include <CL/opencl.h>

#include "../../dyad/src/dyad.h"

#include "vgpu-common.h"
#include "read-gpu-opengl.h"

#define MAX_VGPU_CLIENTS    256

// global value only use here
int vgpu_client_id = -1;
VPGU_CLIENT_TRACK vgpu_client_track[MAX_VGPU_CLIENTS];


int vpgu_check_client_version( PVGPU_TRANS_HEAD head, int size ) {

    if ( head->clientId == -1 ) {
        if ( size < sizeof(VGPU_TRANS_HEAD) ) {
            return -1;
        }

        if ( strcmp( head->txtVersion, txtClientVersion) != 0) {
            return -1;
        }
    }
    return 1;
}

int createNewClientId( PVGPU_TRANS_HEAD head, dyad_Event *e ) {

    int newClient = false;

     // client ask for new clientid
    if ( head->clientId == -1 ) {

        if ( vgpu_client_id >= MAX_VGPU_CLIENTS ) {
            return -2;
        }
        vgpu_client_id++;

        head->clientId = vgpu_client_id;

        vgpu_client_track[vgpu_client_id].clientVersion = head->clientId;

        // setup server info
        sprintf(head->txtVersion,"%s",txtServerVersion);
        head->serverVersion = 1;

        dyad_write(e->stream, head, sizeof(VGPU_TRANS_HEAD));

        newClient = true;
    }
    return newClient;
}

int vgpu_check_if_client_is_vaild(PVGPU_TRANS_HEAD head, dyad_Event *e  ) {

	int ret;

	// check if it a vgpu client
    ret = vpgu_check_client_version(head, e->size);
    if (!ret) {
        // no gpu client found
        return -1;
    }

    // client ask for new clientid
    ret = createNewClientId(head, e);
    if ( ret == -2 ) {
        // out of of ClientIds
        return -2;
    }
    if (ret) {
        return 2;
    }
    return 1;
}


#define VGPU_CMD_HELLO  0

int vgpu_cmd(dyad_Event *e) {

    int ret;
    PVGPU_TRANS_HEAD head;

     // transform begin of data to our header
    head = (PVGPU_TRANS_HEAD) e->data;


    ret = vgpu_check_if_client_is_vaild( head, e);
    if (!ret) {
        // no gpu client found or other errors
        // -1 = no gpu client found
        // -2 = out of of ClientIds
        return -1;
    }

    printf(" server client id : %d \n", head->clientId);

    if ( ret == 2) {
        // it was a new client. waiting on commands now
        return 0;
    }

    switch ( head->cmd ) {
        case VGPU_CMD_HELLO:            
            dyad_write(e->stream, e->data, e->size);
            break;

    //OpenCL.API 1.0
        case VGPU_CMD_CLBUILDPROGRAM:
		    readVgpu_clBuildProgram(e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLCREATEBUFFER:
        case VGPU_CMD_CLCREATECOMMANDQUEUE:
        case VGPU_CMD_CLCREATECONTEXT:
        case VGPU_CMD_CLCREATECONTEXTFROMTYPE:
        case VGPU_CMD_CLCREATEFROMGLBUFFER:
        case VGPU_CMD_CLCREATEFROMGLRENDERBUFFER:
        case VGPU_CMD_CLCREATEFROMGLTEXTURE2D:
        case VGPU_CMD_CLCREATEFROMGLTEXTURE3D:
        case VGPU_CMD_CLCREATEIMAGE2D:
        case VGPU_CMD_CLCREATEIMAGE3D:
        case VGPU_CMD_CLCREATEKERNEL:
        case VGPU_CMD_CLCREATEKERNELSINPROGRAM:
        case VGPU_CMD_CLCREATEPROGRAMWITHBINARY:
        case VGPU_CMD_CLCREATEPROGRAMWITHSOURCE:
        case VGPU_CMD_CLCREATESAMPLER:
        case VGPU_CMD_CLENQUEUEACQUIREGLOBJECTS:
        case VGPU_CMD_CLENQUEUEBARRIER:
        case VGPU_CMD_CLENQUEUECOPYBUFFER:
        case VGPU_CMD_CLENQUEUECOPYBUFFERTOIMAGE:
        case VGPU_CMD_CLENQUEUECOPYIMAGE:
        case VGPU_CMD_CLENQUEUECOPYIMAGETOBUFFER:
        case VGPU_CMD_CLENQUEUEMAPBUFFER:
        case VGPU_CMD_CLENQUEUEMAPIMAGE:
        case VGPU_CMD_CLENQUEUEMARKER:
        case VGPU_CMD_CLENQUEUENDRANGEKERNEL:
        case VGPU_CMD_CLENQUEUENATIVEKERNEL:
        case VGPU_CMD_CLENQUEUEREADBUFFER:
        case VGPU_CMD_CLENQUEUEREADIMAGE:
        case VGPU_CMD_CLENQUEUERELEASEGLOBJECTS:
        case VGPU_CMD_CLENQUEUETASK:
        case VGPU_CMD_CLENQUEUEUNMAPMEMOBJECT:
        case VGPU_CMD_CLENQUEUEWAITFOREVENTS:
        case VGPU_CMD_CLENQUEUEWRITEBUFFER:
        case VGPU_CMD_CLENQUEUEWRITEIMAGE:
        case VGPU_CMD_CLFINISH:
        case VGPU_CMD_CLFLUSH:
        case VGPU_CMD_CLGETCOMMANDQUEUEINFO:
        case VGPU_CMD_CLGETCONTEXTINFO:
        case VGPU_CMD_CLGETDEVICEIDS:
        case VGPU_CMD_CLGETDEVICEINFO:
        case VGPU_CMD_CLGETEVENTINFO:
        case VGPU_CMD_CLGETEVENTPROFILINGINFO:
        case VGPU_CMD_CLGETEXTENSIONFUNCTIONADDRESS:
        case VGPU_CMD_CLGETGLOBJECTINFO:
        case VGPU_CMD_CLGETGLTEXTUREINFO:
        case VGPU_CMD_CLGETIMAGEINFO:
        case VGPU_CMD_CLGETKERNELINFO:
        case VGPU_CMD_CLGETKERNELWORKGROUPINFO:
        case VGPU_CMD_CLGETMEMOBJECTINFO:
        case VGPU_CMD_CLGETPLATFORMIDS:
        case VGPU_CMD_CLGETPLATFORMINFO:
        case VGPU_CMD_CLGETPROGRAMBUILDINFO:
        case VGPU_CMD_CLGETPROGRAMINFO:
        case VGPU_CMD_CLGETSAMPLERINFO:
        case VGPU_CMD_CLGETSUPPORTEDIMAGEFORMATS:
        case VGPU_CMD_CLRELEASECOMMANDQUEUE:
        case VGPU_CMD_CLRELEASECONTEXT:
        case VGPU_CMD_CLRELEASEEVENT:
        case VGPU_CMD_CLRELEASEKERNEL:
        case VGPU_CMD_CLRELEASEMEMOBJECT:
        case VGPU_CMD_CLRELEASEPROGRAM:
        case VGPU_CMD_CLRELEASESAMPLER:
        case VGPU_CMD_CLRETAINCOMMANDQUEUE:
        case VGPU_CMD_CLRETAINCONTEXT:
        case VGPU_CMD_CLRETAINEVENT:
        case VGPU_CMD_CLRETAINKERNEL:
        case VGPU_CMD_CLRETAINMEMOBJECT:
        case VGPU_CMD_CLRETAINPROGRAM:
        case VGPU_CMD_CLRETAINSAMPLER:
        case VGPU_CMD_CLSETCOMMANDQUEUEPROPERTY:
        case VGPU_CMD_CLSETKERNELARG:
        case VGPU_CMD_CLUNLOADCOMPILER:
        case VGPU_CMD_CLWAITFOREVENTS:

//OpenCL.API 1.1
        case VGPU_CMD_CLCREATESUBBUFFER:
        case VGPU_CMD_CLCREATEUSEREVENT:
        case VGPU_CMD_CLENQUEUECOPYBUFFERRECT:
        case VGPU_CMD_CLENQUEUEREADBUFFERRECT:
        case VGPU_CMD_CLENQUEUEWRITEBUFFERRECT:
        case VGPU_CMD_CLSETEVENTCALLBACK:
        case VGPU_CMD_CLSETMEMOBJECTDESTRUCTORCALLBACK:
        case VGPU_CMD_CLSETUSEREVENTSTATUS:

//OpenCL.API 1.2
        case VGPU_CMD_CLCOMPILEPROGRAM:
        case VGPU_CMD_CLCREATEFROMGLTEXTURE:
        case VGPU_CMD_CLCREATEIMAGE:
        case VGPU_CMD_CLCREATEPROGRAMWITHBUILTINKERNELS:
        case VGPU_CMD_CLCREATESUBDEVICES:
        case VGPU_CMD_CLENQUEUEBARRIERWITHWAITLIST:
        case VGPU_CMD_CLENQUEUEFILLBUFFER:
        case VGPU_CMD_CLENQUEUEFILLIMAGE:
        case VGPU_CMD_CLENQUEUEMARKERWITHWAITLIST:
        case VGPU_CMD_CLENQUEUEMIGRATEMEMOBJECTS:
        case VGPU_CMD_CLGETEXTENSIONFUNCTIONADDRESSFORPLATFORM:
        case VGPU_CMD_CLGETKERNELARGINFO:
        case VGPU_CMD_CLLINKPROGRAM:
        case VGPU_CMD_CLRELEASEDEVICE:
        case VGPU_CMD_CLRETAINDEVICE:
        case VGPU_CMD_CLUNLOADPLATFORMCOMPILER:

//OpenCL.API 2.0
        case VGPU_CMD_CLCREATECOMMANDQUEUEWITHPROPERTIES:
        case VGPU_CMD_CLCREATEPIPE:
        case VGPU_CMD_CLCREATESAMPLERWITHPROPERTIES:
        case VGPU_CMD_CLENQUEUESVMFREE:
        case VGPU_CMD_CLENQUEUESVMMAP:
        case VGPU_CMD_CLENQUEUESVMMEMCPY:
        case VGPU_CMD_CLENQUEUESVMMEMFILL:
        case VGPU_CMD_CLENQUEUESVMUNMAP:
        case VGPU_CMD_CLGETPIPEINFO:
        case VGPU_CMD_CLSETKERNELARGSVMPOINTER:
        case VGPU_CMD_CLSETKERNELEXECINFO:
        case VGPU_CMD_CLSVMALLOC:
        case VGPU_CMD_CLSVMFREE:

//OpenCL.API 2.1
        case VGPU_CMD_CLCLONEKERNEL:
        case VGPU_CMD_CLCREATEPROGRAMWITHIL:
        case VGPU_CMD_CLENQUEUESVMMIGRATEMEM:
        case VGPU_CMD_CLGETDEVICEANDHOSTTIMER:
        case VGPU_CMD_CLGETHOSTTIMER:
        case VGPU_CMD_CLGETKERNELSUBGROUPINFO:
        case VGPU_CMD_CLSETDEFAULTDEVICECOMMANDQUEUE:

    //OpenCL.API 2.2
        case VGPU_CMD_CLSETPROGRAMRELEASECALLBACK:
        case VGPU_CMD_CLSETPROGRAMSPECIALIZATIONCONSTANT:


        default:
            dyad_write(e->stream, e->data, e->size);
    }

    // we got data to *e
    // send back same data
    dyad_write(e->stream, e->data, e->size);

    return 0;
}

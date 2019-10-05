
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
		    readVgpu_clBuildProgram (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLCREATEBUFFER:
            readVgpu_clCreateBuffer (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLCREATECOMMANDQUEUE:
            readVgpu_clCreateContext (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLCREATECONTEXT:
            readVgpu_clCreateContext (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLCREATECONTEXTFROMTYPE:
            readVgpu_clCreateContextFromType (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLCREATEFROMGLBUFFER:
            readVgpu_clCreateFromGLBuffer (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLCREATEFROMGLRENDERBUFFER:
            readVgpu_clCreateFromGLRenderbuffer (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLCREATEFROMGLTEXTURE2D:
            readVgpu_clCreateFromGLTexture2D (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLCREATEFROMGLTEXTURE3D:
            readVgpu_clCreateFromGLTexture3D (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLCREATEIMAGE2D:
            readVgpu_clCreateImage2D (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLCREATEIMAGE3D:
            readVgpu_clCreateImage3D (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLCREATEKERNEL:
            readVgpu_clCreateKernel (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLCREATEKERNELSINPROGRAM:
            readVgpu_clCreateKernelsInProgram (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLCREATEPROGRAMWITHBINARY:
            readVgpu_clCreateProgramWithBinary (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLCREATEPROGRAMWITHSOURCE:
            readVgpu_clCreateProgramWithSource (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLCREATESAMPLER:
            readVgpu_clCreateSampler (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLENQUEUEACQUIREGLOBJECTS:
            readVgpu_clEnqueueAcquireGLObjects (e->stream, e->data, e->size);
            break;

        case VGPU_CMD_CLENQUEUEBARRIER:
            readVgpu_clEnqueueBarrier (e->stream, e->data, e->size);
            break;

        case VGPU_CMD_CLENQUEUECOPYBUFFER:
            readVgpu_clEnqueueCopyBuffer (e->stream, e->data, e->size);
            break;

        case VGPU_CMD_CLENQUEUECOPYBUFFERTOIMAGE:
            readVgpu_clEnqueueCopyBufferToImage (e->stream, e->data, e->size);
            break;

        case VGPU_CMD_CLENQUEUECOPYIMAGE:
            readVgpu_clEnqueueCopyImage (e->stream, e->data, e->size);
            break;

        case VGPU_CMD_CLENQUEUECOPYIMAGETOBUFFER:
            readVgpu_clEnqueueCopyImageToBuffer (e->stream, e->data, e->size);
            break;

        case VGPU_CMD_CLENQUEUEMAPBUFFER:
            readVgpu_clEnqueueMapBuffer (e->stream, e->data, e->size);
            break;

        case VGPU_CMD_CLENQUEUEMAPIMAGE:
            readVgpu_clEnqueueMapImage (e->stream, e->data, e->size);
            break;

        case VGPU_CMD_CLENQUEUEMARKER:
            readVgpu_clEnqueueMarker (e->stream, e->data, e->size);
            break;

        case VGPU_CMD_CLENQUEUENDRANGEKERNEL:
            readVgpu_clEnqueueNDRangeKernel (e->stream, e->data, e->size);
            break;

        case VGPU_CMD_CLENQUEUENATIVEKERNEL:
            readVgpu_clEnqueueNativeKernel (e->stream, e->data, e->size);
            break;

        case VGPU_CMD_CLENQUEUEREADBUFFER:
            readVgpu_clEnqueueReadBuffer (e->stream, e->data, e->size);
            break;

        case VGPU_CMD_CLENQUEUEREADIMAGE:
            readVgpu_clEnqueueReadImage (e->stream, e->data, e->size);
            break;

        case VGPU_CMD_CLENQUEUERELEASEGLOBJECTS:
            readVgpu_clEnqueueReleaseGLObjects (e->stream, e->data, e->size);
            break;

        case VGPU_CMD_CLENQUEUETASK:
            readVgpu_clEnqueueTask (e->stream, e->data, e->size);
            break;

        case VGPU_CMD_CLENQUEUEUNMAPMEMOBJECT:
            readVgpu_clEnqueueUnmapMemObject (e->stream, e->data, e->size);
            break;

        case VGPU_CMD_CLENQUEUEWAITFOREVENTS:
            readVgpu_clEnqueueWaitForEvents (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLENQUEUEWRITEBUFFER:
            readVgpu_clEnqueueWriteBuffer (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLENQUEUEWRITEIMAGE:
            readVgpu_clEnqueueWriteImage (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLFINISH:
            readVgpu_clFinish (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLFLUSH:
            readVgpu_clFlush (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLGETCOMMANDQUEUEINFO:
            readVgpu_clGetCommandQueueInfo (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLGETCONTEXTINFO:
            readVgpu_clGetContextInfo (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLGETDEVICEIDS:
            readVgpu_clGetDeviceIDs (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLGETDEVICEINFO:
            readVgpu_clGetDeviceInfo (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLGETEVENTINFO:
            readVgpu_clGetEventInfo (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLGETEVENTPROFILINGINFO:
            readVgpu_clGetEventProfilingInfo (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLGETEXTENSIONFUNCTIONADDRESS:
            readVgpu_clGetExtensionFunctionAddress (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLGETGLOBJECTINFO:
            readVgpu_clGetGLObjectInfo (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLGETGLTEXTUREINFO:
            readVgpu_clGetGLTextureInfo (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLGETIMAGEINFO:
            readVgpu_clGetImageInfo (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLGETKERNELINFO:
            readVgpu_clGetKernelInfo (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLGETKERNELWORKGROUPINFO:
            readVgpu_clGetKernelWorkGroupInfo (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLGETMEMOBJECTINFO:
            readVgpu_clGetMemObjectInfo (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLGETPLATFORMIDS:
            readVgpu_clGetPlatformIDs (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLGETPLATFORMINFO:
            readVgpu_clGetPlatformInfo (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLGETPROGRAMBUILDINFO:
            readVgpu_clGetProgramBuildInfo (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLGETPROGRAMINFO:
            readVgpu_clGetProgramInfo (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLGETSAMPLERINFO:
            readVgpu_clGetSamplerInfo (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLGETSUPPORTEDIMAGEFORMATS:
            readVgpu_clGetSupportedImageFormats (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLRELEASECOMMANDQUEUE:
            readVgpu_clReleaseCommandQueue (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLRELEASECONTEXT:
            readVgpu_clReleaseContext (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLRELEASEEVENT:
            readVgpu_clReleaseEvent (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLRELEASEKERNEL:
            readVgpu_clReleaseKernel (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLRELEASEMEMOBJECT:
            readVgpu_clReleaseMemObject (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLRELEASEPROGRAM:
            readVgpu_clReleaseProgram (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLRELEASESAMPLER:
            readVgpu_clReleaseSampler (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLRETAINCOMMANDQUEUE:
            readVgpu_clRetainCommandQueue (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLRETAINCONTEXT:
            readVgpu_clRetainContext (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLRETAINEVENT:
            readVgpu_clRetainEvent (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLRETAINKERNEL:
            readVgpu_clRetainKernel (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLRETAINMEMOBJECT:
            readVgpu_clRetainMemObject (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLRETAINPROGRAM:
            readVgpu_clRetainProgram (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLRETAINSAMPLER:
            readVgpu_clRetainSampler (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLSETCOMMANDQUEUEPROPERTY:
            readVgpu_clSetCommandQueueProperty (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLSETKERNELARG:
            readVgpu_clSetKernelArg (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLUNLOADCOMPILER:
            readVgpu_clUnloadCompiler (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLWAITFOREVENTS:
            readVgpu_clWaitForEvents (e->stream, e->data, e->size);
		    break;

//OpenCL.API 1.1
        case VGPU_CMD_CLCREATESUBBUFFER:
            //readVgpu_clBuildProgram (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLCREATEUSEREVENT:
            //readVgpu_clBuildProgram (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLENQUEUECOPYBUFFERRECT:
            //readVgpu_clBuildProgram (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLENQUEUEREADBUFFERRECT:
            //readVgpu_clBuildProgram (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLENQUEUEWRITEBUFFERRECT:
            //readVgpu_clBuildProgram (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLSETEVENTCALLBACK:
            //readVgpu_clBuildProgram (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLSETMEMOBJECTDESTRUCTORCALLBACK:
            //readVgpu_clBuildProgram (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLSETUSEREVENTSTATUS:
            //readVgpu_clBuildProgram (e->stream, e->data, e->size);
		    break;

//OpenCL.API 1.2
        case VGPU_CMD_CLCOMPILEPROGRAM:
            //readVgpu_clBuildProgram (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLCREATEFROMGLTEXTURE:
            //readVgpu_clBuildProgram (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLCREATEIMAGE:
            //readVgpu_clBuildProgram (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLCREATEPROGRAMWITHBUILTINKERNELS:
            //readVgpu_clBuildProgram (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLCREATESUBDEVICES:
            //readVgpu_clBuildProgram (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLENQUEUEBARRIERWITHWAITLIST:
            //readVgpu_clBuildProgram (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLENQUEUEFILLBUFFER:
            //readVgpu_clBuildProgram (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLENQUEUEFILLIMAGE:
            //readVgpu_clBuildProgram (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLENQUEUEMARKERWITHWAITLIST:
            //readVgpu_clBuildProgram (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLENQUEUEMIGRATEMEMOBJECTS:
            //readVgpu_clBuildProgram (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLGETEXTENSIONFUNCTIONADDRESSFORPLATFORM:
            //readVgpu_clBuildProgram (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLGETKERNELARGINFO:
            //readVgpu_clBuildProgram (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLLINKPROGRAM:
            //readVgpu_clBuildProgram (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLRELEASEDEVICE:
            //readVgpu_clBuildProgram (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLRETAINDEVICE:
            //readVgpu_clBuildProgram (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLUNLOADPLATFORMCOMPILER:
            //readVgpu_clBuildProgram (e->stream, e->data, e->size);
		    break;

//OpenCL.API 2.0
        case VGPU_CMD_CLCREATECOMMANDQUEUEWITHPROPERTIES:
            //readVgpu_clBuildProgram (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLCREATEPIPE:
            //readVgpu_clBuildProgram (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLCREATESAMPLERWITHPROPERTIES:
            //readVgpu_clBuildProgram (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLENQUEUESVMFREE:
            //readVgpu_clBuildProgram (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLENQUEUESVMMAP:
            //readVgpu_clBuildProgram (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLENQUEUESVMMEMCPY:
            //readVgpu_clBuildProgram (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLENQUEUESVMMEMFILL:
            //readVgpu_clBuildProgram (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLENQUEUESVMUNMAP:
            //readVgpu_clBuildProgram (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLGETPIPEINFO:
            //readVgpu_clBuildProgram (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLSETKERNELARGSVMPOINTER:
            //readVgpu_clBuildProgram (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLSETKERNELEXECINFO:
            //readVgpu_clBuildProgram (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLSVMALLOC:
            //readVgpu_clBuildProgram (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLSVMFREE:
            //readVgpu_clBuildProgram (e->stream, e->data, e->size);
		    break;

//OpenCL.API 2.1
        case VGPU_CMD_CLCLONEKERNEL:
            //readVgpu_clBuildProgram (e->stream, e->data, e->size);
		    break;
            
        case VGPU_CMD_CLCREATEPROGRAMWITHIL:
            //readVgpu_clBuildProgram (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLENQUEUESVMMIGRATEMEM:
            //readVgpu_clBuildProgram (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLGETDEVICEANDHOSTTIMER:
            //readVgpu_clBuildProgram (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLGETHOSTTIMER:
            //readVgpu_clBuildProgram (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLGETKERNELSUBGROUPINFO:
            //readVgpu_clBuildProgram (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLSETDEFAULTDEVICECOMMANDQUEUE:
            //readVgpu_clBuildProgram (e->stream, e->data, e->size);
		    break;

    //OpenCL.API 2.2
        case VGPU_CMD_CLSETPROGRAMRELEASECALLBACK:
            //readVgpu_clBuildProgram (e->stream, e->data, e->size);
		    break;

        case VGPU_CMD_CLSETPROGRAMSPECIALIZATIONCONSTANT:
            //readVgpu_clBuildProgram (e->stream, e->data, e->size);
		    break;


        default:
            dyad_write(e->stream, e->data, e->size);
    }

    // we got data to *e
    // send back same data
    dyad_write(e->stream, e->data, e->size);

    return 0;
}

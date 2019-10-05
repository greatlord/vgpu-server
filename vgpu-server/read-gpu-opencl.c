#define _CRT_SECURE_NO_WARNINGS
#define CL_TARGET_OPENCL_VERSION 220

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include <CL/opencl.h>

#include "../../dyad/src/dyad.h"

#include "load-gou-opencl-int.h"
#include "read-gpu-opengl.h"








void readVgpu_clBuildProgram (dyad_Stream *stream, const void *data, int size) {

    cl_int retVal;
    LDPARAM_READVGPU_CLBUILDPROGRAM cldata = (LDPARAM_READVGPU_CLBUILDPROGRAM) data;

    retVal = runVgpu_clBuildProgram (   cldata->program,    cldata->num_devices,    cldata->device_list, 
                                        cldata->strOptions, cldata->notify,         cldata->user_data);
    
    // send back status code
    dyad_write( stream, &retVal, sizeof(cl_int) );
}



void readVgpu_clCreateBuffer(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clCreateCommandQueue(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clCreateContext(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clCreateContextFromType(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clCreateFromGLBuffer(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clCreateFromGLRenderbuffer(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clCreateFromGLTexture2D(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clCreateFromGLTexture3D(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clCreateImage2D(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}


void readVgpu_clCreateImage3D(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}


void readVgpu_clCreateKernel(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clCreateKernelsInProgram(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clCreateProgramWithBinary(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clCreateProgramWithSource(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clCreateSampler(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}


void readVgpu_clEnqueueAcquireGLObjects(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clEnqueueBarrier(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clEnqueueCopyBuffer(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clEnqueueCopyBufferToImage(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clEnqueueCopyImage(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clEnqueueCopyImageToBuffer(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clEnqueueMapBuffer(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clEnqueueMapImage(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clEnqueueMarker(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clEnqueueNDRangeKernel(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clEnqueueNativeKernel(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clEnqueueReadBuffer(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clEnqueueReadImage(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clEnqueueReleaseGLObjects(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clEnqueueTask(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clEnqueueUnmapMemObject(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clEnqueueWaitForEvents(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clEnqueueWriteBuffer(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clEnqueueWriteImage(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clFinish(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clFlush(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clGetCommandQueueInfo(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clGetContextInfo(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clGetDeviceIDs(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clGetDeviceInfo(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clGetEventInfo(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clGetEventProfilingInfo(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clGetExtensionFunctionAddress(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clGetGLObjectInfo(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clGetGLTextureInfo(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clGetImageInfo(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clGetKernelInfo(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clGetKernelWorkGroupInfo(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clGetMemObjectInfo(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}


void readVgpu_clGetPlatformIDs(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}


void readVgpu_clGetPlatformInfo(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clGetProgramBuildInfo(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clGetSamplerInfo(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}


void readVgpu_clGetSupportedImageFormats(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clReleaseCommandQueue(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clReleaseContext(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}


void readVgpu_clReleaseMemObject(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clReleaseProgram(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clReleaseSampler(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clRetainCommandQueue(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clRetainContext(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clRetainEvent(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clRetainKernel(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clRetainMemObject(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clRetainProgram(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clRetainSampler(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clSetCommandQueueProperty(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clSetKernelArg(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clUnloadCompiler(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}

void readVgpu_clWaitForEvents(dyad_Stream *stream, const void *data, int size) {

    // todo : not implement yet

    // send back same data
    dyad_write( stream, data, size);

}


#define _CRT_SECURE_NO_WARNINGS
#define CL_TARGET_OPENCL_VERSION 220

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include <dlfcn.h>
#include <CL/opencl.h>

#include "load-gou-opencl-int.h"

#include "load-gpu-opencl-int.h"

/* offcial docs at https://www.khronos.org/registry/OpenCL/ 
  https://streamhpc.com/blog/2016-06-03/opencl-header-files-and-opencl-library/?upm_export=print

  Download a zip of the header files here:
  https://github.com/KhronosGroup/OpenCL-Headers/archive/opencl10.zip
  https://github.com/KhronosGroup/OpenCL-Headers/archive/opencl11.zip
  https://github.com/KhronosGroup/OpenCL-Headers/archive/opencl12.zip
  https://github.com/KhronosGroup/OpenCL-Headers/archive/opencl20.zip
  https://github.com/KhronosGroup/OpenCL-Headers/archive/opencl21.zip

  You can build your own ICD, as the sources are open (licence 7). 
  OpenCL version 2.1 is implemented, but it is fully backwards compatible to OpenCL 1.0. 
  You can assume that the vendors use this code for their own, 
  so you can safely use this code in your project.

  https://github.com/KhronosGroup/OpenCL-ICD-Loader

  opencl cts test
  https://github.com/KhronosGroup/OpenCL-CTS

  OpenCL-Registry
  https://github.com/KhronosGroup/OpenCL-Registry

  WebCL
  https://github.com/KhronosGroup/WebCL

*/

void *vgpu_server_opencl_lib;

int loadopencl() {

    char *err;

    /* khronos say load libOpenCL.so to get hold on lcd version */
    vgpu_server_opencl_lib = dlopen("libOpenCL.so", RTLD_NOW);
    
    if (!vgpu_server_opencl_lib) {
           return -1;
    }

// OpenCL 1.0 API

    funcint_clBuildProgram = (funcptr_clBuildProgram) dlsym ( vgpu_server_opencl_lib, "clBuildProgram" );    
    if ((err = dlerror()) != NULL) {
       funcint_clBuildProgram = 0;
    }

    funcint_clCreateBuffer = (funcptr_clCreateBuffer) dlsym ( vgpu_server_opencl_lib, "clCreateBuffer" );    
    if ((err = dlerror()) != NULL) {
       funcint_clCreateBuffer = 0;
    }

    funcint_clCreateCommandQueue = (funcptr_clCreateCommandQueue) dlsym ( vgpu_server_opencl_lib, "clCreateCommandQueue" );    
    if ((err = dlerror()) != NULL) {
       funcint_clCreateCommandQueue = 0;
    }

    funcint_clCreateContext = (funcptr_clCreateContext) dlsym ( vgpu_server_opencl_lib, "clCreateContext" );    
    if ((err = dlerror()) != NULL) {
       funcint_clCreateContext = 0;
    }

    funcint_clCreateContextFromType = (funcptr_clCreateContextFromType) dlsym ( vgpu_server_opencl_lib, "clCreateContextFromType" );    
    if ((err = dlerror()) != NULL) {
       funcint_clCreateContextFromType = 0;
    }

    funcint_clCreateFromGLBuffer = (funcptr_clCreateFromGLBuffer) dlsym ( vgpu_server_opencl_lib, "clCreateFromGLBuffer" );    
    if ((err = dlerror()) != NULL) {
       funcint_clCreateFromGLBuffer = 0;
    }

    funcint_clCreateFromGLRenderbuffer = (funcptr_clCreateFromGLRenderbuffer) dlsym ( vgpu_server_opencl_lib, "clCreateFromGLRenderbuffer" );    
    if ((err = dlerror()) != NULL) {
       funcint_clCreateFromGLRenderbuffer = 0;
    }

    funcint_clCreateFromGLTexture2D = (funcptr_clCreateFromGLTexture2D) dlsym ( vgpu_server_opencl_lib, "clCreateFromGLTexture2D" );    
    if ((err = dlerror()) != NULL) {
       funcint_clCreateFromGLTexture2D = 0;
    }

    funcint_clCreateFromGLTexture3D = (funcptr_clCreateFromGLTexture3D) dlsym ( vgpu_server_opencl_lib, "clCreateFromGLTexture3D" );    
    if ((err = dlerror()) != NULL) {
       funcint_clCreateFromGLTexture3D = 0;
    }

    funcint_clCreateImage2D = (funcptr_clCreateImage2D) dlsym ( vgpu_server_opencl_lib, "clCreateImage2D" );    
    if ((err = dlerror()) != NULL) {
       funcint_clCreateImage2D = 0;
    }

    funcint_clCreateImage3D = (funcptr_clCreateImage3D) dlsym ( vgpu_server_opencl_lib, "clCreateImage3D" );    
    if ((err = dlerror()) != NULL) {
       funcint_clCreateImage3D = 0;
    }

    funcint_clCreateKernel = (funcptr_clCreateKernel) dlsym ( vgpu_server_opencl_lib, "clCreateKernel" );    
    if ((err = dlerror()) != NULL) {
       funcint_clCreateKernel = 0;
    }

    funcint_clCreateKernelsInProgram = (funcptr_clCreateKernelsInProgram) dlsym ( vgpu_server_opencl_lib, "clCreateKernelsInProgram" );    
    if ((err = dlerror()) != NULL) {
       funcint_clCreateKernelsInProgram = 0;
    }

    funcint_clCreateProgramWithBinary = (funcptr_clCreateProgramWithBinary) dlsym ( vgpu_server_opencl_lib, "clCreateProgramWithBinary" );    
    if ((err = dlerror()) != NULL) {
       funcint_clCreateProgramWithBinary = 0;
    }

    funcint_clCreateProgramWithSource = (funcptr_clCreateProgramWithSource) dlsym ( vgpu_server_opencl_lib, "clCreateProgramWithSource" );    
    if ((err = dlerror()) != NULL) {
       funcint_clCreateProgramWithSource = 0;
    }

    funcint_clCreateSampler = (funcptr_clCreateSampler) dlsym ( vgpu_server_opencl_lib, "clCreateSampler" );    
    if ((err = dlerror()) != NULL) {
       funcint_clCreateSampler = 0;
    }

    funcint_clEnqueueAcquireGLObjects = (funcptr_clEnqueueAcquireGLObjects) dlsym ( vgpu_server_opencl_lib, "clEnqueueAcquireGLObjects" );    
    if ((err = dlerror()) != NULL) {
       funcint_clEnqueueAcquireGLObjects = 0;
    }

    funcint_clEnqueueBarrier = (funcptr_clEnqueueBarrier) dlsym ( vgpu_server_opencl_lib, "clEnqueueBarrier" );    
    if ((err = dlerror()) != NULL) {
       funcint_clEnqueueBarrier = 0;
    }

    funcint_clEnqueueCopyBuffer = (funcptr_clEnqueueCopyBuffer) dlsym ( vgpu_server_opencl_lib, "clEnqueueCopyBuffer" );    
    if ((err = dlerror()) != NULL) {
       funcint_clEnqueueCopyBuffer = 0;
    }

    funcint_clEnqueueCopyBufferToImage = (funcptr_clEnqueueCopyBufferToImage) dlsym ( vgpu_server_opencl_lib, "clEnqueueCopyBufferToImage" );    
    if ((err = dlerror()) != NULL) {
       funcint_clEnqueueCopyBufferToImage = 0;
    }

    funcint_clEnqueueCopyImage = (funcptr_clEnqueueCopyImage) dlsym ( vgpu_server_opencl_lib, "clEnqueueCopyImage" );    
    if ((err = dlerror()) != NULL) {
       funcint_clEnqueueCopyImage = 0;
    }

    funcint_clEnqueueCopyImageToBuffer = (funcptr_clEnqueueCopyImageToBuffer) dlsym ( vgpu_server_opencl_lib, "clEnqueueCopyImageToBuffer" );    
    if ((err = dlerror()) != NULL) {
       funcint_clEnqueueCopyImageToBuffer = 0;
    }

    funcint_clEnqueueMapImage = (funcptr_clEnqueueMapImage) dlsym ( vgpu_server_opencl_lib, "clEnqueueMapImage" );    
    if ((err = dlerror()) != NULL) {
       funcint_clEnqueueMapImage = 0;
    }

    funcint_clEnqueueMarker = (funcptr_clEnqueueMarker) dlsym ( vgpu_server_opencl_lib, "clEnqueueMarker" );    
    if ((err = dlerror()) != NULL) {
       funcint_clEnqueueMarker = 0;
    }

    funcint_clEnqueueNDRangeKernel = (funcptr_clEnqueueNDRangeKernel) dlsym ( vgpu_server_opencl_lib, "clEnqueueNDRangeKernel" );    
    if ((err = dlerror()) != NULL) {
       funcint_clEnqueueNDRangeKernel = 0;
    }

    funcint_clEnqueueNativeKernel = (funcptr_clEnqueueNativeKernel) dlsym ( vgpu_server_opencl_lib, "clEnqueueNativeKernel" );    
    if ((err = dlerror()) != NULL) {
       funcint_clEnqueueNativeKernel = 0;
    }

    funcint_clEnqueueReadBuffer = (funcptr_clEnqueueReadBuffer) dlsym ( vgpu_server_opencl_lib, "clEnqueueReadBuffer" );    
    if ((err = dlerror()) != NULL) {
       funcint_clEnqueueReadBuffer = 0;
    }

    funcint_clEnqueueReadImage = (funcptr_clEnqueueReadImage) dlsym ( vgpu_server_opencl_lib, "clEnqueueReadImage" );    
    if ((err = dlerror()) != NULL) {
       funcint_clEnqueueReadImage = 0;
    }

    funcint_clEnqueueReleaseGLObjects = (funcptr_clEnqueueReleaseGLObjects) dlsym ( vgpu_server_opencl_lib, "clEnqueueReleaseGLObjects" );    
    if ((err = dlerror()) != NULL) {
       funcint_clEnqueueReleaseGLObjects = 0;
    }

    funcint_clEnqueueTask = (funcptr_clEnqueueTask) dlsym ( vgpu_server_opencl_lib, "clEnqueueTask" );    
    if ((err = dlerror()) != NULL) {
       funcint_clEnqueueTask = 0;
    }

    funcint_clEnqueueUnmapMemObject = (funcptr_clEnqueueUnmapMemObject) dlsym ( vgpu_server_opencl_lib, "clEnqueueUnmapMemObject" );    
    if ((err = dlerror()) != NULL) {
       funcint_clEnqueueUnmapMemObject = 0;
    }

    funcint_clEnqueueWaitForEvents = (funcptr_clEnqueueWaitForEvents) dlsym ( vgpu_server_opencl_lib, "clEnqueueWaitForEvents" );    
    if ((err = dlerror()) != NULL) {
       funcint_clEnqueueWaitForEvents = 0;
    }

    funcint_clEnqueueWriteBuffer = (funcptr_clEnqueueWriteBuffer) dlsym ( vgpu_server_opencl_lib, "clEnqueueWriteBuffer" );    
    if ((err = dlerror()) != NULL) {
       funcint_clEnqueueWriteBuffer = 0;
    }

    funcint_clEnqueueWriteImage = (funcptr_clEnqueueWriteImage) dlsym ( vgpu_server_opencl_lib, "clEnqueueWriteImage" );    
    if ((err = dlerror()) != NULL) {
       funcint_clEnqueueWriteImage = 0;
    }

    funcint_clFinish = (funcptr_clFinish) dlsym ( vgpu_server_opencl_lib, "clFinish" );    
    if ((err = dlerror()) != NULL) {
       funcint_clFinish = 0;
    }

    funcint_clFlush = (funcptr_clFlush) dlsym ( vgpu_server_opencl_lib, "clFlush" );    
    if ((err = dlerror()) != NULL) {
       funcint_clFlush = 0;
    }

    funcint_clGetCommandQueueInfo = (funcptr_clGetCommandQueueInfo) dlsym ( vgpu_server_opencl_lib, "clGetCommandQueueInfo" );    
    if ((err = dlerror()) != NULL) {
       funcint_clGetCommandQueueInfo = 0;
    }

    funcint_clGetContextInfo = (funcptr_clGetContextInfo) dlsym ( vgpu_server_opencl_lib, "clGetContextInfo" );    
    if ((err = dlerror()) != NULL) {
       funcint_clGetContextInfo = 0;
    }

    funcint_clGetDeviceIDs = (funcptr_clGetDeviceIDs) dlsym ( vgpu_server_opencl_lib, "clGetDeviceIDs" );    
    if ((err = dlerror()) != NULL) {
       funcint_clGetDeviceIDs = 0;
    }

    funcint_clGetDeviceInfo = (funcptr_clGetDeviceInfo) dlsym ( vgpu_server_opencl_lib, "clGetDeviceInfo" );    
    if ((err = dlerror()) != NULL) {
       funcint_clGetDeviceInfo = 0;
    }

    funcint_clGetEventInfo = (funcptr_clGetEventInfo) dlsym ( vgpu_server_opencl_lib, "clGetEventInfo" );    
    if ((err = dlerror()) != NULL) {
       funcint_clGetEventInfo = 0;
    }

    funcint_clGetEventProfilingInfo = (funcptr_clGetEventProfilingInfo) dlsym ( vgpu_server_opencl_lib, "clGetEventProfilingInfo" );    
    if ((err = dlerror()) != NULL) {
       funcint_clGetEventProfilingInfo = 0;
    }

    funcint_clGetExtensionFunctionAddress = (funcptr_clGetExtensionFunctionAddress) dlsym ( vgpu_server_opencl_lib, "clGetExtensionFunctionAddress" );    
    if ((err = dlerror()) != NULL) {
       funcint_clGetExtensionFunctionAddress = 0;
    }

    funcint_clGetGLObjectInfo = (funcptr_clGetGLObjectInfo) dlsym ( vgpu_server_opencl_lib, "clGetGLObjectInfo" );    
    if ((err = dlerror()) != NULL) {
       funcint_clGetGLObjectInfo = 0;
    }

    funcint_clGetGLTextureInfo = (funcptr_clGetGLTextureInfo) dlsym ( vgpu_server_opencl_lib, "clGetGLTextureInfo" );    
    if ((err = dlerror()) != NULL) {
       funcint_clGetGLTextureInfo = 0;
    }

    funcint_clGetImageInfo = (funcptr_clGetImageInfo) dlsym ( vgpu_server_opencl_lib, "clGetImageInfo" );    
    if ((err = dlerror()) != NULL) {
       funcint_clGetImageInfo = 0;
    }

    funcint_clGetKernelInfo = (funcptr_clGetKernelInfo) dlsym ( vgpu_server_opencl_lib, "clGetKernelInfo" );    
    if ((err = dlerror()) != NULL) {
       funcint_clGetKernelInfo = 0;
    }

    funcint_clGetKernelWorkGroupInfo = (funcptr_clGetKernelWorkGroupInfo) dlsym ( vgpu_server_opencl_lib, "clGetKernelWorkGroupInfo" );    
    if ((err = dlerror()) != NULL) {
       funcint_clGetKernelWorkGroupInfo = 0;
    }

    funcint_clGetMemObjectInfo = (funcptr_clGetMemObjectInfo) dlsym ( vgpu_server_opencl_lib, "clGetMemObjectInfo" );    
    if ((err = dlerror()) != NULL) {
       funcint_clGetMemObjectInfo = 0;
    }

    funcint_clGetPlatformIDs = (funcptr_clGetPlatformIDs) dlsym ( vgpu_server_opencl_lib, "clGetPlatformIDs" );    
    if ((err = dlerror()) != NULL) {
       funcint_clGetPlatformIDs = 0;
    }

    funcint_clGetPlatformInfo = (funcptr_clGetPlatformInfo) dlsym ( vgpu_server_opencl_lib, "clGetPlatformInfo" );    
    if ((err = dlerror()) != NULL) {
       funcint_clGetPlatformInfo = 0;
    }

    funcint_clGetProgramBuildInfo = (funcptr_clGetProgramBuildInfo) dlsym ( vgpu_server_opencl_lib, "clGetProgramBuildInfo" );    
    if ((err = dlerror()) != NULL) {
       funcint_clGetProgramBuildInfo = 0;
    }

    funcint_clGetProgramInfo = (funcptr_clGetProgramInfo) dlsym ( vgpu_server_opencl_lib, "clGetProgramInfo" );    
    if ((err = dlerror()) != NULL) {
       funcint_clGetProgramInfo = 0;
    }

    funcint_clGetSamplerInfo = (funcptr_clGetSamplerInfo) dlsym ( vgpu_server_opencl_lib, "clGetSamplerInfo" );    
    if ((err = dlerror()) != NULL) {
       funcint_clGetSamplerInfo = 0;
    }

    funcint_clGetSupportedImageFormats = (funcptr_clGetSupportedImageFormats) dlsym ( vgpu_server_opencl_lib, "clGetSupportedImageFormats" );    
    if ((err = dlerror()) != NULL) {
       funcint_clGetSupportedImageFormats = 0;
    }

    funcint_clReleaseCommandQueue = (funcptr_clReleaseCommandQueue) dlsym ( vgpu_server_opencl_lib, "clReleaseCommandQueue" );    
    if ((err = dlerror()) != NULL) {
       funcint_clReleaseCommandQueue = 0;
    }

    funcint_clReleaseContext = (funcptr_clReleaseContext) dlsym ( vgpu_server_opencl_lib, "clReleaseContext" );    
    if ((err = dlerror()) != NULL) {
       funcint_clReleaseContext = 0;
    }

    funcint_clReleaseEvent = (funcptr_clReleaseEvent) dlsym ( vgpu_server_opencl_lib, "clReleaseEvent" );    
    if ((err = dlerror()) != NULL) {
       funcint_clReleaseEvent = 0;
    }

    funcint_clReleaseKernel = (funcptr_clReleaseKernel) dlsym ( vgpu_server_opencl_lib, "clReleaseKernel" );    
    if ((err = dlerror()) != NULL) {
       funcint_clReleaseKernel = 0;
    }

    funcint_clReleaseMemObject = (funcptr_clReleaseMemObject) dlsym ( vgpu_server_opencl_lib, "clReleaseMemObject" );    
    if ((err = dlerror()) != NULL) {
       funcint_clReleaseMemObject = 0;
    }

    funcint_clReleaseProgram = (funcptr_clReleaseProgram) dlsym ( vgpu_server_opencl_lib, "clReleaseProgram" );    
    if ((err = dlerror()) != NULL) {
       funcint_clReleaseProgram = 0;
    }

    funcint_clReleaseSampler = (funcptr_clReleaseSampler) dlsym ( vgpu_server_opencl_lib, "clReleaseSampler" );    
    if ((err = dlerror()) != NULL) {
       funcint_clReleaseSampler = 0;
    }

    funcint_clRetainCommandQueue = (funcptr_clRetainCommandQueue) dlsym ( vgpu_server_opencl_lib, "clRetainCommandQueue" );    
    if ((err = dlerror()) != NULL) {
       funcint_clRetainCommandQueue = 0;
    }

    funcint_clRetainContext = (funcptr_clRetainContext) dlsym ( vgpu_server_opencl_lib, "clRetainContext" );    
    if ((err = dlerror()) != NULL) {
       funcint_clRetainContext = 0;
    }

    funcint_clRetainEvent = (funcptr_clRetainEvent) dlsym ( vgpu_server_opencl_lib, "clRetainEvent" );    
    if ((err = dlerror()) != NULL) {
       funcint_clRetainEvent = 0;
    }

    funcint_clRetainKernel = (funcptr_clRetainKernel) dlsym ( vgpu_server_opencl_lib, "clRetainKernel" );    
    if ((err = dlerror()) != NULL) {
       funcint_clRetainKernel = 0;
    }

    funcint_clRetainMemObject = (funcptr_clRetainMemObject) dlsym ( vgpu_server_opencl_lib, "clRetainMemObject" );    
    if ((err = dlerror()) != NULL) {
       funcint_clRetainMemObject = 0;
    }

    funcint_clRetainProgram = (funcptr_clRetainProgram) dlsym ( vgpu_server_opencl_lib, "clRetainProgram" );    
    if ((err = dlerror()) != NULL) {
       funcint_clRetainProgram = 0;
    }

    funcint_clRetainSampler = (funcptr_clRetainSampler) dlsym ( vgpu_server_opencl_lib, "clRetainSampler" );    
    if ((err = dlerror()) != NULL) {
       funcint_clRetainSampler = 0;
    }

    funcint_clSetCommandQueueProperty = (funcptr_clSetCommandQueueProperty) dlsym ( vgpu_server_opencl_lib, "clSetCommandQueueProperty" );    
    if ((err = dlerror()) != NULL) {
       funcint_clSetCommandQueueProperty = 0;
    }

    funcint_clSetKernelArg = (funcptr_clSetKernelArg) dlsym ( vgpu_server_opencl_lib, "clSetKernelArg" );    
    if ((err = dlerror()) != NULL) {
       funcint_clSetKernelArg = 0;
    }

    funcint_clUnloadCompiler = (funcptr_clUnloadCompiler) dlsym ( vgpu_server_opencl_lib, "clUnloadCompiler" );    
    if ((err = dlerror()) != NULL) {
       funcint_clUnloadCompiler = 0;
    }

    funcint_clWaitForEvents = (funcptr_clWaitForEvents) dlsym ( vgpu_server_opencl_lib, "clWaitForEvents" );    
    if ((err = dlerror()) != NULL) {
       funcint_clWaitForEvents = 0;
    }        

}

void closeopencl() {
    dlclose(vgpu_server_opencl_lib);
}

typedef struct VGPU_CLPROGRAM VGPU_CLPROGRAM;
struct VGPU_CLPROGRAM {
   cl_program client_clprogram;
   cl_program server_clprogram; 
   VGPU_CLPROGRAM * next;
   VGPU_CLPROGRAM * prev;
};


cl_int runVgpu_clBuildProgram (cl_program program,
                cl_uint              num_devices,
                const cl_device_id * device_list,
                const char *         options,
                void (CL_CALLBACK *  pfn_notify)(cl_program program, void * user_data),
                void * user_data) {

    
    if ( user_data != NULL ) {
        printf("clBuildProgram : not supported pfn notify");
    }

    return funcint_clBuildProgram ( program, num_devices, device_list, options, NULL, NULL);

    //return cllib_clBuildProgram ( program, num_devices, device_list, options, program, user_data);
}

void runVgpu_clCreateBuffer() {

}

void runVgpu_clCreateCommandQueue() {

}

void runVgpu_clCreateContext() {

}

void runVgpu_clCreateContextFromType() {

}

void runVgpu_clCreateFromGLBuffer() {

}

void runVgpu_clCreateFromGLRenderbuffer() {

}

void runVgpu_clCreateFromGLTexture2D() {

}

void runVgpu_clCreateFromGLTexture3D() {

}

void runVgpu_clCreateImage2D() {

}


void runVgpu_clCreateImage3D() {

}


void runVgpu_clCreateKernel() {

}

void runVgpu_clCreateKernelsInProgram() {

}

void runVgpu_clCreateProgramWithBinary() {

}

void runVgpu_clCreateProgramWithSource() {

}

void runVgpu_clCreateSampler() {

}


void runVgpu_clEnqueueAcquireGLObjects() {

}

void runVgpu_clEnqueueBarrier() {

}

void runVgpu_clEnqueueCopyBuffer() {

}

void runVgpu_clEnqueueCopyBufferToImage() {

}

void runVgpu_clEnqueueCopyImage() {

}

void runVgpu_clEnqueueCopyImageToBuffer() {

}

void runVgpu_clEnqueueMapBuffer() {

}

void runVgpu_clEnqueueMapImage() {

}

void runVgpu_clEnqueueMarker() {

}

void runVgpu_clEnqueueNDRangeKernel() {

}

void runVgpu_clEnqueueNativeKernel() {

}

void runVgpu_clEnqueueReadBuffer() {

}

void runVgpu_clEnqueueReadImage() {

}

void runVgpu_clEnqueueReleaseGLObjects() {

}

void runVgpu_clEnqueueTask() {

}

void runVgpu_clEnqueueUnmapMemObject() {

}

void runVgpu_clEnqueueWaitForEvents() {

}

void runVgpu_clEnqueueWriteBuffer() {

}

void runVgpu_clEnqueueWriteImage() {

}

void runVgpu_clFinish() {

}

void runVgpu_clFlush() {

}

void runVgpu_clGetCommandQueueInfo() {

}

void runVgpu_clGetContextInfo() {

}

void runVgpu_clGetDeviceIDs() {

}

void runVgpu_clGetDeviceInfo() {

}

void runVgpu_clGetEventInfo() {

}

void runVgpu_clGetEventProfilingInfo() {

}

void runVgpu_clGetExtensionFunctionAddress() {

}

void runVgpu_clGetGLObjectInfo() {

}

void runVgpu_clGetGLTextureInfo() {

}

void runVgpu_clGetImageInfo() {

}

void runVgpu_clGetKernelInfo() {

}

void runVgpu_clGetKernelWorkGroupInfo() {

}

void runVgpu_clGetMemObjectInfo() {

}


cl_int runVgpu_clGetPlatformIDs(    cl_uint num_entries,
                                    cl_platform_id * platforms,
                                    cl_uint *        num_platforms) {

    return -1;

}


void runVgpu_clGetPlatformInfo() {

}

void runVgpu_clGetProgramBuildInfo() {

}

void runVgpu_clGetProgramInfo() {

}

void runVgpu_clGetSamplerInfo() {

}


void runVgpu_clGetSupportedImageFormats() {

}

void runVgpu_clReleaseCommandQueue() {

}

void runVgpu_clReleaseContext() {

}


void runVgpu_clReleaseMemObject() {

}

void runVgpu_clReleaseProgram() {

}

void runVgpu_clReleaseSampler() {

}

void runVgpu_clRetainCommandQueue() {

}

void runVgpu_clRetainContext() {

}

void runVgpu_clRetainEvent() {

}

void runVgpu_clRetainKernel() {

}

void runVgpu_clRetainMemObject() {

}

void runVgpu_clRetainProgram() {

}

void runVgpu_clRetainSampler() {

}

void runVgpu_clSetCommandQueueProperty() {

}

void runVgpu_clSetKernelArg() {

}

void runVgpu_clUnloadCompiler() {

}

void runVgpu_clWaitForEvents() {

}

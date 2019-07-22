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

    cllib_clBuildProgram = dlsym(vgpu_server_opencl_lib,"clBuildProgram");    
    if ((err = dlerror()) != NULL) {
       cllib_clBuildProgram = 0;
    }




    /*
     clBuildProgram;
        clCreateBuffer;
        clCreateCommandQueue;
        clCreateContext;
        clCreateContextFromType;
        clCreateFromGLBuffer;
        clCreateFromGLRenderbuffer;
        clCreateFromGLTexture2D;
        clCreateFromGLTexture3D;
        clCreateImage2D;
        clCreateImage3D;
        clCreateKernel;
        clCreateKernelsInProgram;
        clCreateProgramWithBinary;
        clCreateProgramWithSource;
        clCreateSampler;
        clEnqueueAcquireGLObjects;
        clEnqueueBarrier;
        clEnqueueCopyBuffer;
        clEnqueueCopyBufferToImage;
        clEnqueueCopyImage;
        clEnqueueCopyImageToBuffer;
        clEnqueueMapBuffer;
        clEnqueueMapImage;
        clEnqueueMarker;
        clEnqueueNDRangeKernel;
        clEnqueueNativeKernel;
        clEnqueueReadBuffer;
        clEnqueueReadImage;
        clEnqueueReleaseGLObjects;
        clEnqueueTask;
        clEnqueueUnmapMemObject;
        clEnqueueWaitForEvents;
        clEnqueueWriteBuffer;
        clEnqueueWriteImage;
        clFinish;
        clFlush;
        clGetCommandQueueInfo;
        clGetContextInfo;
        clGetDeviceIDs;
        clGetDeviceInfo;
        clGetEventInfo;
        clGetEventProfilingInfo;
        clGetExtensionFunctionAddress;
        clGetGLObjectInfo;
        clGetGLTextureInfo;
        clGetImageInfo;
        clGetKernelInfo;
        clGetKernelWorkGroupInfo;
        clGetMemObjectInfo;
        clGetPlatformIDs;
        clGetPlatformInfo;
        clGetProgramBuildInfo;
        clGetProgramInfo;
        clGetSamplerInfo;
        clGetSupportedImageFormats;
        clReleaseCommandQueue;
        clReleaseContext;
        clReleaseEvent;
        clReleaseKernel;
        clReleaseMemObject;
        clReleaseProgram;
        clReleaseSampler;
        clRetainCommandQueue;
        clRetainContext;
        clRetainEvent;
        clRetainKernel;
        clRetainMemObject;
        clRetainProgram;
        clRetainSampler;
        clSetCommandQueueProperty;
        clSetKernelArg;
        clUnloadCompiler;
        clWaitForEvents;
        */
        
        
        

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

    return cllib_clBuildProgram ( program, num_devices, device_list, options, NULL, NULL);

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

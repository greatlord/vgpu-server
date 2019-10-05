

// CMD commands
// OpenCL 1.0 API
    #define VGPU_CMD_TYPE_CL    0x100
    
    #define VGPU_CMD_CLBUILDPROGRAM                             VGPU_CMD_TYPE_CL | 0
    #define VGPU_CMD_CLCREATEBUFFER                             VGPU_CMD_TYPE_CL | 1
    #define VGPU_CMD_CLCREATECOMMANDQUEUE                       VGPU_CMD_TYPE_CL | 3
    #define VGPU_CMD_CLCREATECONTEXT                            VGPU_CMD_TYPE_CL | 4
    #define VGPU_CMD_CLCREATECONTEXTFROMTYPE                    VGPU_CMD_TYPE_CL | 5
    #define VGPU_CMD_CLCREATEFROMGLBUFFER                       VGPU_CMD_TYPE_CL | 6
    #define VGPU_CMD_CLCREATEFROMGLRENDERBUFFER                 VGPU_CMD_TYPE_CL | 7
    #define VGPU_CMD_CLCREATEFROMGLTEXTURE2D                    VGPU_CMD_TYPE_CL | 8
    #define VGPU_CMD_CLCREATEFROMGLTEXTURE3D                    VGPU_CMD_TYPE_CL | 9
    #define VGPU_CMD_CLCREATEIMAGE2D                            VGPU_CMD_TYPE_CL | 10
    #define VGPU_CMD_CLCREATEIMAGE3D                            VGPU_CMD_TYPE_CL | 11
    #define VGPU_CMD_CLCREATEKERNEL                             VGPU_CMD_TYPE_CL | 12
    #define VGPU_CMD_CLCREATEKERNELSINPROGRAM                   VGPU_CMD_TYPE_CL | 13
    #define VGPU_CMD_CLCREATEPROGRAMWITHBINARY                  VGPU_CMD_TYPE_CL | 14
    #define VGPU_CMD_CLCREATEPROGRAMWITHSOURCE                  VGPU_CMD_TYPE_CL | 15
    #define VGPU_CMD_CLCREATESAMPLER                            VGPU_CMD_TYPE_CL | 16 
    #define VGPU_CMD_CLENQUEUEACQUIREGLOBJECTS                  VGPU_CMD_TYPE_CL | 17
    #define VGPU_CMD_CLENQUEUEBARRIER                           VGPU_CMD_TYPE_CL | 18
    #define VGPU_CMD_CLENQUEUECOPYBUFFER                        VGPU_CMD_TYPE_CL | 19
    #define VGPU_CMD_CLENQUEUECOPYBUFFERTOIMAGE                 VGPU_CMD_TYPE_CL | 20
    #define VGPU_CMD_CLENQUEUECOPYIMAGE                         VGPU_CMD_TYPE_CL | 21
    #define VGPU_CMD_CLENQUEUECOPYIMAGETOBUFFER                 VGPU_CMD_TYPE_CL | 22
    #define VGPU_CMD_CLENQUEUEMAPBUFFER                         VGPU_CMD_TYPE_CL | 23
    #define VGPU_CMD_CLENQUEUEMAPIMAGE                          VGPU_CMD_TYPE_CL | 24
    #define VGPU_CMD_CLENQUEUEMARKER                            VGPU_CMD_TYPE_CL | 25
    #define VGPU_CMD_CLENQUEUENDRANGEKERNEL                     VGPU_CMD_TYPE_CL | 26
    #define VGPU_CMD_CLENQUEUENATIVEKERNEL                      VGPU_CMD_TYPE_CL | 27
    #define VGPU_CMD_CLENQUEUEREADBUFFER                        VGPU_CMD_TYPE_CL | 28
    #define VGPU_CMD_CLENQUEUEREADIMAGE                         VGPU_CMD_TYPE_CL | 29
    #define VGPU_CMD_CLENQUEUERELEASEGLOBJECTS                  VGPU_CMD_TYPE_CL | 30
    #define VGPU_CMD_CLENQUEUETASK                              VGPU_CMD_TYPE_CL | 31
    #define VGPU_CMD_CLENQUEUEUNMAPMEMOBJECT                    VGPU_CMD_TYPE_CL | 32
    #define VGPU_CMD_CLENQUEUEWAITFOREVENTS                     VGPU_CMD_TYPE_CL | 33
    #define VGPU_CMD_CLENQUEUEWRITEBUFFER                       VGPU_CMD_TYPE_CL | 34
    #define VGPU_CMD_CLENQUEUEWRITEIMAGE                        VGPU_CMD_TYPE_CL | 35
    #define VGPU_CMD_CLFINISH                                   VGPU_CMD_TYPE_CL | 36
    #define VGPU_CMD_CLFLUSH                                    VGPU_CMD_TYPE_CL | 37
    #define VGPU_CMD_CLGETCOMMANDQUEUEINFO                      VGPU_CMD_TYPE_CL | 38
    #define VGPU_CMD_CLGETCONTEXTINFO                           VGPU_CMD_TYPE_CL | 39
    #define VGPU_CMD_CLGETDEVICEIDS                             VGPU_CMD_TYPE_CL | 40
    #define VGPU_CMD_CLGETDEVICEINFO                            VGPU_CMD_TYPE_CL | 41
    #define VGPU_CMD_CLGETEVENTINFO                             VGPU_CMD_TYPE_CL | 42
    #define VGPU_CMD_CLGETEVENTPROFILINGINFO                    VGPU_CMD_TYPE_CL | 43
    #define VGPU_CMD_CLGETEXTENSIONFUNCTIONADDRESS              VGPU_CMD_TYPE_CL | 44
    #define VGPU_CMD_CLGETGLOBJECTINFO                          VGPU_CMD_TYPE_CL | 45
    #define VGPU_CMD_CLGETGLTEXTUREINFO                         VGPU_CMD_TYPE_CL | 46
    #define VGPU_CMD_CLGETIMAGEINFO                             VGPU_CMD_TYPE_CL | 47
    #define VGPU_CMD_CLGETKERNELINFO                            VGPU_CMD_TYPE_CL | 48
    #define VGPU_CMD_CLGETKERNELWORKGROUPINFO                   VGPU_CMD_TYPE_CL | 49
    #define VGPU_CMD_CLGETMEMOBJECTINFO                         VGPU_CMD_TYPE_CL | 50
    #define VGPU_CMD_CLGETPLATFORMIDS                           VGPU_CMD_TYPE_CL | 51
    #define VGPU_CMD_CLGETPLATFORMINFO                          VGPU_CMD_TYPE_CL | 52
    #define VGPU_CMD_CLGETPROGRAMBUILDINFO                      VGPU_CMD_TYPE_CL | 53
    #define VGPU_CMD_CLGETPROGRAMINFO                           VGPU_CMD_TYPE_CL | 54
    #define VGPU_CMD_CLGETSAMPLERINFO                           VGPU_CMD_TYPE_CL | 55
    #define VGPU_CMD_CLGETSUPPORTEDIMAGEFORMATS                 VGPU_CMD_TYPE_CL | 56
    #define VGPU_CMD_CLRELEASECOMMANDQUEUE                      VGPU_CMD_TYPE_CL | 57
    #define VGPU_CMD_CLRELEASECONTEXT                           VGPU_CMD_TYPE_CL | 58
    #define VGPU_CMD_CLRELEASEEVENT                             VGPU_CMD_TYPE_CL | 59
    #define VGPU_CMD_CLRELEASEKERNEL                            VGPU_CMD_TYPE_CL | 60
    #define VGPU_CMD_CLRELEASEMEMOBJECT                         VGPU_CMD_TYPE_CL | 61
    #define VGPU_CMD_CLRELEASEPROGRAM                           VGPU_CMD_TYPE_CL | 62
    #define VGPU_CMD_CLRELEASESAMPLER                           VGPU_CMD_TYPE_CL | 63
    #define VGPU_CMD_CLRETAINCOMMANDQUEUE                       VGPU_CMD_TYPE_CL | 64
    #define VGPU_CMD_CLRETAINCONTEXT                            VGPU_CMD_TYPE_CL | 65
    #define VGPU_CMD_CLRETAINEVENT                              VGPU_CMD_TYPE_CL | 66
    #define VGPU_CMD_CLRETAINKERNEL                             VGPU_CMD_TYPE_CL | 67
    #define VGPU_CMD_CLRETAINMEMOBJECT                          VGPU_CMD_TYPE_CL | 68
    #define VGPU_CMD_CLRETAINPROGRAM                            VGPU_CMD_TYPE_CL | 69
    #define VGPU_CMD_CLRETAINSAMPLER                            VGPU_CMD_TYPE_CL | 70
    #define VGPU_CMD_CLSETCOMMANDQUEUEPROPERTY                  VGPU_CMD_TYPE_CL | 71
    #define VGPU_CMD_CLSETKERNELARG                             VGPU_CMD_TYPE_CL | 72
    #define VGPU_CMD_CLUNLOADCOMPILER                           VGPU_CMD_TYPE_CL | 73
    #define VGPU_CMD_CLWAITFOREVENTS                            VGPU_CMD_TYPE_CL | 74

// OpenCL 1.1 API
    #define VGPU_CMD_CLCREATESUBBUFFER                           VGPU_CMD_TYPE_CL | 75
    #define VGPU_CMD_CLCREATEUSEREVENT                           VGPU_CMD_TYPE_CL | 76
    #define VGPU_CMD_CLENQUEUECOPYBUFFERRECT                     VGPU_CMD_TYPE_CL | 77
    #define VGPU_CMD_CLENQUEUEREADBUFFERRECT                     VGPU_CMD_TYPE_CL | 78
    #define VGPU_CMD_CLENQUEUEWRITEBUFFERRECT                    VGPU_CMD_TYPE_CL | 79
    #define VGPU_CMD_CLSETEVENTCALLBACK                          VGPU_CMD_TYPE_CL | 80
    #define VGPU_CMD_CLSETMEMOBJECTDESTRUCTORCALLBACK            VGPU_CMD_TYPE_CL | 81
    #define VGPU_CMD_CLSETUSEREVENTSTATUS                        VGPU_CMD_TYPE_CL | 82

// OpenCL 1.2 API
    #define VGPU_CMD_CLCOMPILEPROGRAM                            VGPU_CMD_TYPE_CL | 83
    #define VGPU_CMD_CLCREATEFROMGLTEXTURE                       VGPU_CMD_TYPE_CL | 84
    #define VGPU_CMD_CLCREATEIMAGE                               VGPU_CMD_TYPE_CL | 85
    #define VGPU_CMD_CLCREATEPROGRAMWITHBUILTINKERNELS           VGPU_CMD_TYPE_CL | 86
    #define VGPU_CMD_CLCREATESUBDEVICES                          VGPU_CMD_TYPE_CL | 87
    #define VGPU_CMD_CLENQUEUEBARRIERWITHWAITLIST                VGPU_CMD_TYPE_CL | 88
    #define VGPU_CMD_CLENQUEUEFILLBUFFER                         VGPU_CMD_TYPE_CL | 89
    #define VGPU_CMD_CLENQUEUEFILLIMAGE                          VGPU_CMD_TYPE_CL | 90
    #define VGPU_CMD_CLENQUEUEMARKERWITHWAITLIST                 VGPU_CMD_TYPE_CL | 91
    #define VGPU_CMD_CLENQUEUEMIGRATEMEMOBJECTS                  VGPU_CMD_TYPE_CL | 92
    #define VGPU_CMD_CLGETEXTENSIONFUNCTIONADDRESSFORPLATFORM    VGPU_CMD_TYPE_CL | 93
    #define VGPU_CMD_CLGETKERNELARGINFO                          VGPU_CMD_TYPE_CL | 94
    #define VGPU_CMD_CLLINKPROGRAM                               VGPU_CMD_TYPE_CL | 95
    #define VGPU_CMD_CLRELEASEDEVICE                             VGPU_CMD_TYPE_CL | 96
    #define VGPU_CMD_CLRETAINDEVICE                              VGPU_CMD_TYPE_CL | 97
    #define VGPU_CMD_CLUNLOADPLATFORMCOMPILER                    VGPU_CMD_TYPE_CL | 98

// OpenCL 2.0 API
    #define VGPU_CMD_CLCREATECOMMANDQUEUEWITHPROPERTIES          VGPU_CMD_TYPE_CL | 99
    #define VGPU_CMD_CLCREATEPIPE                                VGPU_CMD_TYPE_CL | 100
    #define VGPU_CMD_CLCREATESAMPLERWITHPROPERTIES               VGPU_CMD_TYPE_CL | 101
    #define VGPU_CMD_CLENQUEUESVMFREE                            VGPU_CMD_TYPE_CL | 102
    #define VGPU_CMD_CLENQUEUESVMMAP                             VGPU_CMD_TYPE_CL | 103
    #define VGPU_CMD_CLENQUEUESVMMEMCPY                          VGPU_CMD_TYPE_CL | 104
    #define VGPU_CMD_CLENQUEUESVMMEMFILL                         VGPU_CMD_TYPE_CL | 105
    #define VGPU_CMD_CLENQUEUESVMUNMAP                           VGPU_CMD_TYPE_CL | 106
    #define VGPU_CMD_CLGETPIPEINFO                               VGPU_CMD_TYPE_CL | 107
    #define VGPU_CMD_CLSETKERNELARGSVMPOINTER                    VGPU_CMD_TYPE_CL | 108
    #define VGPU_CMD_CLSETKERNELEXECINFO                         VGPU_CMD_TYPE_CL | 109
    #define VGPU_CMD_CLSVMALLOC                                  VGPU_CMD_TYPE_CL | 110
    #define VGPU_CMD_CLSVMFREE                                   VGPU_CMD_TYPE_CL | 111

// OpenCL 2.1 API
    #define VGPU_CMD_CLCLONEKERNEL                               VGPU_CMD_TYPE_CL | 112
    #define VGPU_CMD_CLCREATEPROGRAMWITHIL                       VGPU_CMD_TYPE_CL | 113
    #define VGPU_CMD_CLENQUEUESVMMIGRATEMEM                      VGPU_CMD_TYPE_CL | 114
    #define VGPU_CMD_CLGETDEVICEANDHOSTTIMER                     VGPU_CMD_TYPE_CL | 115
    #define VGPU_CMD_CLGETHOSTTIMER                              VGPU_CMD_TYPE_CL | 116
    #define VGPU_CMD_CLGETKERNELSUBGROUPINFO                     VGPU_CMD_TYPE_CL | 117
    #define VGPU_CMD_CLSETDEFAULTDEVICECOMMANDQUEUE              VGPU_CMD_TYPE_CL | 118

// OpenCL 2.2 API
    #define VGPU_CMD_CLSETPROGRAMRELEASECALLBACK                 VGPU_CMD_TYPE_CL | 119
    #define VGPU_CMD_CLSETPROGRAMSPECIALIZATIONCONSTANT          VGPU_CMD_TYPE_CL | 120


// Protoypes 
void readVgpu_clBuildProgram (dyad_Stream *stream, const void *data, int size);
void readVgpu_clCreateBuffer(dyad_Stream *stream, const void *data, int size);
void readVgpu_clCreateCommandQueue(dyad_Stream *stream, const void *data, int size);
void readVgpu_clCreateContext(dyad_Stream *stream, const void *data, int size);
void readVgpu_clCreateContextFromType(dyad_Stream *stream, const void *data, int size);
void readVgpu_clCreateFromGLBuffer(dyad_Stream *stream, const void *data, int size);
void readVgpu_clCreateFromGLRenderbuffer(dyad_Stream *stream, const void *data, int size);
void readVgpu_clCreateFromGLTexture2D(dyad_Stream *stream, const void *data, int size);
void readVgpu_clCreateFromGLTexture3D(dyad_Stream *stream, const void *data, int size);
void readVgpu_clCreateImage2D(dyad_Stream *stream, const void *data, int size);
void readVgpu_clCreateImage3D(dyad_Stream *stream, const void *data, int size);
void readVgpu_clCreateKernel(dyad_Stream *stream, const void *data, int size);
void readVgpu_clCreateKernelsInProgram(dyad_Stream *stream, const void *data, int size);
void readVgpu_clCreateProgramWithBinary(dyad_Stream *stream, const void *data, int size);
void readVgpu_clCreateProgramWithSource(dyad_Stream *stream, const void *data, int size);
void readVgpu_clCreateSampler(dyad_Stream *stream, const void *data, int size);
void readVgpu_clEnqueueAcquireGLObjects(dyad_Stream *stream, const void *data, int size);
void readVgpu_clEnqueueBarrier(dyad_Stream *stream, const void *data, int size);
void readVgpu_clEnqueueCopyBuffer(dyad_Stream *stream, const void *data, int size);
void readVgpu_clEnqueueCopyBufferToImage(dyad_Stream *stream, const void *data, int size);
void readVgpu_clEnqueueCopyImage(dyad_Stream *stream, const void *data, int size);
void readVgpu_clEnqueueCopyImageToBuffer(dyad_Stream *stream, const void *data, int size);
void readVgpu_clEnqueueMapBuffer(dyad_Stream *stream, const void *data, int size);
void readVgpu_clEnqueueMapImage(dyad_Stream *stream, const void *data, int size);
void readVgpu_clEnqueueMarker(dyad_Stream *stream, const void *data, int size);
void readVgpu_clEnqueueNDRangeKernel(dyad_Stream *stream, const void *data, int size);
void readVgpu_clEnqueueNativeKernel(dyad_Stream *stream, const void *data, int size);
void readVgpu_clEnqueueReadBuffer(dyad_Stream *stream, const void *data, int size);
void readVgpu_clEnqueueReadImage(dyad_Stream *stream, const void *data, int size);
void readVgpu_clEnqueueReleaseGLObjects(dyad_Stream *stream, const void *data, int size);
void readVgpu_clEnqueueTask(dyad_Stream *stream, const void *data, int size);
void readVgpu_clEnqueueUnmapMemObject(dyad_Stream *stream, const void *data, int size);
void readVgpu_clEnqueueWaitForEvents(dyad_Stream *stream, const void *data, int size);
void readVgpu_clEnqueueWriteBuffer(dyad_Stream *stream, const void *data, int size);
void readVgpu_clEnqueueWriteImage(dyad_Stream *stream, const void *data, int size);
void readVgpu_clFinish(dyad_Stream *stream, const void *data, int size);
void readVgpu_clFlush(dyad_Stream *stream, const void *data, int size);
void readVgpu_clGetCommandQueueInfo(dyad_Stream *stream, const void *data, int size);
void readVgpu_clGetContextInfo(dyad_Stream *stream, const void *data, int size);
void readVgpu_clGetDeviceIDs(dyad_Stream *stream, const void *data, int size);
void readVgpu_clGetDeviceInfo(dyad_Stream *stream, const void *data, int size);
void readVgpu_clGetEventInfo(dyad_Stream *stream, const void *data, int size);
void readVgpu_clGetEventProfilingInfo(dyad_Stream *stream, const void *data, int size);
void readVgpu_clGetExtensionFunctionAddress(dyad_Stream *stream, const void *data, int size);
void readVgpu_clGetGLObjectInfo(dyad_Stream *stream, const void *data, int size);
void readVgpu_clGetGLTextureInfo(dyad_Stream *stream, const void *data, int size);
void readVgpu_clGetImageInfo(dyad_Stream *stream, const void *data, int size);
void readVgpu_clGetKernelInfo(dyad_Stream *stream, const void *data, int size);
void readVgpu_clGetKernelWorkGroupInfo(dyad_Stream *stream, const void *data, int size);
void readVgpu_clGetMemObjectInfo(dyad_Stream *stream, const void *data, int size);
void readVgpu_clGetPlatformIDs(dyad_Stream *stream, const void *data, int size);
void readVgpu_clGetPlatformInfo(dyad_Stream *stream, const void *data, int size);
void readVgpu_clGetProgramBuildInfo(dyad_Stream *stream, const void *data, int size);
void readVgpu_clGetSamplerInfo(dyad_Stream *stream, const void *data, int size);
void readVgpu_clGetSupportedImageFormats(dyad_Stream *stream, const void *data, int size);
void readVgpu_clReleaseCommandQueue(dyad_Stream *stream, const void *data, int size);
void readVgpu_clReleaseContext(dyad_Stream *stream, const void *data, int size);
void readVgpu_clReleaseMemObject(dyad_Stream *stream, const void *data, int size);
void readVgpu_clReleaseProgram(dyad_Stream *stream, const void *data, int size);
void readVgpu_clReleaseSampler(dyad_Stream *stream, const void *data, int size);
void readVgpu_clRetainCommandQueue(dyad_Stream *stream, const void *data, int size);
void readVgpu_clRetainContext(dyad_Stream *stream, const void *data, int size);
void readVgpu_clRetainEvent(dyad_Stream *stream, const void *data, int size);
void readVgpu_clRetainKernel(dyad_Stream *stream, const void *data, int size);
void readVgpu_clRetainMemObject(dyad_Stream *stream, const void *data, int size);
void readVgpu_clRetainProgram(dyad_Stream *stream, const void *data, int size);
void readVgpu_clRetainSampler(dyad_Stream *stream, const void *data, int size);
void readVgpu_clSetCommandQueueProperty(dyad_Stream *stream, const void *data, int size);
void readVgpu_clSetKernelArg(dyad_Stream *stream, const void *data, int size);
void readVgpu_clUnloadCompiler(dyad_Stream *stream, const void *data, int size);
void readVgpu_clWaitForEvents(dyad_Stream *stream, const void *data, int size);


// Client send struct
typedef struct  _PARAM_READVGPU_CLBUILDPROGRAM {

    cl_program program;                 // The program object 
    cl_uint num_devices;                // The number of devices listed in device_list.    
    cl_device_id * device_list;         // If device_list is a non-NULL value, the program executable is built for devices specified in this list
    void * notify;                      // A function pointer to a notification routine
    void * user_data;                   // Passed as an argument when pfn_notify is called. user_data can be NULL
    char * strOptions;                    // A pointer to a string that describes the build options to be used for building the program executable

} PARAM_READVGPU_CLBUILDPROGRAM, *LDPARAM_READVGPU_CLBUILDPROGRAM;

#include <CL/opencl.h>

cl_int (*cllib_clBuildProgram) (cl_program program,
                cl_uint              num_devices,
                const cl_device_id * device_list,
                const char *         options,
                void (CL_CALLBACK *  pfn_notify)(cl_program program,
                void * user_data),
                void * user_data) ;

cl_int runVgpu_clBuildProgram (cl_program program,
                cl_uint              num_devices,
                const cl_device_id * device_list,
                const char *         options,
                void (CL_CALLBACK *  pfn_notify)(cl_program program,
                void * user_data),
                void * user_data) ;


cl_int (*cllib_clGetPlatformIDs)(    cl_uint num_entries,
                                    cl_platform_id * platforms,
                                    cl_uint *        num_platforms);

cl_int runVgpu_clGetPlatformIDs(    cl_uint num_entries,
                                    cl_platform_id * platforms,
                                    cl_uint *        num_platforms);

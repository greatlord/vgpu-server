
#include <CL/opencl.h>

/* OpenCL 1.0 support */

typedef cl_int CL_API_CALL 
    ( *funcptr_clBuildProgram )(
        cl_program          program,
        cl_uint             num_devices,
        const cl_device_id  *device_list,
        const char          *options,
        void                (CL_CALLBACK *pfn_notify )(cl_program program, void * user_data),
        void                *user_data);

typedef cl_mem CL_API_CALL 
    ( *funcptr_clCreateBuffer )(
        cl_context      context,
        cl_mem_flags    flags,
        size_t          size,
        void            *host_ptr,
        cl_int          *errcode_ret); 

typedef cl_command_queue CL_API_CALL 
    ( *funcptr_clCreateCommandQueue )(
        cl_context                      context,
        cl_device_id                    device,
        cl_command_queue_properties     properties,
        cl_int                          *errcode_ret);

typedef cl_context CL_API_CALL 
    ( *funcptr_clCreateContext )(
        const cl_context_properties     *properties,
        cl_uint                         num_devices,
        const cl_device_id              *devices,
        void (CL_CALLBACK               *pfn_notify )(const char *errinfo, const void *private_info, size_t cb, void *user_data),
        void *user_data,cl_int          *errcode_ret);

typedef cl_context CL_API_CALL 
    ( *funcptr_clCreateContextFromType )(
        const cl_context_properties     *properties,
        cl_device_type                  device_type,
        void                            (CL_CALLBACK *pfn_notify )(const char *errinfo, const void *private_info, size_t cb, void *user_data),
        void                            *user_data,
        cl_int                          *errcode_ret);

typedef cl_mem CL_API_CALL 
    ( *funcptr_clCreateFromGLBuffer )(
        cl_context      context,
        cl_mem_flags    flags,
        cl_GLuint       bufobj,
        cl_int          *errcode_ret);

typedef cl_mem CL_API_CALL 
    ( *funcptr_clCreateFromGLRenderbuffer )(
        cl_context      context,
        cl_mem_flags    flags,
        cl_GLuint       renderbuffer,
        cl_int          *errcode_ret);

typedef cl_mem CL_API_CALL 
    ( *funcptr_clCreateFromGLTexture2D )(
        cl_context      context,
        cl_mem_flags    flags,
        cl_GLenum       target,
        cl_GLint        miplevel,
        cl_GLuint       texture,
        cl_int          *errcode_ret);

typedef cl_mem CL_API_CALL 
    ( *funcptr_clCreateFromGLTexture3D )(
        cl_context      context,
        cl_mem_flags    flags,
        cl_GLenum       target,
        cl_GLint        miplevel,
        cl_GLuint       texture,
        cl_int          *errcode_ret);

typedef cl_mem CL_API_CALL 
    ( *funcptr_clCreateImage2D )(
        cl_context              context,
        cl_mem_flags            flags,
        const cl_image_format   *image_format,
        size_t                  image_width,
        size_t                  image_height,
        size_t                  image_row_pitch,
        void                    *host_ptr,
        cl_int                  *errcode_ret);

typedef cl_mem CL_API_CALL 
    ( *funcptr_clCreateImage3D )(
        cl_context              context,
        cl_mem_flags            flags,
        const cl_image_format   *image_format,
        size_t                  image_width,
        size_t                  image_height,
        size_t                  image_depth,
        size_t                  image_row_pitch,
        size_t                  image_slice_pitch,
        void                    *host_ptr,
        cl_int                  *errcode_ret);

typedef cl_kernel CL_API_CALL 
    ( *funcptr_clCreateKernel )(
        cl_program              program,
        const char              *kernel_name,
        cl_int                  *errcode_ret);

typedef cl_int CL_API_CALL 
    ( *funcptr_clCreateKernelsInProgram )(
        cl_program              program,
        cl_uint                 num_kernels,
        cl_kernel               *kernels,
        cl_uint                 *num_kernels_ret);

typedef cl_program CL_API_CALL 
    ( *funcptr_clCreateProgramWithBinary )(
        cl_context              context,
        cl_uint                 num_devices,
        const cl_device_id      *device_list,
        const size_t            *lengths,
        const unsigned char     **binaries,
        cl_int                  *binary_status,
        cl_int                  *errcode_ret);

typedef cl_program CL_API_CALL 
    ( *funcptr_clCreateProgramWithSource )(
        cl_context      context,
        cl_uint         count,
        const char      **strings,
        const size_t    *lengths,
        cl_int          *errcode_ret);

typedef cl_sampler CL_API_CALL 
    ( *funcptr_clCreateSampler )(
        cl_context          context,
        cl_bool             normalized_coords,
        cl_addressing_mode  addressing_mode,
        cl_filter_mode      filter_mode,
        cl_int              *errcode_ret); 

typedef cl_int CL_API_CALL 
    ( *funcptr_clEnqueueAcquireGLObjects )(
        cl_command_queue    command_queue,
        cl_uint             num_objects,
        const cl_mem        *mem_objects,
        cl_uint             num_events_in_wait_list,
        const cl_event      *event_wait_list,
        cl_event            *event); 

typedef cl_int CL_API_CALL 
    ( *funcptr_clEnqueueBarrier )(
        cl_command_queue    command_queue,
        cl_uint             num_events_in_wait_list,
        const cl_event      *event_wait_list,
        cl_event            *event);

typedef cl_int CL_API_CALL 
    ( *funcptr_clEnqueueCopyBuffer )(
        cl_command_queue    command_queue,
        cl_mem              src_buffer,
        cl_mem              dst_buffer,
        size_t              src_offset,
        size_t              dst_offset,
        size_t              size,
        cl_uint             num_events_in_wait_list,
        const cl_event      *event_wait_list,
        cl_event            *event);

typedef cl_int CL_API_CALL 
    ( *funcptr_clEnqueueCopyBufferToImage )(
        cl_command_queue    command_queue,
        cl_mem              src_buffer,
        cl_mem              dst_image,
        size_t              src_offset,
        const size_t        *dst_origin,
        const size_t        *region,
        cl_uint             num_events_in_wait_list,
        const cl_event      *event_wait_list,
        cl_event            *event);

typedef cl_int CL_API_CALL 
    ( *funcptr_clEnqueueCopyImage) (
        cl_command_queue    command_queue,
        cl_mem              src_image,
        cl_mem              dst_image,
        const size_t        *src_origin,
        const size_t        *dst_origin,
        const size_t        *region,
        cl_uint             num_events_in_wait_list,
        const cl_event      *event_wait_list,
        cl_event            *event);

typedef cl_int CL_API_CALL 
    ( *funcptr_clEnqueueCopyImageToBuffer) (
        cl_command_queue    command_queue,
        cl_mem              src_image,
        cl_mem              dst_buffer,
        const size_t        *src_origin,
        const size_t        *region,
        size_t              dst_offset,
        cl_uint             num_events_in_wait_list,
        const cl_event      *event_wait_list,
        cl_event            *event); 

typedef void * CL_API_CALL 
    ( *funcptr_clEnqueueMapBuffer )(
        cl_command_queue    command_queue,
        cl_mem              buffer,
        cl_bool             blocking_map,
        cl_map_flags        map_flags,
        size_t              offset,
        size_t              size,
        cl_uint             num_events_in_wait_list,
        const cl_event      *event_wait_list,
        cl_event            *event,
        cl_int              *errcode_ret);

typedef void * CL_API_CALL 
    ( *funcptr_clEnqueueMapImage )(
        cl_command_queue    command_queue,
        cl_mem              image,
        cl_bool             blocking_map,
        cl_map_flags        map_flags,
        const size_t        *origin,
        const size_t        *region,
        size_t              *image_row_pitch,
        size_t              *image_slice_pitch,
        cl_uint             num_events_in_wait_list,
        const cl_event      *event_wait_list,
        cl_event            *event,
        cl_int              *errcode_ret);

typedef cl_int CL_API_CALL ( *funcptr_clEnqueueMarker )(
    cl_command_queue    command_queue,
    cl_event            *event);

typedef cl_int CL_API_CALL 
    ( *funcptr_clEnqueueNDRangeKernel )(
        cl_command_queue    command_queue,
        cl_kernel           kernel,
        cl_uint             work_dim,
        const size_t        *global_work_offset,
        const size_t        *global_work_size,
        const size_t        *local_work_size,
        cl_uint             num_events_in_wait_list,
        const cl_event      *event_wait_list,
        cl_event            *event);

typedef cl_int CL_API_CALL 
    ( *funcptr_clEnqueueNativeKernel )(
        cl_command_queue    command_queue,
        void                (CL_CALLBACK *user_func )(void *),
        void                *args,
        size_t              cb_args,
        cl_uint             num_mem_objects,
        const cl_mem        *mem_list,
        const void          **args_mem_loc,
        cl_uint             num_events_in_wait_list,
        const cl_event      *event_wait_list,
        cl_event            *event);

typedef cl_int CL_API_CALL 
    ( *funcptr_clEnqueueReadBuffer )(
        cl_command_queue    command_queue,
        cl_mem              buffer,
        cl_bool             blocking_read,
        size_t              offset,
        size_t              size,
        void                *ptr,
        cl_uint             num_events_in_wait_list,
        const cl_event      *event_wait_list,
        cl_event            *event);

typedef cl_int CL_API_CALL 
    ( *funcptr_clEnqueueReadImage )(
        cl_command_queue    command_queue,
        cl_mem              image,
        cl_bool             blocking_read,
        const size_t        *origin,
        const size_t        *region,
        size_t              row_pitch,
        size_t              slice_pitch,
        void                *ptr,
        cl_uint             num_events_in_wait_list,
        const cl_event      *event_wait_list,
        cl_event            *event);

typedef cl_int CL_API_CALL 
    ( *funcptr_clEnqueueReleaseGLObjects )(
        cl_command_queue    command_queue,
        cl_uint             num_objects,
        const cl_mem        *mem_objects,
        cl_uint             num_events_in_wait_list,
        const cl_event      *event_wait_list,
        cl_event            *event);

typedef cl_int CL_API_CALL 
    ( *funcptr_clEnqueueTask )(
        cl_command_queue    ommand_queue,
        cl_kernel           kernel,
        cl_uint             num_events_in_wait_list,
        const cl_event      *event_wait_list,
        cl_event            *event);

typedef cl_int CL_API_CALL 
    ( *funcptr_clEnqueueUnmapMemObject )(
        cl_command_queue    command_queue,
        cl_mem              memobj,
        void                *mapped_ptr,
        cl_uint             num_events_in_wait_list,
        const cl_event      *event_wait_list,
        cl_event            *event);

typedef cl_int CL_API_CALL 
    ( *funcptr_clEnqueueWaitForEvents )(
        cl_command_queue    command_queue,
        cl_uint             num_events,
        const cl_event      *event_list);

typedef cl_int CL_API_CALL 
    ( *funcptr_clEnqueueWriteBuffer )(
        cl_command_queue    command_queue,
        cl_mem              buffer,
        cl_bool             blocking_write,
        size_t              offset,
        size_t              size,
        const void          *ptr,
        cl_uint             num_events_in_wait_list,
        const cl_event      *event_wait_list,
        cl_event            *event);

typedef cl_int CL_API_CALL 
    ( *funcptr_clEnqueueWriteImage )(
        cl_command_queue    command_queue,
        cl_mem              image,
        cl_bool             blocking_write,
        const size_t        *origin,
        const size_t        *region,
        size_t              input_row_pitch,
        size_t              input_slice_pitch,
        const void          *ptr,
        cl_uint             num_events_in_wait_list,
        const cl_event      *event_wait_list,
        cl_event            *event);

typedef cl_int CL_API_CALL 
    ( *funcptr_clFinish )(
        cl_command_queue    command_queue);

typedef cl_int CL_API_CALL 
    ( *funcptr_clFlush )(
        cl_command_queue    command_queue);

typedef cl_int CL_API_CALL 
    ( *funcptr_clGetCommandQueueInfo )(
        cl_command_queue        command_queue,
        cl_command_queue_info   param_name,
        size_t                  param_value_size,
        void                    *param_value,
        size_t                  *param_value_size_ret);

typedef cl_int CL_API_CALL 
    ( *funcptr_clGetContextInfo )(
        cl_context          context,
        cl_context_info     param_name,
        size_t              param_value_size,
        void                *param_value,
        size_t              *param_value_size_ret);

typedef cl_int CL_API_CALL 
    ( *funcptr_clGetDeviceIDs )(
        cl_platform_id  platform,
        cl_device_type  device_type,
        cl_uint         num_entries,
        cl_device_id    *devices,
        cl_uint         *num_devices);

typedef cl_int CL_API_CALL 
    ( *funcptr_clGetDeviceInfo )(
        cl_device_id    device,
        cl_device_info  param_name,
        size_t          param_value_size,
        void            *param_value,
        size_t          *param_value_size_ret);

typedef cl_int CL_API_CALL 
    ( *funcptr_clGetEventInfo )(
        cl_event        event,
        cl_event_info   param_name,
        size_t          param_value_size,
        void            *param_value,
        size_t          *param_value_size_ret);

typedef cl_int CL_API_CALL 
    ( *funcptr_clGetEventProfilingInfo )(
        cl_event            event,
        cl_profiling_info   param_name,
        size_t              param_value_size,
        void                *param_value,
        size_t              *param_value_size_ret);

typedef void * CL_API_CALL
    ( *funcptr_clGetExtensionFunctionAddress )(
        cl_platform_id  platform,
        const char      *func_name); 

typedef void * CL_API_CALL
    ( *funcptr_clGetGLObjectInfo )(
        cl_platform_id  platform,
        const char      *func_name);

typedef cl_int CL_API_CALL
    ( *funcptr_clGetGLTextureInfo )(
        cl_mem              memobj,
        cl_gl_texture_info  param_name,
        size_t              param_value_size,
        void                *param_value,
        size_t              *param_value_size_ret);

typedef cl_int CL_API_CALL
    ( *funcptr_clGetImageInfo )(
        cl_mem          image,
        cl_image_info   param_name,
        size_t          param_value_size,
        void            *param_value,
        size_t          *param_value_size_ret);

typedef cl_int CL_API_CALL
    ( *funcptr_clGetKernelInfo )(
        cl_kernel       kernel,
        cl_kernel_info  param_name,
        size_t          param_value_size,
        void            *param_value,
        size_t          *param_value_size_ret);

typedef cl_int CL_API_CALL
    ( *funcptr_clGetKernelWorkGroupInfo )(
        cl_kernel                   kernel,
        cl_device_id                device,
        cl_kernel_work_group_info   param_name,
        size_t                      param_value_size,
        void                        *param_value,
        size_t                      *param_value_size_ret);

typedef cl_int CL_API_CALL
    ( *funcptr_clGetMemObjectInfo )(
        cl_mem      memobj,
        cl_mem_info param_name,
        size_t      param_value_size,
        void        *param_value,
        size_t      *param_value_size_ret);

typedef cl_int CL_API_CALL
    ( *funcptr_clGetPlatformIDs )(
        cl_uint         num_entries,
        cl_platform_id  *platforms,
        cl_uint         *num_platforms);

typedef cl_int CL_API_CALL
    ( *funcptr_clGetPlatformInfo )(
        cl_platform_id      platform,
        cl_platform_info    param_name,
        size_t              param_value_size,
        void                *param_value,
        size_t              *param_value_size_ret);

typedef cl_int CL_API_CALL 
    ( *funcptr_clGetProgramBuildInfo )(
        cl_program              program,
        cl_device_id            device,
        cl_program_build_info   param_name,
        size_t                  param_value_size,
        void                    *param_value,
        size_t                  *param_value_size_ret);

typedef cl_int CL_API_CALL
    ( *funcptr_clGetProgramInfo )(
        cl_program          program,
        cl_program_info     param_name,
        size_t              param_value_size,
        void                *param_value,
        size_t              *param_value_size_ret);

typedef cl_int CL_API_CALL
    ( *funcptr_clGetSamplerInfo )(
        cl_sampler          sampler,
        cl_sampler_info     param_name,
        size_t              param_value_size,
        void                *param_value,
        size_t              *param_value_size_ret);

typedef cl_int CL_API_CALL
    ( *funcptr_clGetSupportedImageFormats )(
        cl_context          context,
        cl_mem_flags        flags,
        cl_mem_object_type  image_type,
        cl_uint             num_entries,
        cl_image_format     *image_formats,
        cl_uint             *num_image_formats);         

typedef cl_int CL_API_CALL
    ( *funcptr_clReleaseCommandQueue )(
        cl_command_queue    command_queue);

typedef cl_int CL_API_CALL
    ( *funcptr_clReleaseContext )(
        cl_context  context);

typedef cl_int CL_API_CALL
    ( *funcptr_clReleaseEvent )(
        cl_event    event);

typedef cl_int CL_API_CALL
    ( *funcptr_clReleaseEvent )(
        cl_event    event);

typedef cl_int CL_API_CALL
    ( *funcptr_clReleaseKernel )(
        cl_kernel   kernel) ;

typedef cl_int CL_API_CALL
    ( *funcptr_clReleaseMemObject )(
        cl_mem  memobj);

typedef cl_int CL_API_CALL
    ( *funcptr_clReleaseProgram )(
        cl_program  program);

typedef cl_int CL_API_CALL
    ( *funcptr_clReleaseSampler )(
        cl_sampler  sampler);

typedef cl_int CL_API_CALL
    ( *funcptr_clRetainCommandQueue )(
        cl_command_queue    command_queue);

typedef cl_int CL_API_CALL 
    ( *funcptr_clRetainContext )(
        cl_context  context);

typedef cl_int CL_API_CALL
    ( *funcptr_clRetainEvent )(
        cl_event event);

typedef cl_int CL_API_CALL
    ( *funcptr_clRetainKernel )(
        cl_kernel    kernel);

typedef cl_int CL_API_CALL
    ( *funcptr_clRetainMemObject )(
        cl_mem  memobj);

typedef cl_int CL_API_CALL
    ( *funcptr_clRetainProgram )(
        cl_program  program);

typedef cl_int CL_API_CALL
    ( *funcptr_clRetainSampler )(
        cl_sampler  sampler);

typedef cl_int CL_API_CALL
    ( *funcptr_clSetCommandQueueProperty )(
        cl_command_queue                command_queue,
        cl_command_queue_properties     properties,
        cl_bool                         enable,
        cl_command_queue_properties     *old_properties);

typedef cl_int CL_API_CALL
    ( *funcptr_clSetKernelArg )(
        cl_kernel   kernel,
        cl_uint     arg_index,
        size_t      arg_size,
        const void  *arg_value);

typedef cl_int CL_API_CALL
    ( *funcptr_clUnloadCompiler )(
        void); 

typedef cl_int CL_API_CALL
    ( *funcptr_clWaitForEvents )(
        cl_uint         num_events,
        const cl_event  *event_list);

typedef cl_mem CL_API_CALL
    ( *funcptr_clCreateSubBuffer )(
        cl_mem                  buffer,
        cl_mem_flags            flags,
        cl_buffer_create_type   buffer_create_type,
        const void              *buffer_create_info,
        cl_int                  *errcode_ret);

typedef cl_event CL_API_CALL
    ( *funcptr_clCreateUserEvent )(
        cl_context  context,
        cl_int      *errcode_ret);

typedef cl_int CL_API_CALL
    ( *funcptr_clEnqueueCopyBufferRect )(
        cl_command_queue    command_queue,
        cl_mem              src_buffer,
        cl_mem              dst_buffer,
        const size_t        *src_origin,
        const size_t        *dst_origin,
        const size_t        *region,
        size_t              src_row_pitch,
        size_t              src_slice_pitch,
        size_t              dst_row_pitch,
        size_t              dst_slice_pitch,
        cl_uint             num_events_in_wait_list,
        const cl_event      *event_wait_list,
        cl_event            *event);

typedef cl_int CL_API_CALL
    ( *funcptr_clEnqueueReadBufferRect )(
        cl_command_queue    command_queue,
        cl_mem              buffer,
        cl_bool             blocking_read,
        const size_t        *buffer_offset,
        const size_t        *host_offset,
        const size_t        *region,
        size_t              buffer_row_pitch,
        size_t              buffer_slice_pitch,
        size_t              host_row_pitch,
        size_t              host_slice_pitch,
        void                *ptr,
        cl_uint             num_events_in_wait_list,
        const cl_event      *event_wait_list,
        cl_event            *event);

typedef cl_int CL_API_CALL
    ( *funcptr_clEnqueueWriteBufferRect )(
        cl_command_queue    command_queue,
        cl_mem              buffer,
        cl_bool             blocking_write,
        const size_t        *buffer_offset,
        const size_t        *host_offset,
        const size_t        *region,
        size_t              buffer_row_pitch,
        size_t              buffer_slice_pitch,
        size_t              host_row_pitch,
        size_t              host_slice_pitch,
        const void          *ptr,
        cl_uint             num_events_in_wait_list,
        const cl_event      *event_wait_list,
        cl_event            *event);

typedef cl_int CL_API_CALL
    ( *funcptr_clSetEventCallback )(
        cl_event    event,
        cl_int      command_exec_callback_type,
        void        (CL_CALLBACK * pfn_notify )(cl_event event, cl_int   event_command_status, void *   user_data),
        void        *user_data);

typedef cl_int CL_API_CALL
    (*funcptr_clSetMemObjectDestructorCallback )(
        cl_mem  memobj,
        void    (CL_CALLBACK * pfn_notify )(cl_mem memobj, void * user_data),
        void    *user_data);

typedef cl_int CL_API_CALL
    ( *funcptr_clSetUserEventStatus )(
        cl_event    event,
        cl_int      execution_status);

typedef cl_int CL_API_CALL
    ( *funcptr_clCompileProgram )(
        cl_program           program,
        cl_uint              num_devices,
        const cl_device_id  *device_list,
        const char          *options,
        cl_uint              num_input_headers,
        const cl_program    *input_headers,
        const char          **header_include_names,
        void                (CL_CALLBACK *pfn_notify )(cl_program program, void *user_data),
        void                *user_data);

typedef cl_mem CL_API_CALL
( *funcptr_clCreateFromGLTexture )(
        cl_context      context,
        cl_mem_flags    flags,
        cl_GLenum       target,
        cl_GLint        miplevel,
        cl_GLuint       texture,
        cl_int          *errcode_ret);

typedef cl_mem CL_API_CALL
    ( *funcptr_clCreateImage )(
        cl_context              context,
        cl_mem_flags            flags,
        const cl_image_format   *image_format,
        const cl_image_desc     *image_desc,
        void                    *host_ptr,
        cl_int                  *errcode_ret) ;

typedef cl_program CL_API_CALL
    ( *funcptr_clCreateProgramWithBuiltInKernels )( 
        cl_context          context,
        cl_uint             num_devices,
        const cl_device_id  *device_list,
        const char          *kernel_names,
        cl_int              *errcode_ret);

typedef cl_int CL_API_CALL
    ( *funcptr_clCreateSubDevices )(
        cl_device_id                        in_device,
        const cl_device_partition_property  *properties,
        cl_uint                             num_devices,
        cl_device_id                        *out_devices,
        cl_uint                             *num_devices_ret);

typedef cl_int CL_API_CALL
    ( *funcptr_clEnqueueBarrierWithWaitList )(
        cl_command_queue    command_queue,
        cl_uint             num_events_in_wait_list,
        const cl_event      *event_wait_list,
        cl_event            *event);

typedef cl_int CL_API_CALL
    ( *funcptr_clEnqueueFillBuffer )(
        cl_command_queue    command_queue,
        cl_mem              buffer,
        const void          *pattern,
        size_t              pattern_size,
        size_t              offset,
        size_t              size,
        cl_uint             num_events_in_wait_list,
        const cl_event      *event_wait_list,
        cl_event            *event);

typedef cl_int CL_API_CALL
    ( *funcptr_clEnqueueFillImage )(
        cl_command_queue    command_queue,
        cl_mem              image,
        const void          *fill_color,
        const size_t        *origin,
        const size_t        *region,
        cl_uint             num_events_in_wait_list,
        const cl_event      *event_wait_list,
        cl_event            *event);

typedef cl_int CL_API_CALL
    ( *funcptr_clEnqueueMarkerWithWaitList )(
        cl_command_queue    command_queue,
        cl_uint             num_events_in_wait_list,
        const cl_event      *event_wait_list,
        cl_event            *event);

typedef cl_int CL_API_CALL
    ( *funcptr_clEnqueueMigrateMemObjects )(
        cl_command_queue        command_queue,
        cl_uint                 num_mem_objects,
        const cl_mem            *mem_objects,
        cl_mem_migration_flags  flags,
        cl_uint                 num_events_in_wait_list,
        const cl_event          *event_wait_list,
        cl_event                *event);

typedef void * CL_API_CALL
    ( *funcptr_clGetExtensionFunctionAddressForPlatform )(
        cl_platform_id  platform,
        const char      *func_name);

typedef cl_int CL_API_CALL
    ( *funcptr_clGetKernelArgInfo )(
        cl_kernel           kernel,
        cl_uint             arg_indx,
        cl_kernel_arg_info  param_name,
        size_t              param_value_size,
        void                *param_value,
        size_t              *param_value_size_ret);

typedef cl_program CL_API_CALL
    ( *funcptr_clLinkProgram )(
        cl_context          context,
        cl_uint             num_devices,
        const cl_device_id  *device_list,
        const char          *options,
        cl_uint             num_input_programs,
        const cl_program    *input_programs,
        void                (CL_CALLBACK *pfn_notify )(cl_program program, void * user_data),
        void                *user_data,
        cl_int              *errcode_ret);

typedef cl_int CL_API_CALL
    ( *funcptr_clReleaseDevice )(
        cl_device_id    device);

typedef cl_int CL_API_CALL
    ( *funcptr_clRetainDevice )(
        cl_device_id    device);

typedef cl_int CL_API_CALL
    ( *funcptr_clUnloadPlatformCompiler )(
        cl_platform_id  platform);

typedef cl_command_queue CL_API_CALL
    ( *funcptr_clCreateCommandQueueWithProperties )(
        cl_context                  context,
        cl_device_id                device,
        const cl_queue_properties   *properties,
        cl_int                      *errcode_ret);

typedef cl_mem CL_API_CALL
    ( *funcptr_clCreatePipe )(
        cl_context                  context,
        cl_mem_flags                flags,
        cl_uint                     pipe_packet_size,
        cl_uint                     pipe_max_packets,
        const cl_pipe_properties    *properties,
        cl_int                      *errcode_ret);

typedef cl_sampler CL_API_CALL
    ( *funcptr_clCreateSamplerWithProperties )(
        cl_context                      context,
        const cl_sampler_properties     *sampler_properties,
        cl_int                          *errcode_ret);

typedef cl_int CL_API_CALL
    ( *funcptr_clEnqueueSVMFree )(
        cl_command_queue    command_queue,
        cl_uint             num_svm_pointers,
        void                *svm_pointers[],
        void                (CL_CALLBACK * pfn_free_func )(cl_command_queue queue,cl_uint num_svm_pointers, void *svm_pointers[], void *user_data),
        void                *user_data,
        cl_uint             num_events_in_wait_list,
        const cl_event      *event_wait_list,
        cl_event            *event);

typedef cl_int CL_API_CALL
    ( *funcptr_clEnqueueSVMMap )(
        cl_command_queue    command_queue,
        cl_bool             blocking_map,
        cl_map_flags        flags,
        void                *svm_ptr,
        size_t              size,
        cl_uint             num_events_in_wait_list,
        const cl_event      *event_wait_list,
        cl_event            *event);

typedef cl_int CL_API_CALL
    ( *funcptr_clEnqueueSVMMemcpy )(
        cl_command_queue    command_queue,
        cl_bool             blocking_copy,
        void                *dst_ptr,
        const void          *src_ptr,
        size_t              size,
        cl_uint             num_events_in_wait_list,
        const cl_event      *event_wait_list,
        cl_event            *event);

typedef cl_int CL_API_CALL
    ( *funcptr_clEnqueueSVMMemFill )(
        cl_command_queue    command_queue,
        void                *svm_ptr,
        const void          *pattern,
        size_t              pattern_size,
        size_t              size,
        cl_uint             num_events_in_wait_list,
        const cl_event      *event_wait_list,
        cl_event            *event);

typedef cl_int CL_API_CALL
    ( *funcptr_clEnqueueSVMUnmap )(
        cl_command_queue    command_queue,
        void                *svm_ptr,
        cl_uint             num_events_in_wait_list,
        const cl_event      *event_wait_list,
        cl_event            *event);

typedef cl_int CL_API_CALL
    ( *funcptr_clGetPipeInfo )(
        cl_mem          pipe,
        cl_pipe_info    param_name,
        size_t          param_value_size,
        void            *param_value,
        size_t          *param_value_size_ret);

typedef cl_int CL_API_CALL
    ( *funcptr_clSetKernelArgSVMPointer )(
        cl_kernel   kernel,
        cl_uint     arg_index,
        const void  *arg_value);

typedef cl_int CL_API_CALL
    ( *funcptr_clSetKernelExecInfo )(
        cl_kernel               kernel,
        cl_kernel_exec_info     param_name,
        size_t                  param_value_size,
        const void              *param_value);

typedef void * CL_API_CALL
    ( *funcptr_clSVMAlloc )(
        cl_context          context,
        cl_svm_mem_flags    flags,
        size_t              size,
        cl_uint             alignment);

typedef void CL_API_CALL
    ( *funcptr_clSVMFree )(
        cl_context  context,
        void        *svm_pointer);

typedef cl_kernel CL_API_CALL
    ( *funcptr_clCloneKernel )(
        cl_kernel   source_kernel,
        cl_int  *errcode_ret);

typedef cl_program CL_API_CALL
    ( *funcptr_clCreateProgramWithIL )(
        cl_context  context,
        const void  *il,
        size_t      length,
        cl_int      *errcode_ret);

typedef cl_int CL_API_CALL
    ( *funcptr_clEnqueueSVMMigrateMem )(
        cl_command_queue        command_queue,
        cl_uint                 num_svm_pointers,
        const void              **svm_pointers,
        const size_t            *sizes,
        cl_mem_migration_flags  flags,
        cl_uint                 num_events_in_wait_list,
        const cl_event          *event_wait_list,
        cl_event                *event);

typedef cl_int CL_API_CALL
    ( *funcptr_clGetDeviceAndHostTimer )(
        cl_device_id    device,
        cl_ulong        *device_timestamp,
        cl_ulong        *host_timestamp);

typedef cl_int CL_API_CALL
    ( *funcptr_clGetHostTimer )(
        cl_device_id    device,
        cl_ulong        *host_timestamp);

typedef cl_int CL_API_CALL
    ( *funcptr_clGetKernelSubGroupInfo )(
        cl_kernel                   kernel,
        cl_device_id                device,
        cl_kernel_sub_group_info    param_name,
        size_t                      input_value_size,
        const void                  *input_value,
        size_t                      param_value_size,
        void                        *param_value,
        size_t                      *param_value_size_ret);

typedef cl_int CL_API_CALL
    ( *funcptr_clSetDefaultDeviceCommandQueue )(
        cl_context          context,
        cl_device_id        device,
        cl_command_queue    command_queue);

typedef cl_int CL_API_CALL
    ( *funcptr_clSetProgramReleaseCallback )(
        cl_program  program,
        void        (CL_CALLBACK * pfn_notify )(cl_program program,
        void        *user_data),
        void        *user_data);

typedef cl_int CL_API_CALL
    ( *funcptr_clSetProgramSpecializationConstant )(
        cl_program  program,
        cl_uint     spec_id,
        size_t      spec_size,
        const void* spec_value);

// OpenCL 1.0 API

    funcptr_clBuildProgram                              funcint_clBuildProgram                              = NULL;
    funcptr_clCreateBuffer                              funcint_clCreateBuffer                              = NULL;
    funcptr_clCreateCommandQueue                        funcint_clCreateCommandQueue                        = NULL;
    funcptr_clCreateContext                             funcint_clCreateContext                             = NULL;
    funcptr_clCreateContextFromType                     funcint_clCreateContextFromType                     = NULL;
    funcptr_clCreateFromGLBuffer                        funcint_clCreateFromGLBuffer                        = NULL;
    funcptr_clCreateFromGLRenderbuffer                  funcint_clCreateFromGLRenderbuffer                  = NULL;
    funcptr_clCreateFromGLTexture2D                     funcint_clCreateFromGLTexture2D                     = NULL;
    funcptr_clCreateFromGLTexture3D                     funcint_clCreateFromGLTexture3D                     = NULL;
    funcptr_clCreateImage2D                             funcint_clCreateImage2D                             = NULL;
    funcptr_clCreateImage3D                             funcint_clCreateImage3D                             = NULL;
    funcptr_clCreateKernel                              funcint_clCreateKernel                              = NULL;
    funcptr_clCreateKernelsInProgram                    funcint_clCreateKernelsInProgram                    = NULL;
    funcptr_clCreateProgramWithBinary                   funcint_clCreateProgramWithBinary                   = NULL;
    funcptr_clCreateProgramWithSource                   funcint_clCreateProgramWithSource                   = NULL;
    funcptr_clCreateSampler                             funcint_clCreateSampler                             = NULL;
    funcptr_clEnqueueAcquireGLObjects                   funcint_clEnqueueAcquireGLObjects                   = NULL;
    funcptr_clEnqueueBarrier                            funcint_clEnqueueBarrier                            = NULL;
    funcptr_clEnqueueCopyBuffer                         funcint_clEnqueueCopyBuffer                         = NULL;
    funcptr_clEnqueueCopyBufferToImage                  funcint_clEnqueueCopyBufferToImage                  = NULL;
    funcptr_clEnqueueCopyImage                          funcint_clEnqueueCopyImage                          = NULL;
    funcptr_clEnqueueCopyImageToBuffer                  funcint_clEnqueueCopyImageToBuffer                  = NULL;
    funcptr_clEnqueueMapBuffer                          funcint_clEnqueueMapBuffer                          = NULL;
    funcptr_clEnqueueMapImage                           funcint_clEnqueueMapImage                           = NULL;
    funcptr_clEnqueueMarker                             funcint_clEnqueueMarker                             = NULL;
    funcptr_clEnqueueNDRangeKernel                      funcint_clEnqueueNDRangeKernel                      = NULL;
    funcptr_clEnqueueNativeKernel                       funcint_clEnqueueNativeKernel                       = NULL;
    funcptr_clEnqueueReadBuffer                         funcint_clEnqueueReadBuffer                         = NULL;
    funcptr_clEnqueueReadImage                          funcint_clEnqueueReadImage                          = NULL;
    funcptr_clEnqueueReleaseGLObjects                   funcint_clEnqueueReleaseGLObjects                   = NULL;
    funcptr_clEnqueueTask                               funcint_clEnqueueTask                               = NULL;
    funcptr_clEnqueueUnmapMemObject                     funcint_clEnqueueUnmapMemObject                     = NULL;
    funcptr_clEnqueueWaitForEvents                      funcint_clEnqueueWaitForEvents                      = NULL;
    funcptr_clEnqueueWriteBuffer                        funcint_clEnqueueWriteBuffer                        = NULL;
    funcptr_clEnqueueWriteImage                         funcint_clEnqueueWriteImage                         = NULL;
    funcptr_clFinish                                    funcint_clFinish                                    = NULL;
    funcptr_clFlush                                     funcint_clFlush                                     = NULL;
    funcptr_clGetCommandQueueInfo                       funcint_clGetCommandQueueInfo                       = NULL;
    funcptr_clGetContextInfo                            funcint_clGetContextInfo                            = NULL;
    funcptr_clGetDeviceIDs                              funcint_clGetDeviceIDs                              = NULL;
    funcptr_clGetDeviceInfo                             funcint_clGetDeviceInfo                             = NULL;
    funcptr_clGetEventInfo                              funcint_clGetEventInfo                              = NULL;
    funcptr_clGetEventProfilingInfo                     funcint_clGetEventProfilingInfo                     = NULL;
    funcptr_clGetExtensionFunctionAddress               funcint_clGetExtensionFunctionAddress               = NULL;
    funcptr_clGetGLObjectInfo                           funcint_clGetGLObjectInfo                           = NULL;
    funcptr_clGetGLTextureInfo                          funcint_clGetGLTextureInfo                          = NULL;
    funcptr_clGetImageInfo                              funcint_clGetImageInfo                              = NULL;
    funcptr_clGetKernelInfo                             funcint_clGetKernelInfo                             = NULL;
    funcptr_clGetKernelWorkGroupInfo                    funcint_clGetKernelWorkGroupInfo                    = NULL;
    funcptr_clGetMemObjectInfo                          funcint_clGetMemObjectInfo                          = NULL;
    funcptr_clGetPlatformIDs                            funcint_clGetPlatformIDs                            = NULL;
    funcptr_clGetPlatformInfo                           funcint_clGetPlatformInfo                           = NULL;
    funcptr_clGetProgramBuildInfo                       funcint_clGetProgramBuildInfo                       = NULL; 
    funcptr_clGetProgramInfo                            funcint_clGetProgramInfo                            = NULL; 
    funcptr_clGetSamplerInfo                            funcint_clGetSamplerInfo                            = NULL; 
    funcptr_clGetSupportedImageFormats                  funcint_clGetSupportedImageFormats                  = NULL; 
    funcptr_clReleaseCommandQueue                       funcint_clReleaseCommandQueue                       = NULL; 
    funcptr_clReleaseContext                            funcint_clReleaseContext                            = NULL; 
    funcptr_clReleaseEvent                              funcint_clReleaseEvent                              = NULL; 
    funcptr_clReleaseKernel                             funcint_clReleaseKernel                             = NULL; 
    funcptr_clReleaseMemObject                          funcint_clReleaseMemObject                          = NULL; 
    funcptr_clReleaseProgram                            funcint_clReleaseProgram                            = NULL; 
    funcptr_clReleaseSampler                            funcint_clReleaseSampler                            = NULL; 
    funcptr_clRetainCommandQueue                        funcint_clRetainCommandQueue                        = NULL;
    funcptr_clRetainContext                             funcint_clRetainContext                             = NULL;
    funcptr_clRetainEvent                               funcint_clRetainEvent                               = NULL;
    funcptr_clRetainKernel                              funcint_clRetainKernel                              = NULL;
    funcptr_clRetainMemObject                           funcint_clRetainMemObject                           = NULL;
    funcptr_clRetainProgram                             funcint_clRetainProgram                             = NULL;
    funcptr_clRetainSampler                             funcint_clRetainSampler                             = NULL;
    funcptr_clSetCommandQueueProperty                   funcint_clSetCommandQueueProperty                   = NULL;
    funcptr_clSetKernelArg                              funcint_clSetKernelArg                              = NULL;
    funcptr_clUnloadCompiler                            funcint_clUnloadCompiler                            = NULL;
    funcptr_clWaitForEvents                             funcint_clWaitForEvents                             = NULL;

// OpenCL 1.1 API
    funcptr_clCreateSubBuffer                           funcint_clCreateSubBuffer                           = NULL;
    funcptr_clCreateUserEvent                           funcint_clCreateUserEvent                           = NULL;
    funcptr_clEnqueueCopyBufferRect                     funcint_clEnqueueCopyBufferRect                     = NULL;
    funcptr_clEnqueueReadBufferRect                     funcint_clEnqueueReadBufferRect                     = NULL;
    funcptr_clEnqueueWriteBufferRect                    funcint_clEnqueueWriteBufferRect                    = NULL;
    funcptr_clSetEventCallback                          funcint_clSetEventCallback                          = NULL;
    funcptr_clSetMemObjectDestructorCallback            funcint_clSetMemObjectDestructorCallback            = NULL;
    funcptr_clSetUserEventStatus                        funcint_clSetUserEventStatus                        = NULL;

// OpenCL 1.2 API
    funcptr_clCompileProgram                            funcint_clCompileProgram                            = NULL;
    funcptr_clCreateFromGLTexture                       funcint_clCreateFromGLTexture                       = NULL;
    funcptr_clCreateImage                               funcint_clCreateImage                               = NULL;
    funcptr_clCreateProgramWithBuiltInKernels           funcint_clCreateProgramWithBuiltInKernels           = NULL;
    funcptr_clCreateSubDevices                          funcint_clCreateSubDevices                          = NULL;
    funcptr_clEnqueueBarrierWithWaitList                funcint_clEnqueueBarrierWithWaitList                = NULL;
    funcptr_clEnqueueFillBuffer                         funcint_clEnqueueFillBuffer                         = NULL;
    funcptr_clEnqueueFillImage                          funcint_clEnqueueFillImage                          = NULL;
    funcptr_clEnqueueMarkerWithWaitList                 funcint_clEnqueueMarkerWithWaitList                 = NULL;
    funcptr_clEnqueueMigrateMemObjects                  funcint_clEnqueueMigrateMemObjects                  = NULL;
    funcptr_clGetExtensionFunctionAddressForPlatform    funcint_clGetExtensionFunctionAddressForPlatform    = NULL;
    funcptr_clGetKernelArgInfo                          funcint_clGetKernelArgInfo                          = NULL;
    funcptr_clLinkProgram                               funcint_clLinkProgram                               = NULL;
    funcptr_clReleaseDevice                             funcint_clReleaseDevice                             = NULL;
    funcptr_clRetainDevice                              funcint_clRetainDevice                              = NULL;
    funcptr_clUnloadPlatformCompiler                    funcint_clUnloadPlatformCompiler                    = NULL;

// OpenCL 2.0 API
    funcptr_clCreateCommandQueueWithProperties          funcint_clCreateCommandQueueWithProperties          = NULL;
    funcptr_clCreatePipe                                funcint_clCreatePipe                                = NULL;
    funcptr_clCreateSamplerWithProperties               funcint_clCreateSamplerWithProperties               = NULL;
    funcptr_clEnqueueSVMFree                            funcint_clEnqueueSVMFree                            = NULL;
    funcptr_clEnqueueSVMMap                             funcint_clEnqueueSVMMap                             = NULL;
    funcptr_clEnqueueSVMMemcpy                          funcint_clEnqueueSVMMemcpy                          = NULL;
    funcptr_clEnqueueSVMMemFill                         funcint_clEnqueueSVMMemFill                         = NULL;
    funcptr_clEnqueueSVMUnmap                           funcint_clEnqueueSVMUnmap                           = NULL;
    funcptr_clGetPipeInfo                               funcint_clGetPipeInfo                               = NULL;
    funcptr_clSetKernelArgSVMPointer                    funcint_clSetKernelArgSVMPointer                    = NULL;
    funcptr_clSetKernelExecInfo                         funcint_clSetKernelExecInfo                         = NULL;
    funcptr_clSVMAlloc                                  funcint_clSVMAlloc                                  = NULL;
    funcptr_clSVMFree                                   funcint_clSVMFree                                   = NULL;

// OpenCL 2.1 API
    funcptr_clCloneKernel                               funcint_clCloneKernel                               = NULL;
    funcptr_clCreateProgramWithIL                       funcint_clCreateProgramWithIL                       = NULL;
    funcptr_clEnqueueSVMMigrateMem                      funcint_clEnqueueSVMMigrateMem                      = NULL;
    funcptr_clGetDeviceAndHostTimer                     funcint_clGetDeviceAndHostTimer                     = NULL;
    funcptr_clGetHostTimer                              funcint_clGetHostTimer                              = NULL;
    funcptr_clGetKernelSubGroupInfo                     funcint_clGetKernelSubGroupInfo                     = NULL;
    funcptr_clSetDefaultDeviceCommandQueue              funcint_clSetDefaultDeviceCommandQueue              = NULL;

// OpenCL 2.2 API
    funcptr_clSetProgramReleaseCallback                 funcint_clSetProgramReleaseCallback                 = NULL;
    funcptr_clSetProgramSpecializationConstant          funcint_clSetProgramSpecializationConstant          = NULL;


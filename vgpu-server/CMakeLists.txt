cmake_minimum_required(VERSION 3.0.0)
project(vgpu-server VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(vgpu-server main.c vgpu-cmd.c load-gpu-opencl.c ../../dyad/src/dyad.c )

target_link_libraries( vgpu-server  dl)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

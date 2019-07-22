cmake_minimum_required(VERSION 3.0.0)
project(vgpu-server VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(vgpu-server main.c vgpu_cmd.c ../../dyad/src/dyad.c )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

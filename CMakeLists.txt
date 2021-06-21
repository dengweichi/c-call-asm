cmake_minimum_required(VERSION 3.16)
project(c_call_asm)

# 只支持linux系统
if(NOT(CMAKE_SYSTEM_NAME STREQUAL "Linux"))
    message(SEND_ERROR "only support linux system")
endif()

# 只支持64位系统
if(NOT(CMAKE_SIZEOF_VOID_P EQUAL 8))
    message(STATUS "only support 64 bits")
endif()

# 只支持x86-64位处理器
if(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "x86_64")
    message(STATUS "only support x86-64")
endif()

enable_language(ASM)
add_executable(${PROJECT_NAME} main.c foo.s)
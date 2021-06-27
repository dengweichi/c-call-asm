cmake_minimum_required(VERSION 3.16)
project(c_call_asm)



# 只支持64位系统
if(NOT(CMAKE_SIZEOF_VOID_P EQUAL 4))
    message(STATUS "only support 32 bits")
endif()

# 只支持x86-64位处理器
if( (NOT(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "AMD64")) AND (NOT(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "x86_64")))
    message(FATAL_ERROR "only support x86-64")
endif()

enable_language(ASM_NASM)
add_executable(${PROJECT_NAME} main.cpp)
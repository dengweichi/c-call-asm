cmake_minimum_required(VERSION 3.16)
project(nasm-learn)



# 默认nasm的扩展名为 asm
set(CMAKE_ASM_NASM_SOURCE_FILE_EXTENSIONS "asm;s;S")


add_subdirectory(./googletest)
include_directories(./googletest/googletest/include)
include_directories(./googletest/googlemock/include)


#根据指针大小定义64位和32位宏
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    add_definitions(-DBITS_64)
else()
    add_definitions(-DBITS_32)
endif()

#默认情况下，nasm的全局函数没有使用_拼接，所以需要全局使用_作为函数的前缀
# 如果为debug模式，启动nasm的调试模式
set(CMAKE_ASM_NASM_FLAGS "${CMAKE_ASM_NASM_FLAGS} -g --prefix _")


# 只支持x86-64位处理器
if( (NOT(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "AMD64")) AND (NOT(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "x86_64")))
    message(FATAL_ERROR "only support x86-64")
endif()

enable_language(ASM_NASM)


add_executable(${PROJECT_NAME} main.cpp ./test/test_pseudo_instruction_32.cpp ./test/test_pseudo_instruction_32.s)
# 链接google的测试库
target_link_libraries(${PROJECT_NAME}  gtest gtest_main)
target_link_libraries(${PROJECT_NAME}  gmock gmock)
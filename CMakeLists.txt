# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)
# 执行gcc、g++版本
#SET(CMAKE_C_COMPILER "/opt/compiler/gcc-8.2/bin/gcc")
#SET(CMAKE_CXX_COMPILER "/opt/compiler/gcc-8.2/bin/g++")
# 项目信息
project (algorithm)
 
#去哪里找头文件 相当于-I(i的大写字母)参数
include_directories(${PROJECT_SOURCE_DIR}/include)
#include_directories(/usr/local/include)
# set(LINK_DIR ${PROJECT_SOURCE_DIR}/lib)
# link_directories(${LINK_DIR})
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
SET( CMAKE_CXX_FLAGS "-std=c++11 -O3")
# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

# 添加 lib 子目录
add_subdirectory(src)
# add_subdirectory(include/pb)
# 指定生成目标
add_executable(algorithm ${DIR_SRCS})
target_link_libraries(algorithm src)
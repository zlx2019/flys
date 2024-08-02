cmake_minimum_required(VERSION 3.12)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# C++ 标准
set(CMAKE_CXX_STANDARD 17)
# 最终生成的可执行文件名称
set(WORK_NAME "flys")
project(${WORK_NAME} LANGUAGES CXX)
# 可执行文件生成目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 编译参数
add_compile_options(-Wall -Wextra -Werror=return-type)
# 将 ./include 作为头文件检索目录
# include_directories(${PROJECT_SOURCE_DIR}/include)

# 查找 src 目录中所有 .cpp 文件
file(GLOB_RECURSE SRC_FILES src/*.cpp)

# 查找 fmt 库
find_package(FMT REQUIRED)

# 指定程序入口源文件
add_executable(${WORK_NAME} main.cpp)
# 为可执行文件，链接目标文件、静态链接库
target_link_libraries(${WORK_NAME} fmt::fmt ${SRC_FILES})
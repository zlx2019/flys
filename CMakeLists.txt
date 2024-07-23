cmake_minimum_required(VERSION 3.12)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# C++ 标准
set(CMAKE_CXX_STANDARD 17)
project(flys LANGUAGES CXX)

# 编译参数
add_compile_options(-Wall -Wextra -Werror=return-type)
# 将 根目录/include 作为头文件检索目录
include_directories(${PROJECT_SOURCE_DIR}/include)
# 可执行文件生成目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 查找根目录中的所有 .cpp 文件，并存储在 sources 变量中
file(GLOB sources CONFIGURE_DEPENDS *.cpp)

# 查找 src 目录中所有 .cpp 文件，并存储在 
file(GLOB_RECURSE SRC_FILES src/*.cpp)

# 遍历每个源文件，为每个源文件创建一个可执行程序, 并链接 fmt 库
foreach (source IN ITEMS ${sources})
    get_filename_component(name "${source}" NAME_WLE)
    # 程序主文件 main 文件
    if(${name} STREQUAL "main")
        add_executable(flys ${name}.cpp ${SRC_FILES})
        target_link_libraries(flys /usr/local/lib/libfmt.a)
    else()
        add_executable(${name} ${name}.cpp)
        target_link_libraries(${name} /usr/local/lib/libfmt.a)
    endif()
endforeach()

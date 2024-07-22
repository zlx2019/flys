cmake_minimum_required(VERSION 3.12)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# C++ 标准
set(CMAKE_CXX_STANDARD 17)
project(flys LANGUAGES CXX)

# 编译参数
add_compile_options(-Wall -Wextra -Werror=return-type)

# 指定头文件目录
include_directories(/usr/local/include)
# 查找当前目录中的所有 .cpp 文件，并存储在 sources 变量中
file(GLOB sources CONFIGURE_DEPENDS *.cpp)

# 可执行文件生成目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 遍历每个源文件，为每个源文件创建一个可执行程序
foreach (source IN ITEMS ${sources})
    get_filename_component(name "${source}" NAME_WLE)
    add_executable(${name} ${name}.cpp)
    # 链接 fmt 依赖库.
    target_link_libraries(${name} /usr/local/lib/libfmt.a)
endforeach()
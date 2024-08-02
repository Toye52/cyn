# 设置所需的最低CMake版本
cmake_minimum_required(VERSION 3.22)

# 设置项目名称和版本
project(Myproject VERSION 1.0)

# 设置C++标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 查找当前目录下的所有源文件，并将它们存储在变量 SRC_LIST 中
file(GLOB SRC_LIST "*.cpp")

# 添加可执行文件，使用通用的源文件列表
add_executable(Myproject ${SRC_LIST})
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(PROJECT_NAME "she_log_sample")
set(CMAKE_CXX_FLAGS "-g")# 断点无效处理方案
project(${PROJECT_NAME})

# set
set(she_log ${CMAKE_SOURCE_DIR}/she_log)

# include
include_directories(${she_log}/include)
# lib
link_directories(${she_log}/lib)

file(GLOB_RECURSE SRC "${CMAKE_SOURCE_DIR}/sample.cpp")
add_executable(${PROJECT_NAME} ${SRC})

# 链接库
target_link_libraries(${PROJECT_NAME} "-pthread"
        she_log)
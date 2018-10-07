cmake_minimum_required(VERSION 3.12)
project(Cpp_unittest)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES main.cpp)
add_executable(cpp_unittest_run ${SOURCE_FILES})

include_directories(src)

add_subdirectory(src)
add_subdirectory(tests)

target_link_libraries(cpp_unittest_run cpp_unittest_src)

cmake_minimum_required(VERSION 3.10)
project(oj_problem_056)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(code main.cpp)

# Optimize for speed and enable warnings
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
  target_compile_options(code PRIVATE -O2 -pipe -Wall -Wextra -Wshadow -Wconversion -Wno-sign-conversion)
endif()


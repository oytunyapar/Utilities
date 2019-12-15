cmake_minimum_required(VERSION 3.10)

project(Utilites VERSION 1.0)

set(BINARY ${CMAKE_PROJECT_NAME})

#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

include_directories(src/include)

add_subdirectory(tests)
add_subdirectory(src)

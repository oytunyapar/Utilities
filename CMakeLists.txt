cmake_minimum_required(VERSION 3.10)

project(Utilities VERSION 1.0)

set(BINARY ${CMAKE_PROJECT_NAME})

#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

include_directories(src/include)

file(GLOB UTILITIES_LOGGING_SOURCE_FILES
    "src/logging/*.cpp"
)

add_definitions(-DBOOST_LOG_DYN_LINK)

find_package(Boost REQUIRED COMPONENTS log log_setup)
include_directories(${Boost_INCLUDE_DIR})

add_subdirectory(tests)
add_subdirectory(src)

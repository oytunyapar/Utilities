set(TEST_BINARY "${BINARY}_unit_tests")

add_executable(${TEST_BINARY} unit_tests_main.cpp)

set(CMAKE_BUILD_TYPE unittest)
set(CMAKE_CXX_FLAGS_UNITTEST "-O0")

find_package(Threads)

find_library(libgtest_location NAMES libgtest.a)
message(STATUS ${libgtest_location})

add_library(libgtest STATIC IMPORTED)
set_target_properties(libgtest PROPERTIES IMPORTED_LOCATION ${libgtest_location})

find_library(libgmock_location NAMES libgmock.a)
message(STATUS ${libgmock_location})

add_library(libgmock STATIC IMPORTED)
set_target_properties(libgmock PROPERTIES IMPORTED_LOCATION ${libgmock_location})

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fprofile-arcs -ftest-coverage")
    target_link_libraries(${TEST_BINARY} gcov)
endif()

target_link_libraries(${TEST_BINARY} libgtest libgmock ${CMAKE_THREAD_LIBS_INIT})

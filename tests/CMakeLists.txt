set(TEST_BINARY "${BINARY}_unit_tests")

file(GLOB UTILITIES_MOCK_SOURCE_FILES
    "mocks/*.cpp"
)

file(GLOB UTILITIES_TEST_SOURCE_FILES
    "unit_tests/*.cpp"
)

include_directories(unit_tests)
include_directories(mocks)

add_executable(${TEST_BINARY} unit_tests_main.cpp ${UTILITIES_TEST_SOURCE_FILES} ${UTILITIES_MOCK_SOURCE_FILES})

set(CMAKE_BUILD_TYPE unittest)
set(CMAKE_CXX_FLAGS_UNITTEST "-O0")

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fprofile-arcs -ftest-coverage")
    target_link_libraries(${TEST_BINARY} gcov)
endif()

add_library(utilities STATIC ${UTILITIES_LOGGING_SOURCE_FILES})

find_package(Threads)

find_library(libgtest_location NAMES libgtest.a)
message(STATUS ${libgtest_location})

add_library(libgtest STATIC IMPORTED)
set_target_properties(libgtest PROPERTIES IMPORTED_LOCATION ${libgtest_location})

find_library(libgmock_location NAMES libgmock.a)
message(STATUS ${libgmock_location})

add_library(libgmock STATIC IMPORTED)
set_target_properties(libgmock PROPERTIES IMPORTED_LOCATION ${libgmock_location})

target_link_libraries(${TEST_BINARY} libgtest libgmock utilities ${CMAKE_THREAD_LIBS_INIT} ${Boost_LIBRARIES})

set(TEST_BINARY "${BINARY}_unit_tests")

add_executable(${TEST_BINARY} unit_tests_main.cpp)

find_package(Threads)

find_library(libgtest_location NAMES libgtest.a)
message(STATUS ${libgtest_location})

add_library(libgtest STATIC IMPORTED)
set_target_properties(libgtest PROPERTIES IMPORTED_LOCATION ${libgtest_location})

find_library(libgtestmain_location NAMES libgtest.a)
message(STATUS ${libgtestmain_location})

add_library(libgtestmain STATIC IMPORTED)
set_target_properties(libgtestmain PROPERTIES IMPORTED_LOCATION ${libgtestmain_location})

target_link_libraries(${TEST_BINARY} libgtest libgtestmain ${CMAKE_THREAD_LIBS_INIT}) 
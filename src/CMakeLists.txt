add_executable(${BINARY} main.cpp ${UTILITIES_LOGGING_SOURCE_FILES})

target_link_libraries(${BINARY} ${Boost_LIBRARIES})


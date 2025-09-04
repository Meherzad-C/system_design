# Glob all source and header files
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "*.cpp")
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS "*.h")

# Create an executable target named `observer_pattern_test`
add_executable(observer_pattern_test ${SOURCES} ${HEADERS})

# Include current directory for headers
target_include_directories(observer_pattern_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
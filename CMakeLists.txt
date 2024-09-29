cmake_minimum_required(VERSION 3.5.0)
project(FlushTools VERSION 0.1.0 LANGUAGES C CXX)

# Add the FlushTools library
add_library(FlushTools SHARED src/FlushTools.cpp)

# Specify where to find the header files (without absolute paths in install target)
target_include_directories(FlushTools PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

set_target_properties(FlushTools PROPERTIES CXX_STANDARD 20 CXX_STANDARD_REQUIRED YES)

# Install FlushTools library and headers
install(TARGETS FlushTools
        EXPORT Flush_Tools_targets
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin)

install(DIRECTORY include/ DESTINATION include)

install(EXPORT Flush_Tools_targets
        FILE FlushToolsConfig.cmake
        NAMESPACE FlushTools::
        DESTINATION lib/cmake/FlushTools)

# Fetch GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(googletest)

# Add the test executable for randomGen
enable_testing()
add_executable(test_flush_tools_random tests/test_flush_tools_random.cpp)

# Link GoogleTest and FlushTools to the test executable
target_link_libraries(test_flush_tools_random gtest_main FlushTools)

# Add tests
add_test(NAME RandomGenInRangeTest COMMAND test_flush_tools_random)

# Add the test executable for TimerTest
add_executable(test_timer tests/test_flush_tools_timer.cpp)

# Link GoogleTest and FlushTools to the test executable
target_link_libraries(test_timer gtest_main FlushTools)

# Add tests
add_test(NAME TimerTest COMMAND test_timer)
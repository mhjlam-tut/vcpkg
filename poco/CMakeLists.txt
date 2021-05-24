cmake_minimum_required(VERSION 3.16)
project(HelloWorld DESCRIPTION "A hello world project" VERSION 0.0.1)

# find 3rd party dependencies
find_package(fmt CONFIG REQUIRED)
find_package(Poco CONFIG REQUIRED Foundation)
find_package(Catch2 CONFIG REQUIRED)

# create target for library
add_library(processlib src/process.cpp)
target_compile_features(processlib PUBLIC cxx_std_17)
target_link_libraries(processlib PRIVATE fmt::fmt)

target_include_directories(processlib
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# create target for main binary
add_executable(main src/main.cpp)
target_compile_features(main PUBLIC cxx_std_17)
target_link_libraries(main PRIVATE processlib fmt::fmt Poco::Foundation)

# create target for test, enable testing, and register a test "RunAllTests"
add_executable(run_tests tests/tests.cpp)
target_compile_features(run_tests PUBLIC cxx_std_17)
target_link_libraries(run_tests PRIVATE processlib Catch2::Catch2)

enable_testing()
add_test(RunAllTests run_tests)

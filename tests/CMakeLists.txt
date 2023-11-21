cmake_minimum_required(VERSION 3.14)
project(logs)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()

add_executable(
  echo_tests

  core/reply_to_listener_test.cpp

  ../include/safe_memory.h
  ../lib/safe_memory.o

  ../src/core/listener/listener.h
  ../src/core/listener/listener.c

  mock/unit/test_mock.c
  mock/unit/test_mock.h
)
target_link_libraries(
  echo_tests
  GTest::gtest_main
)

target_include_directories(echo_tests PRIVATE ../include)
target_include_directories(echo_tests PRIVATE ../src/core/listener)
target_include_directories(echo_tests PRIVATE mock/unit)

include(GoogleTest)
gtest_discover_tests(echo_tests)
# Testing

# Fetching external Google Test Library
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)


enable_testing()

add_executable(
  testsSudoku
  testsMain.cpp
)

target_link_libraries(
  testsSudoku
  PRIVATE
  GTest::gtest_main
  Field
  Solver
)

include(GoogleTest)
gtest_discover_tests(testsSudoku)

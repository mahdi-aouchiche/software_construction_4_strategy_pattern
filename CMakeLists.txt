cmake_minimum_required(VERSION 3.0.0)
project(CS100_Lab4 VERSION 4.0.0)

add_subdirectory(${CMAKE_BINARY_DIR}/../googletest)

set(CMAKE_CXX_STANDARD 11)

# Composit pattern
add_executable(composite_tests
    ../src/lab3_unit_tests.cpp
)
add_executable(composite_pattern
    src/main_lab3.cpp
)

# Strategy pattern
add_executable(strategy_tests
    ../src/lab4_unit_tests.cpp
)
add_executable(strategy_pattern
    src/main_lab4.cpp
    src/container.cpp
)

target_link_libraries(composite_tests gtest)
target_link_libraries(strategy_tests gtest)

target_compile_definitions(composite_tests PRIVATE gtest_disable_pthreads=ON)
target_compile_definitions(strategy_tests PRIVATE gtest_disable_pthreads=ON)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
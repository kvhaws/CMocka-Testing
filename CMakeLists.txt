cmake_minimum_required(VERSION 3.10)

project(MyUnitTestProject)

# Add your executable
add_executable(test_example test_example.c)
add_executable(test_file test_file.c)

# Include directories for the target
target_include_directories(test_example PRIVATE "C:/Program Files (x86)/cmocka/include")
target_include_directories(test_file PRIVATE "C:/Program Files (x86)/cmocka/include")

# Locate cmocka
find_package(cmocka REQUIRED)

# Link against cmocka
target_link_libraries(test_example PRIVATE "C:/Program Files (x86)/cmocka/lib/cmocka.lib")
target_link_libraries(test_file PRIVATE "C:/Program Files (x86)/cmocka/lib/cmocka.lib")

# Configuring GCC compilations
if (CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    find_library(CMOCKA_LIB NAMES cmocka PATHS /usr/local/lib)
    set(GCC_COVERAGE_COMPILE_FLAGS "-fprofile-arcs -ftest-coverage")
    set(GCC_COVERAGE_LINK_FLAGS "-lgcov")
    set(GCC_WARNING_COMPILE_FLAGS "-W -Wall")

    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_WARNING_COMPILE_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS} ${GCC_THREADS_FLAGS} -pthread")
    
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_WARNING_COMPILE_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS} ${GCC_THREADS_FLAGS} -pthread")

    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS} -Wl,--wrap=world")
    
endif (CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)

cmake_print_variables(CMOCKA_HOME)
cmake_print_variables(CMAKE_SOURCE_DIR)

# Enable testing
enable_testing()

# Register the test
add_test(NAME test_example COMMAND test_example)
add_test(NAME test_example2 COMMAND test_file)

cmake_minimum_required(VERSION 3.23) 

enable_testing()

set(CMAKE_CXX_COMPILER "g++")

project(S21Matrix)

set(CMAKE_CXX_STANDARD 17)

find_package(PkgConfig)
pkg_check_modules(GTEST REQUIRED gtest)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)

file(GLOB TEST_SOURCES CONFIGURE_DEPENDS "test/*.h" "test/*.cpp")
file(GLOB SOURCES CONFIGURE_DEPENDS "*.h" "*.cpp")
set(GCOV_TEST_SOURCES ${TEST_SOURCES})

set(GCOV_EXE mtest_gcov)
set(TEST_EXE apptest)
set(MATRIX_LIB s21_matrix_oop)
set(TEST_MATRIX_LIB s21_matrix_oop_test)

add_library(${MATRIX_LIB} STATIC ${SOURCES})
add_library(${TEST_MATRIX_LIB} STATIC ${SOURCES})

add_executable(${TEST_EXE} ${TEST_SOURCES})
add_executable(${GCOV_EXE} ${TEST_SOURCES})

set_source_files_properties(${SOURCES} PROPERTIES COMPILE_FLAGS "-g")
set_target_properties(${TEST_MATRIX_LIB} PROPERTIES COMPILE_FLAGS "-g -O0 -ftest-coverage -fprofile-arcs")
set_target_properties(${GCOV_EXE} PROPERTIES LINK_FLAGS "-g -O0 -ftest-coverage -fprofile-arcs")
set_target_properties(${GCOV_EXE} PROPERTIES LINK_FLAGS " -ftest-coverage -fprofile-arcs")

target_link_libraries(${TEST_EXE} ${MATRIX_LIB} GTest::gtest_main)
target_link_libraries(${GCOV_EXE} ${TEST_MATRIX_LIB} GTest::gtest_main)

gtest_discover_tests(${TEST_EXE})

add_custom_target(gcov_report
	DEPENDS ${GCOV_EXE}	
	COMMAND ./${GCOV_EXE}
	COMMAND grcov . --branch --guess-directory-when-missing --parallel -b mtest_gcov -t html -s ../src/
)
add_custom_target(open 
	COMMAND open html/index.html
)

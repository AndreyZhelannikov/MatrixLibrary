cmake_minimum_required(VERSION 3.23)  # CMake version check

enable_testing()

project(S21Matrix)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 17)            # Enable c++14 standard0

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

# set(TEST_SOURCES test/test.cpp)

file(GLOB TEST_SOURCES CONFIGURE_DEPENDS "test/*.h" "test/*.cpp")
file(GLOB SOURCES CONFIGURE_DEPENDS "*.h" "*.cpp")
# set(SOURCES eq_matrix.cpp
			# helpers.cpp
			# matrix_constructors.cpp)

add_library(s21_matrix_oop STATIC ${SOURCES})

add_executable(testapp ${TEST_SOURCES})

target_link_libraries(testapp s21_matrix_oop GTest::gtest_main)

gtest_discover_tests(testapp)


# target_link_libraries(test ${GTEST_LIBRARIES})
# target_include_directories(test PUBLIC ${GTEST_INCLUDE_DIRS})
# target_compile_options(test PUBLIC ${GTEST_CFLAGS_OTHER})

cmake_minimum_required(VERSION 3.22)

project(boilerplate_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# directories
include_directories(src)
include_directories(include)
include(GNUInstallDirs)


set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

file(GLOB_RECURSE SRC src/*.cpp)

list(REMOVE_ITEM SRC "src/main.cpp")

file(GLOB_RECURSE INCLUDE include/*.h)

add_library(core ${INCLUDE} ${SRC})

add_executable(boilerplate_build src/main.cpp)

target_link_libraries(boilerplate_build core)

enable_testing()

file(GLOB_RECURSE TEST test/*.cpp)

add_executable(tests ${TEST})

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

target_link_libraries(tests GTest::gtest_main)
target_link_libraries(tests core)

add_test(NAME test_core COMMAND $<TARGET_FILE:tests>)

include(GoogleTest)
gtest_discover_tests(tests)

cmake_minimum_required(VERSION 3.26 FATAL_ERROR)

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
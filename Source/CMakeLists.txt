# Specify the minimum version required
cmake_minimum_required(VERSION 3.28)

# See https://cmake.org/cmake/help/latest/policy/CMP0135.html. Needed for GTest inclusion
cmake_policy(SET CMP0135 NEW)

# Declare and name the project and its version
project(DataStructuresAndAlgorithms VERSION 1.0)

# Define the C++ standard version meant to be used by this project
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define additional compiler flags
set(ADDITIONAL_COMPILER_FLAGS "-GS -Wall -WX -sdl -O2 -MP")

# Append the flags to the corresponding CMake flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${ADDITIONAL_COMPILER_FLAGS}")

# Declare a dependency (on Google Test)
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip

  # Old url from docs https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Hide Google Test and Google Mock projects in Visual Studio Solution Explorer
set_target_properties(gmock gmock_main gtest gtest_main PROPERTIES FOLDER "GoogleTest")

# Declare a CMake config file and turn it into an importable header file
configure_file(DataStructuresAndAlgorithmsConfig.h.in DataStructuresAndAlgorithmsConfig.h)

# Create sub-projects visible in VS's Solution Explorer
add_subdirectory(Algorithms)
add_subdirectory(DataStructures)
add_subdirectory(DataStructuresTests)

set(source_list main.cpp)
# Add the source and header files to be compiled into the project
add_executable(DataStructuresAndAlgorithms ${source_list})
# Creates a "folder-like" structure in VS Solution Explorer
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${source_list})

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT DataStructuresAndAlgorithms)

target_link_libraries(DataStructuresAndAlgorithms
  PUBLIC Algorithms
  PUBLIC DataStructures)

# Add a precompiled header file to this particular project.
# Other projects can define their own files, or reuse this one.
target_precompile_headers(DataStructuresAndAlgorithms
  PUBLIC pch.h
)

# Where to search for 'include' directives
target_include_directories(DataStructuresAndAlgorithms PUBLIC "${PROJECT_BINARY_DIR}")

# Needed for GTest
enable_testing()

include(GoogleTest)

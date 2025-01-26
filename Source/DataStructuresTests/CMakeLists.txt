set(
    source_list
	Queue/QueueTests.cpp
	Utils/LinkedListUtilsTests.cpp
)

add_executable(DataStructuresTests ${source_list})

# Creates a "folder-like" structure in VS Solution Explorer
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${source_list})

target_precompile_headers(DataStructuresTests
  PUBLIC pch_DataStructuresTests.h
)

target_include_directories(DataStructuresTests
	PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}"
	PUBLIC "${CMAKE_SOURCE_DIR}"
	PUBLIC "${CMAKE_SOURCE_DIR}/DataStructures")

target_link_libraries(DataStructuresTests
	PUBLIC DataStructures
	PUBLIC GTest::gtest_main)

include(GoogleTest)

gtest_discover_tests(DataStructuresTests)
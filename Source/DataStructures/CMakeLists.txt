set(
    source_list
	LinkedList/examples.cpp
	LinkedList/examples.h
	LinkedList/SinglyLinkedList.h
)

add_library(DataStructures ${source_list})

# Creates a "folder-like" structure in VS Solution Explorer
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${source_list})

target_precompile_headers(DataStructures
  PUBLIC pch_DataStructures.h
)

target_include_directories(DataStructures
	PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}"
	PUBLIC "${CMAKE_SOURCE_DIR}")

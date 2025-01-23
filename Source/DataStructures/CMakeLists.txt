set(
    source_list
    LinkedList/SinglyLinkedList.cpp
	LinkedList/SinglyLinkedList.h
)

add_library(DataStructures ${source_list})

# Creates a "folder-like" structure in VS Solution Explorer
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${source_list})

target_include_directories(DataStructures INTERFACE
	"${CMAKE_CURRENT_SOURCE_DIR}")

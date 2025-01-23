add_library(DataStructures
	LinkedList/SinglyLinkedList.cpp
	LinkedList/SinglyLinkedList.h)

target_include_directories(DataStructures INTERFACE
	"${CMAKE_CURRENT_SOURCE_DIR}")

set(
    source_list
    TreeTraversal/DepthFirstSearch.cpp
	TreeTraversal/DepthFirstSearch.h
)

add_library(Algorithms ${source_list})

# Creates a "folder-like" structure in VS Solution Explorer
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${source_list})

target_include_directories(Algorithms INTERFACE
	"${CMAKE_CURRENT_SOURCE_DIR}")

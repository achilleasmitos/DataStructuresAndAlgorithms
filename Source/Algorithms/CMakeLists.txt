add_library(Algorithms
	TreeTraversal/DepthFirstSearch.cpp
	TreeTraversal/DepthFirstSearch.h)

target_include_directories(Algorithms INTERFACE
	"${CMAKE_CURRENT_SOURCE_DIR}")

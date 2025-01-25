#include "pch.h"

#include "DataStructuresAndAlgorithmsConfig.h"

#include "DataStructures/LinkedList/examples.h"

int main()
{
	std::cout << "Project version: " << DataStructuresAndAlgorithms_VERSION_MAJOR
			  << "." << DataStructuresAndAlgorithms_VERSION_MINOR << std::endl;

	datastructures::RunSinglyLinkedListExample();
	std::cout << std::endl;
	datastructures::RunDoublyLinkedListExample();

	return 0;
}

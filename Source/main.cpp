#include "pch.h"

#include "DataStructuresAndAlgorithmsConfig.h"

#include "DataStructures/LinkedList/examples.h"
#include "DataStructures/Queue/examples.h"

int main()
{
	std::cout << "Project version: " << DataStructuresAndAlgorithms_VERSION_MAJOR
			  << "." << DataStructuresAndAlgorithms_VERSION_MINOR << std::endl;

	datastructures::RunSinglyLinkedListExample();
	std::cout << std::endl;
	datastructures::RunDoublyLinkedListExample();
	std::cout << std::endl;
	datastructures::RunRangeToSinglyLinkedListExample();
	std::cout << std::endl;
	datastructures::RunRangeToDoublyLinkedListExample();
	std::cout << std::endl;

	datastructures::RunQueueExample();
	std::cout << std::endl;

	return 0;
}

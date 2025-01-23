#include "pch_DataStructures.h"
#include "examples.h"

#include "SinglyLinkedList.h"

namespace datastructures
{

void RunSinglyLinkedListExample()
{
	SinglyLinkedList<int> sll{};

	auto second{std::make_shared<SLListNode<int>>(5)};
	auto first{std::make_shared<SLListNode<int>>(4)};
	auto fourth{std::make_shared<SLListNode<int>>(8)};
	auto third{std::make_shared<SLListNode<int>>(6)};

	first->next = second;
	second->next = third;
	third->next = fourth;

	sll.head = first;

	auto& curr = sll.head;
	std::cout << "Your linked list is: [ ";
	while (curr != nullptr)
	{
		std::cout << curr->value << " ";
		curr = curr->next;
	}
	std::cout << "]" << std::endl;
}

} // namespace datastructures

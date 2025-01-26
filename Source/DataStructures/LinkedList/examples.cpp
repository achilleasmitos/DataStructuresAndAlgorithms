#include "pch_DataStructures.h"
#include "examples.h"

#include "DoublyLinkedList.h"
#include "SinglyLinkedList.h"
#include "Utils/LinkedListUtils.h"

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
	std::cout << "Your singly linked list is: [ ";
	while (curr != nullptr)
	{
		std::cout << curr->value << " ";
		curr = curr->next;
	}
	std::cout << "]" << std::endl;
}

void RunDoublyLinkedListExample()
{
	DoublyLinkedList<int> sll{};

	auto second{std::make_shared<DLListNode<int>>(5)};
	auto first{std::make_shared<DLListNode<int>>(4)};
	auto fourth{std::make_shared<DLListNode<int>>(8)};
	auto third{std::make_shared<DLListNode<int>>(6)};

	first->next = second;
	second->next = third;
	second->prev = first;
	third->next = fourth;
	third->prev = second;
	fourth->prev = third;

	sll.head = first;

	auto& curr = sll.head;
	std::cout << "Your doubly linked list is: [ ";
	while (curr != nullptr)
	{
		std::cout << curr->value << " ";
		curr = curr->next;
	}
	std::cout << "]" << std::endl;

	std::cout << "And it can also be read backwards: [ ";
	curr = fourth;
	while (curr != nullptr)
	{
		std::cout << curr->value << " ";
		curr = curr->prev;
	}
	std::cout << "]" << std::endl;
}

void RunRangeToSinglyLinkedListExample()
{
	std::vector<int> inputVector{1, 2, 3, 4, 5};
	auto sll = RangeToSinglyLinkedList(inputVector);

	auto currNode = sll.head;
	std::cout << "The sllist produced from the vector is: [ ";
	while (currNode != nullptr)
	{
		std::cout << currNode->value << " ";
		currNode = currNode->next;
	}
	std::cout << "]" << std::endl;
}

void RunRangeToDoublyLinkedListExample()
{
	std::vector<int> inputVector{1, 2, 3, 4, 5};
	auto dll = RangeToDoublyLinkedList(inputVector);

	auto currNode = dll.head;
	std::cout << "The dllist produced from the vector is: [ ";
	while (currNode != nullptr)
	{
		std::cout << currNode->value << " ";

		if (currNode->next == nullptr)
		{
			break;
		}
		currNode = currNode->next;
	}
	std::cout << "]" << std::endl;

	std::cout << "Also, read backwards the dllist is: [ ";
	while (currNode != nullptr)
	{
		std::cout << currNode->value << " ";

		currNode = currNode->prev;
	}
	std::cout << "]" << std::endl;
}

} // namespace datastructures

#pragma once

#include <ranges>

#include "LinkedList/DoublyLinkedList.h"
#include "LinkedList/SinglyLinkedList.h"

namespace datastructures
{

#pragma region RangeType concept
template<class I>
concept RangeType = std::ranges::range<I>;

static_assert(RangeType<std::vector<int>>);
static_assert(RangeType<std::vector<std::string>>);
static_assert(!RangeType<std::array<std::string, 4>>); // --> does not accept arrays, end() is not a sentinel
static_assert(RangeType<std::initializer_list<int>>);
static_assert(RangeType<std::initializer_list<std::string>>);
#pragma endregion

template<typename T, RangeType Range>
SinglyLinkedList<T> RangeToSinglyLinkedList(const Range& range)
{
	SinglyLinkedList<T> sll{};
	if (range.begin() == range.end())
	{
		return sll;
	}

	sll.head = std::make_shared<SLListNode<T>>(*range.begin());

	auto currNode = sll.head;
	auto prevNode = sll.head;

	for (auto it = range.begin() + 1; it != range.end(); it++)
	{
		currNode = std::make_shared<SLListNode<T>>(*it);
		prevNode->next = currNode;
		prevNode = currNode;
	}

	return sll;
}

template<typename T, RangeType Range>
DoublyLinkedList<T> RangeToDoublyLinkedList(const Range& range)
{
	DoublyLinkedList<T> dll{};
	if (range.begin() == range.end())
	{
		return dll;
	}

	dll.head = std::make_shared<DLListNode<T>>(*range.begin());

	auto currNode = dll.head;
	auto prevNode = dll.head;

	for (auto it = range.begin() + 1; it != range.end(); it++)
	{
		currNode = std::make_shared<DLListNode<T>>(*it);
		prevNode->next = currNode;
		currNode->prev = prevNode;
		prevNode = currNode;
	}

	return dll;
}

} // namespace datastructures

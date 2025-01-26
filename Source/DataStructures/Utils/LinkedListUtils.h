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

template<RangeType Range>
auto RangeToSinglyLinkedList(const Range& range)
{
	using T = std::ranges::range_value_t<Range>;

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

template<RangeType Range>
auto RangeToDoublyLinkedList(const Range& range)
{
	using T = std::ranges::range_value_t<Range>;

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

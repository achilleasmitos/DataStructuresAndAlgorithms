#include "pch_DataStructuresTests.h"

#include "DataStructures/Utils/LinkedListUtils.h"

using namespace ::testing;
using namespace datastructures;

TEST(RangeToSinglyLinkedListUnitTests, ShouldReturn_EmptyList_When_VectorIsEmpty)
{
	const std::vector<float> testData{};
	auto sll = RangeToSinglyLinkedList(testData);

	EXPECT_EQ(sll.head, nullptr);
}

TEST(RangeToSinglyLinkedListUnitTests, ShouldReturn_ListWithOneElement_When_VectorHasExactlyOneElement)
{
	const std::vector<double> testData{4.21};
	auto sll = RangeToSinglyLinkedList(testData);

	EXPECT_NE(sll.head, nullptr);
	EXPECT_EQ(sll.head->next, nullptr);
	EXPECT_DOUBLE_EQ(sll.head->value, 4.21);
}

TEST(RangeToSinglyLinkedListUnitTests, ShouldReturn_ListWitTheSameElements_When_VectorHasMoreThanOneElement)
{
	const std::vector<int> testData{1, 2, 3, 4, 5, 6};
	auto sll = RangeToSinglyLinkedList(testData);

	auto currNode = sll.head;
	size_t elementsInListCount = 0;
	while (currNode != nullptr)
	{
		EXPECT_EQ(currNode->value, testData[elementsInListCount++]);
		currNode = currNode->next;
	}
	EXPECT_EQ(elementsInListCount, testData.size());
}

TEST(RangeToSinglyLinkedListUnitTests, ShouldAccommodate_InitializerLists)
{
	const std::initializer_list<int> testData{1, 2, 3};
	auto sll = RangeToSinglyLinkedList(testData);

	auto listHead = sll.head;
	EXPECT_EQ(listHead->value, 1);
	EXPECT_EQ(listHead->next->value, 2);
	EXPECT_EQ(listHead->next->next->value, 3);
}

TEST(RangeToDoublyLinkedListUnitTests, ShouldReturn_EmptyList_When_VectorIsEmpty)
{
	const std::vector<float> testData{};
	auto dll = RangeToDoublyLinkedList(testData);

	EXPECT_EQ(dll.head, nullptr);
}

TEST(RangeToDoublyLinkedListUnitTests, ShouldReturn_ListWithOneElement_When_VectorHasExactlyOneElement)
{
	const std::vector<double> testData{4.21};
	auto dll = RangeToDoublyLinkedList(testData);

	EXPECT_NE(dll.head, nullptr);
	EXPECT_EQ(dll.head->next, nullptr);
	EXPECT_DOUBLE_EQ(dll.head->value, 4.21);
}

TEST(RangeToDoublyLinkedListUnitTests, ShouldReturn_ListWitTheSameElements_When_VectorHasMoreThanOneElement)
{
	const std::vector<int> testData{1, 2, 3, 4, 5, 6};
	auto dll = RangeToDoublyLinkedList(testData);

	auto currNode = dll.head;
	for (auto it = testData.cbegin(); it != testData.cend(); it++)
	{
		EXPECT_EQ(currNode->value, *it);
		currNode = currNode->next;
	}
}

TEST(RangeToDoublyLinkedListUnitTests,
	ShouldReturn_ListWitTheSameElements_When_VectorHasMoreThanOneElement_Backwards)
{
	const std::vector<int> testData{1, 2, 3, 4, 5, 6};
	auto dll = RangeToDoublyLinkedList(testData);

	auto currNode = dll.head;
	// Find the tail of list
	while (currNode->next != nullptr)
	{
		currNode = currNode->next;
	}

	for (auto it = testData.crbegin(); it != testData.crend(); it++)
	{
		EXPECT_EQ(currNode->value, *it);
		currNode = currNode->prev;
	}
}

TEST(RangeToDoublyLinkedListUnitTests, ShouldAccommodate_InitializerLists)
{
	const std::initializer_list<int> testData{1, 2, 3};
	auto dll = RangeToDoublyLinkedList(testData);

	auto listHead = dll.head;
	EXPECT_EQ(listHead->value, 1);
	EXPECT_EQ(listHead->next->value, 2);
	EXPECT_EQ(listHead->next->next->value, 3);
}

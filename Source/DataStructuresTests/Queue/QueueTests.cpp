#include "pch_DataStructuresTests.h"

#include "DataStructures/Queue/Queue.h"

using namespace ::testing;
using namespace datastructures;

TEST(QueueUnitTests, Peek_ShouldThrowRangeError_When_NoElementsHaveBeenEnqueued)
{
	const Queue<int> sut{};

	const auto shouldThrow = [&sut]()
	{ [[maybe_unused]] auto element = sut.Peek(); };

	EXPECT_THROW(shouldThrow(), std::range_error);
}

TEST(QueueUnitTests, Peek_ShouldThrowRangeError_When_TheSameNumberOfElementsHaveBeenEnqueuedAndDequeued)
{
	Queue<int> sut{};

	const auto shouldThrow = [&sut]()
	{ [[maybe_unused]] auto element = sut.Peek(); };

	const int testDataToEnqueue{5};
	const int testOtherDataToEnqueue{6};

	// Enqueue one, dequeue one
	sut.Enqueue(testDataToEnqueue);
	sut.Dequeue();
	EXPECT_THROW(shouldThrow(), std::range_error);

	// Enqueue two consecutively, dequeue two consecutively
	sut.Enqueue(testDataToEnqueue);
	sut.Enqueue(testOtherDataToEnqueue);
	sut.Dequeue();
	sut.Dequeue();
	EXPECT_THROW(shouldThrow(), std::range_error);

	// Same number of elements enqueued and dequeued, mixed order
	sut.Enqueue(testDataToEnqueue);
	sut.Dequeue();
	sut.Enqueue(testOtherDataToEnqueue);
	sut.Dequeue();
	EXPECT_THROW(shouldThrow(), std::range_error);
}

TEST(QueueUnitTests, Peek_ShouldAlwaysReturnTheFirstElement_When_AtLeastOneElementHasBeenEnqueuedAndNoneDequeued)
{
	Queue<int> sut{};

	const int testDataToEnqueue{5};
	const int testOtherDataToEnqueue{6};

	sut.Enqueue(testDataToEnqueue);
	EXPECT_EQ(sut.Peek(), testDataToEnqueue);

	sut.Enqueue(testOtherDataToEnqueue);
	EXPECT_EQ(sut.Peek(), testDataToEnqueue);
}

TEST(QueueUnitTests, Peek_ShouldReturnTheFirstElementNotDequeued_When_AtLeastTwoElementsHaveBeenEnqueuedAndFewerDequeued)
{
	Queue<int> sut{};

	const int testDataToEnqueue{5};
	const int testOtherDataToEnqueue{6};

	sut.Enqueue(testDataToEnqueue);
	sut.Enqueue(testOtherDataToEnqueue);
	sut.Dequeue();
	EXPECT_EQ(sut.Peek(), testOtherDataToEnqueue);
}

TEST(QueueUnitTests, Dequeue_ShouldThrowRangeError_When_NoElementsHaveBeenEnqueued)
{
	Queue<int> sut{};

	const auto shouldThrow = [&sut]() { sut.Dequeue(); };

	EXPECT_THROW(shouldThrow(), std::range_error);
}

TEST(QueueUnitTests, Dequeue_ShouldThrowRangeError_When_TheSameNumberOfElementsHaveBeenEnqueuedAndDequeued)
{
	Queue<int> sut{};

	const auto shouldThrow = [&sut]() { sut.Dequeue(); };

	const int testDataToEnqueue{5};
	const int testOtherDataToEnqueue{6};

	// Enqueue one, dequeue one
	sut.Enqueue(testDataToEnqueue);
	sut.Dequeue();
	EXPECT_THROW(shouldThrow(), std::range_error);

	// Enqueue two consecutively, dequeue two consecutively
	sut.Enqueue(testDataToEnqueue);
	sut.Enqueue(testOtherDataToEnqueue);
	sut.Dequeue();
	sut.Dequeue();
	EXPECT_THROW(shouldThrow(), std::range_error);

	// Same number of elements enqueued and dequeued, mixed order
	sut.Enqueue(testDataToEnqueue);
	sut.Dequeue();
	sut.Enqueue(testOtherDataToEnqueue);
	sut.Dequeue();
	EXPECT_THROW(shouldThrow(), std::range_error);
}

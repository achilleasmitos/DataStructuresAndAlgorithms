#include "pch_DataStructures.h"

#include "examples.h"

#include "Queue.h"

namespace datastructures
{

void RunQueueExample()
{
	Queue<std::string> queue{};

#pragma region Error handling for reading from an empty queue
	try
	{
		auto element = queue.Peek();
		std::cout << element << std::endl;
	}
	catch (const std::range_error& ex)
	{
		std::cout
			<< "Tried to peek into an empty queue. Encountered exception: "
			<< ex.what() << std::endl;
	}
	catch (const std::exception& ex)
	{
		std::cout << "Unexpected exception while reading from queue: " << ex.what()
				  << std::endl;
	}
	catch (...)
	{
		std::cout << "Unknown error while reading from queue." << std::endl;
		return;
	}
#pragma endregion

	queue.Enqueue("Achilleas");
	std::cout << "Enqueued 'Achilleas', peeking gives: " << queue.Peek() << std::endl;
	queue.Enqueue("Mariliza");
	std::cout << "Enqueued 'Mariliza', peeking gives: " << queue.Peek() << std::endl;
	queue.Enqueue("Mom");
	std::cout << "Enqueued 'Mom'" << std::endl;
	queue.Enqueue("Dad");
	std::cout << "Enqueued 'Dad'" << std::endl;

	std::cout << "Dequeueing " << queue.Dequeue() << "..." << std::endl;
	std::cout << "Dequeueing " << queue.Dequeue() << "..." << std::endl;
	std::cout << "Peeking now gives: " << queue.Peek() << std::endl;
	std::cout << "Dequeueing " << queue.Dequeue() << "..." << std::endl;
	std::cout << "Dequeueing " << queue.Dequeue() << "..." << std::endl;

#pragma region Error handling for dequeueing from an empty queue
	try
	{
		std::cout << "Dequeueing " << queue.Dequeue() << "..." << std::endl;
	}
	catch (const std::range_error& ex)
	{
		std::cout
			<< "Tried to dequeue from an empty queue. Encountered exception: "
			<< ex.what() << std::endl;
	}
	catch (const std::exception& ex)
	{
		std::cout << "Unexpected exception while dequeueing from queue: " << ex.what()
				  << std::endl;
	}
	catch (...)
	{
		std::cout << "Unknown error while dequeueing from queue." << std::endl;
		return;
	}
#pragma endregion
}

} // namespace datastructures

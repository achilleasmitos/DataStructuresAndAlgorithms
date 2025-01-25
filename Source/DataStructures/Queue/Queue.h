#pragma once

#include "pch_DataStructures.h"

#include "LinkedList/SinglyLinkedList.h"

namespace datastructures
{

/// @brief A queue is a linear FIFO data structure with three basic operations:
/// Peek, that returns the value of the next element to be processed;
/// Enqueue, that adds a new element to the end of the queue
/// Dequeue, that removes an element from the front of the queue.
/// @tparam T The value type of the elements in the queue.
template<typename T>
class Queue
{
public:
	/// @brief  Peeks the very next element to be removed, without actually removing it.
	/// @throws std::range_error If the queue has no elements in it
	/// @return The element to be dequeued, if one exists
	[[nodiscard]] T Peek() const
	{
		if (!HasElement())
		{
			throw std::range_error("Queue does not contain any elements!");
		}

		return m_impl.head->value;
	}

	/// @brief Adds an element to the back of the queue.
	/// The element will be processed after all elements before it
	/// have been processed.
	/// @param[in] element The element to be added
	void Enqueue(T element)
	{
		auto newNode = std::make_shared<SLListNode<T>>(element);

		if (!HasElement())
		{
			m_impl.head = newNode;
			return;
		}

		auto curr = m_impl.head;
		while (curr->next != nullptr)
		{
			curr = curr->next;
		}

		curr->next = newNode;
	}

	/// @brief Removes the first element from the queue. The very next element
	/// now becomes the first (next one to be removed).
	/// @throws std::range_error If the queue has no elements in it
	/// @return The element that was removed, if the operation completed successfully
	T Dequeue()
	{
		if (!HasElement())
		{
			throw new std::range_error("Queue does not contain any elements!");
		}

		auto dequeuedElement = m_impl.head->value;
		m_impl.head = m_impl.head->next;

		return dequeuedElement;
	}

private:
	bool HasElement() const { return m_impl.head != nullptr; }

	/// @brief The internal implementation for this queue.
	/// Other implementations might include a doubly linked list
	/// with a pointer to the last node, for ease of dequeue operations,
	/// or an array for queues of fixed length.
	SinglyLinkedList<T> m_impl{};
};

} // namespace datastructures

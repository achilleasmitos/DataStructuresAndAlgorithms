#pragma once

namespace datastructures
{
#pragma warning(push)
#pragma warning(disable : 4820) // Depending on the value of TValue here, a padding error may appear in VS compiler
/// <summary>
/// This represents a node in a doubly linked list.
/// It contains a value as well as a pointer to its next element and a pointer to its previous element (nullptr by default).
/// </summary>
/// <typeparam name="TValue">The value stored in the node, for example 'int' or 'std::string'</typeparam>
template<typename TValue>
struct DLListNode
{
	TValue value;
	std::shared_ptr<DLListNode> next{nullptr};
	std::shared_ptr<DLListNode> prev{nullptr};
};
#pragma warning(pop)

/// <summary>
/// A doubly linked list is the most common alternative type of a linked list (after a singly linked list).
/// Each of its nodes points forward to the next node and backwards to its previous element.
///
/// The list is just a wrapper around its first (head) node. This can be a nullptr,
/// indicating an empty list.
/// A node that forward-points to nullptr is considered to be the last node of the list.
/// </summary>
/// <typeparam name="TValue">The value stored in each of the list's nodes.</typeparam>
template<typename TValue>
struct DoublyLinkedList
{
	std::shared_ptr<DLListNode<TValue>> head{nullptr};
};

} // namespace datastructures

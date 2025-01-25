#pragma once

namespace datastructures
{
#pragma warning(push)
#pragma warning(disable : 4820) // Depending on the value of TValue here, a padding error may appear in VS compiler
/// @brief This represents a node in a singly linked list.
/// It contains a value as well as a pointer to its next element (nullptr by default).
/// @tparam TValue The value stored in the node, for example 'int' or 'std::string'
template<typename TValue>
struct SLListNode
{
	TValue value;
	std::shared_ptr<SLListNode> next{nullptr};
};
#pragma warning(pop)

/// @brief A singly linked list is the most common type of a linked list.
/// Each of its nodes only points forward to the next node.
///
/// The list is just a wrapper around its first (head) node. This can be a nullptr,
/// indicating an empty list.
/// A node that points to nullptr is considered to be the last node of the list.
/// @tparam TValue The value stored in each of the list's nodes.
template<typename TValue>
struct SinglyLinkedList
{
	std::shared_ptr<SLListNode<TValue>> head{nullptr};
};

} // namespace datastructures

# Linked Lists

_Sources:_ [Wikipedia article](https://en.wikipedia.org/wiki/Linked_list)

### Summary

A linked list is a linear collection of data elements whose order is not given by their physical placement in memory. Instead, each element points to the next. It is a data structure consisting of a collection of nodes which together represent a sequence. In its most basic form, each node contains data, and a reference (in other words, a link) to the next node in the sequence.
More complex variants add additional links, allowing more efficient insertion or removal of nodes at arbitrary positions.

Linked lists are among the simplest and most common data structures. They can be used to **implement** several other common abstract data types, including **lists, stacks, queues, associative arrays, and S-expressions**.

A **node** is an element in the list. It usually contains one member variable holding the "_value_" of that node, as well as one or several "_links_" to other elements in the list (see [Types of Linked Lists](#types-of-linked-lists) below).<br>
The **head** of the linked list refers to the very first element in the list, the one used to start iterations from. A linked list can also be identified by its head only.<br>
The last element in the list is a node that does not point to any other nodes in the list, and is usually called the _tail_ of the list (though this term is also used for the body of the list that excludes the head).

### Advantages:
- Simple in concept and implementation
- Storage-efficient (since they don't require a contiguous block of memory, like arrays for example)
- Insertions and removals are instant (while traversing the list, needs element before/after in the list for the operation)

### Disadvantages:
- Do not allow for random access, like arrays do (access time is linear on the number of nodes in the list)
- Do not allow for indexing, and efficient search algorithms (like sorted arrays do)
- Not as good cache locality as traditional arrays

## Types of Linked Lists

**Singly Linked List:** Singly linked lists contain nodes which have a 'value' field as well as 'next' field, which points to the next node in line of nodes. Operations that can be performed on singly linked lists include insertion, deletion and traversal.

**Doubly Linked List:** In a 'doubly linked list', each node contains, besides the next-node link, a second link field pointing to the 'previous' node in the sequence. The two links may be called 'forwards' and 'backwards', or 'next' and 'prev'.

**Multiply Linked List:** Each node contains references to more than two elements in the list.

**Circular Linked List:** In a circular linked list, the tail (last node) of the list contains a link to the first element in the list.

**Centinel Nodes:** In some implementations an extra 'sentinel' or 'dummy' node may be added before the first data record or after the last one. This convention simplifies and accelerates some list-handling algorithms, by ensuring that all links can be safely dereferenced and that every list (even one that contains no data elements) always has a "first" and "last" node. 

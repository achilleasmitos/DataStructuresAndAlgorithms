# Queues

_Sources:_ [Wikipedia article](https://en.wikipedia.org/wiki/Queue_(abstract_data_type))

### Summary

A queue is a collection of entities that are maintained in a sequence and can be modified by the addition of entities at one end of the sequence and the removal of entities from the other end of the sequence. By convention, the end of the sequence at which elements are added is called the back, tail, or rear of the queue, and the end at which elements are removed is called the head or front of the queue.

The operations of a queue make it a **first-in-first-out** (FIFO) data structure. This is equivalent to the requirement that once a new element is added, all elements that were added before have to be removed before the new element can be removed. A queue is an example of a linear data structure, or more abstractly a sequential collection.

## Operations

The operation of adding an element to the rear of the queue is known as **_enqueue_**, and the operation of removing an element from the front is known as **_dequeue_**. Other operations may also be allowed, often including a **_peek_** or front operation that returns the value of the next element to be dequeued without dequeuing it.

### Implementation

One common implementation for queues is the use of linked lists. Doubly linked lists that also contain a pointer to the last element are especially easy to stand-in for a queue. Other structures, such as arrays, may also be used, but they come with costs in efficiency (especially since most arrays are of a fixed size, contrary to most queues).

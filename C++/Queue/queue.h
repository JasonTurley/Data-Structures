#ifndef QUEUE_H_
#define QUEUE_H_

#include <cstddef>


/**
 * Implementation of a queue as a non-expanding array (circular buffer).
 */
template <class T>
class Queue {
public:
	/**
	 * Default constructor.
	 */
	explicit Queue(size_t capacity);

	/**
	 * Destructor
	 */
	~Queue();

	/**
	 * Returns the number of elements in the queue.
	 */
	size_t size() const;

	/**
	 * Returns the max number of elements the queue can hold.
	 */
	size_t capacity() const;

	/**
	 * Returns true if the queue if full, false otherwise.
	 */
	bool full() const;

	/**
	 * Returns true if the list is empty, false otherwise.
	 */
	bool empty() const;

	/**
	 * Returns the item at the front of the queue, without removing it.
	 */
	const T front() const;

	/**
	 * Returns the item at the end of the queue, without removing it.
	 */
	const T back() const;

	/**
	 * Appends an item to the queue, if it is not already full.
	 */
	void enqueue(const T& data);

	/**
	 * Removes and returns the item at the front of the queue.
	 */
	const T dequeue();

private:
	/**
	 * The container of elements.
	 */
	T *buffer;

	/**
	 * Tracks the beginning of the queue.
	 */
	int head;

	/**
	 * Tracks the end of the queue.
	 */
	int tail;

	/**
	 * How many elements are in the queue.
	 */
	size_t currentSize;

	/**
	 * The maximum number of elements the queue can store.
	 */
	size_t maxCapacity;
};

#endif

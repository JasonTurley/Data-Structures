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
	 * Copy constructor.
	 */
	Queue(const Queue& oldQ);

	/**
	 * Overloaded operator=.
	 */
	Queue& operator=(const Queue& oldQ);

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
	const T& front() const;

	/**
	 * Returns the item at the end of the queue, without removing it.
	 */
	const T& back() const;

	/**
	 * Returns true if able to append an item to the end of the queue,
	 * otherwise returns false.
	 */
	bool enqueue(const T& data);

	/**
	 * Removes and returns the item at the front of the queue.
	 */
	const T& dequeue();

private:
	/**
	 * The container of elements.
	 */
	T *m_buffer;

	/**
	 * Tracks the beginning of the queue.
	 */
	int m_front;

	/**
	 * Tracks the end of the queue.
	 */
	int m_back;

	/**
	 * How many elements are in the queue.
	 */
	size_t m_size;

	/**
	 * The maximum number of elements the queue can store.
	 */
	size_t m_capacity;

	/**
	 * Helper function that performs a deep copy of the provided Queue
	 * object.
	 */
	 void copy(const Queue& oldQ);
};

#endif

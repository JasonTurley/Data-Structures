#include <iostream>

#include "queue.h"

template <class T>
Queue<T>::Queue(size_t n)
{
    buffer = new T[n];
	front = 0;
	back = -1;
	size = 0;
	capacity = n;
}

template <class T>
Queue<T>::Queue(const Queue& oldQ)
{
	copy(oldQ);
}

template <class T>
Queue<T>& Queue<T>::operator=(const Queue& other)
{
	// Avoid self assignment
	if (this != &other) {
		if (capacity != other.capacity)
			delete[]  buffer; // free previous storage

		copy(other);
	}

	return *this;
}

template <class T>
Queue<T>::~Queue()
{
    delete [] buffer;
}

template <class T>
size_t Queue<T>::getSize() const
{
    return size;
}

template <class T>
size_t Queue<T>::getCapacity() const
{
    return capacity;
}

template <class T>
bool Queue<T>::full() const
{
    return size == capacity;
}

template <class T>
bool Queue<T>::empty() const
{
    return size == 0;
}

template <class T>
const T& Queue<T>::getFront() const
{
    return buffer[front];
}

template <class T>
const T& Queue<T>::getBack() const
{
    return buffer[back];
}

template <class T>
bool Queue<T>::enqueue(const T& data)
{
	if (full())
		return false;

	back++;
	size++;

	// Handle wrap around for circular buffer
	if (back == (int) capacity)
	    back = 0;

	buffer[back] = data;

	return true;
}

template <class T>
const T& Queue<T>::dequeue()
{
	if (empty()) {
		std::cerr << "Cannot pop from empty queue.\n";
		exit(1);
	}

	// Handle wrap around for circular buffer
	if (front == (int) capacity)
		front = 0;

	const T& retval = buffer[ front];
	front++;
	size--;

	return retval;
}

template <class T>
void Queue<T>::copy(const Queue& other)
{
	// Copy member variables
	size = other.size;
	capacity = other.capacity;
	front = other.front;
	back = other.back;
	buffer = new T [capacity];

	// Copy queue data
	int i = size;
	int j = front;

	while (i) {
		buffer[j % capacity] = other.buffer[j % capacity];
		j++;
		i--;
	}
}

// Avoid linking errors
template class Queue<int>;

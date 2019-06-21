#include <iostream>

#include "queue.h"

template <class T>
Queue<T>::Queue(size_t capacity)
{
	m_buffer = new T[capacity];
	m_front = 0;
	m_back = -1;
	m_size = 0;
	m_capacity = capacity;
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
		if (m_capacity != other.m_capacity)
			delete[] m_buffer; // free previous storage

		copy(other);
	}

	return *this;
}

template <class T>
Queue<T>::~Queue()
{
        delete [] m_buffer;
}

template <class T>
size_t Queue<T>::size() const
{
        return m_size;
}

template <class T>
size_t Queue<T>::capacity() const
{
        return m_capacity;
}

template <class T>
bool Queue<T>::full() const
{
        return m_size == m_capacity;
}

template <class T>
bool Queue<T>::empty() const
{
        return m_size == 0;
}

template <class T>
const T& Queue<T>::front() const
{
        return m_buffer[m_front];
}

template <class T>
const T& Queue<T>::back() const
{
        return m_buffer[m_back];
}

template <class T>
bool Queue<T>::enqueue(const T& data)
{
	if (full())
		return false;

	m_back++;
	m_size++;

	// Handle wrap around for circular buffer
	if (m_back == (int) m_capacity)
		m_back = 0;

	m_buffer[m_back] = data;

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
	if (m_front == (int) m_capacity)
		m_front = 0;

	const T& retval = m_buffer[m_front];
	m_front++;
	m_size--;

	return retval;
}

template <class T>
void Queue<T>::copy(const Queue& other)
{
	// Copy member variables
	m_size = other.m_size;
	m_capacity = other.m_capacity;
	m_front = other.m_front;
	m_back = other.m_back;
	m_buffer = new T [m_capacity];

	// Copy queue data
	int i = m_size;
	int j = m_front;

	while (i) {
		m_buffer[j % m_capacity] = other.m_buffer[j % m_capacity];
		j++;
		i--;
	}
}

// Avoid linking errors
template class Queue<int>;

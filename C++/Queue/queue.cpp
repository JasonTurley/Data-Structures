

#include "queue.h"

template <class T>
Queue<T>::Queue(size_t capacity)
{
	buffer = new T[capacity];
	head = 0;
	tail = -1;
	currentSize = 0;
	maxCapacity = capacity;
}

template <class T>
Queue<T>::~Queue()
{
        delete [] buffer;
}

template <class T>
size_t Queue<T>::size() const
{
        return currentSize;
}

template <class T>
size_t Queue<T>::capacity() const
{
        return maxCapacity;
}

template <class T>
bool Queue<T>::full() const
{
        return currentSize == maxCapacity;
}

template <class T>
bool Queue<T>::empty() const
{
        return currentSize == 0;
}

template <class T>
const T Queue<T>::front() const
{
        return buffer[head % maxCapacity];
}

template <class T>
const T Queue<T>::back() const
{
        return buffer[tail % maxCapacity];
}

template <class T>
void Queue<T>::enqueue(const T& data)
{
        if (!full()) {
                buffer[++tail % maxCapacity] = data;
                currentSize++;
        }
}

template <class T>
const T Queue<T>::dequeue()
{
        if (!empty()) {
                return buffer[head++ % maxCapacity];
        }

        return T();
}


// Avoid linking errors
template class Queue<int>;

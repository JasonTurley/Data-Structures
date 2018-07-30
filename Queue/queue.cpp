/**
 * @file queue.cpp
 *
 * @author Jason Turley
 * @date (created) 27 July 2018
 */
#include <climits>      // INT_MIN
#include "queue.h"

template <class T>
Queue<T>::Queue()
    : front(nullptr), end(nullptr), length(0)
{ /* nothing */ }

template <class T>
Queue<T>::~Queue()
{
    // delete the linked list
    destroyList(&front);
}

template <class T>
void Queue<T>::enqueue(const T& data)
{
    Node *node = new Node(data);

    if (end == nullptr) {
        front = end = node;
    } else {
        end->next = node;
        end = node;
    }

    this->length++;
}

template <class T>
T Queue<T>::dequeue() 
{
    // Either zero or one nodes left
    if (front == end) {
        end = nullptr;
    }

    T ret;

    if (front) {
        ret = front->data;
        Node* to_delete = front;
        front = front->next;
        delete(to_delete);

        this->length--;
    }

    return ret;
}

template <class T>
int Queue<T>::size() const 
{
    return this->length;
}

template <class T>
T Queue<T>::getFront() const
{
    if (front) 
        return front->data;
    return INT_MIN;
}

template <class T>
bool Queue<T>::isEmpty() const
{
    return (front == nullptr && end == nullptr && length == 0);
}

// Helper for Destructor
template <class T>
void Queue<T>::destroyList(Node** head_ref)
{
    while (*head_ref) {
        Node* to_delete = *head_ref;
        *head_ref = to_delete->next;
        to_delete->next = nullptr;
        delete(to_delete);
    }

    if (*head_ref)
        *head_ref = nullptr;
}

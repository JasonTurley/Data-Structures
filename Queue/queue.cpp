/**
 * @file queue.cpp
 *
 * @author Jason Turley
 * @date (created) 27 July 2018
 */
#include <climits>      // INT_MIN
#include "queue.h"


Queue::Queue()
    : front(nullptr), end(nullptr), length(0)
{ /* nothing */ }

Queue::~Queue()
{
    // delete the linked list
    destroyList(&front);
}

void Queue::enqueue(const int data)
{
    Node *node = new Node(data);

    if (front == nullptr)
        front = node;
    if (end == nullptr) {
        end = node;
    } else {
        end->next = node;
        end = node;
    }

    this->length++;
}

int Queue::dequeue() 
{
    int ret = INT_MIN;

    // Case were last node is removed
    if (front == end) {
        end = nullptr;
    }

    if (front) {
        ret = front->data;
        Node* to_delete = front;
        front = front->next;
        delete(to_delete);
    }


    this->length--;
    return ret;
}

int Queue::size() const 
{
    return this->length;
}

int Queue::getFront() const
{
    if (front) 
        return front->data;
    return INT_MIN;
}

bool Queue::isEmpty() const
{
    return (front == nullptr && end == nullptr && length == 0);
}

// Helper for Destructor
void Queue::destroyList(Node** head_ref)
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

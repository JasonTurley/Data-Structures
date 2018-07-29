/**
 * @file queue.cpp
 *
 * @author Jason Turley
 * @date (created) 27 July 2018
 */
#include "queue.h"

//using namespace std;

/**
 * Default Queue Constructor
 */
Queue::Queue()
    : front(nullptr), end(nullptr), length(0)
{ /* nothing */ }

/**
 * Inserts data to end of queue
 */
void Queue::enqueue(const int data) {
    Node *node = new Node(data);

    if (front == nullptr)
        front = node;
    if (end == nullptr) {
        end = node;
    } else {
        node->next = end;
        end = node;
    }

    this->length++;
}

/**
 * Removes node from front of queue and returns its data
 */
int Queue::dequeue() const {
    // TODO: finish
    if (end) {
        int ret = end->data;

    }
    return 0;
}

/**
 * Returns the queue's size
 */
int Queue::size() const {
    return this->length;
}

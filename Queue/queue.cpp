/**
 * @file queue.cpp
 *
 * @author Jason Turley
 * @date (created) 27 July 2018
 */
#include <climits>      // INT_MIN
#include "queue.h"

using namespace std;

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
 * Removes node from front of queue and returns its data. If The
 * list is empty, returns INT_MIN
 */
int Queue::dequeue() {
    int ret = INT_MIN;

    if (front) {
        ret = front->data;
        Node* to_delete = front;
        front = front->next;
        delete(to_delete);
    }

    return ret;
}

/**
 * Returns the queue's size
 */
int Queue::size() const {
    return this->length;
}

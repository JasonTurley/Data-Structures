/**
 * @file queue.cpp
 *
 * @author Jason Turley
 * @date (created) 27 July 2018
 */
#include <climits>      // INT_MIN
#include "queue.h"

using namespace std;

// Default Queue Constructor
Queue::Queue()
    : front(nullptr), end(nullptr), length(0)
{ /* nothing */ }

// Queue Destructor
Queue::~Queue()
{
    // delete the linked list
    destroyList(&front);
}

// Inserts data to end of queue
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

// Removes node from front of queue and returns its data. Returns INT_MIN if queue is empty
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

// Returns the queue's size
int Queue::size() const {
    return this->length;
}

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

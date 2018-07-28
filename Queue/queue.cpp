/**
 * @file queue.cpp
 *
 * @author Jason Turley
 * @date (created) 27 July 2018
 */

using namespace std;

template <class T>
Queue::Queue()
    : front(NULL), rear(NULL), length(0)
{ /* nothing */ }

template <class T>
void Queue::enqueue(const T& data)
{
    Node node = new Node(data);

    if (front == NULL)
        front = node;
    if (rear == NULL) {
        rear = node;
    } else {
        node->next = rear;
        rear = node;
    }
}

template <class T>
T Queue::dequeue() const
{
    if (rear) {
        T ret = rear->data;
        
    }
}

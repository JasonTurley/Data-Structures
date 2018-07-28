/**
 * @file queue.h
 *
 * @author Jason Turley
 * @date (created) 27 July 2018
 */
#ifndef QUEUE_H
#define QUEUE_H

using namespace std;

/**
 * Queue: This is a templated queue class (meaning it contains data
 * of templated type T, which is a placeholder for a type).
 *
 * The queue is implemented as a singly-linked list of nodes
 */
template <class T>
class Queue {
private:
    /**
    * The Node class is private within class Queue due to the
    * principle of encapsulation -- the user does not need to
    * know how our queue is implemented.
    */
    template <class T>
    class Node {
    public:
        /**
        * The data contained in this Node.
        */
        T data;

        /**
        * Pointer to the next Node in the list. May be nullptr
        */
        Node* next;
    };

public:

    /**
     * Default Queue constructor.
     * Creates an empty Queue.
     */
    Queue();

    /**
     * Inserts a new node at the end of the Queue.
     *
     * @param data The data to be inserted
     */
    void enqueue(const T& data);

    /**
     * Removes the first Node pushed onto the Queue, decreasing its size by 1.
     *
     * @return The data contained inside the Node
     */
    T dequeue() const;

    /**
     * Gets the size of the Queue.
     * Marked const because it promises not to alter the Node in any way.
     *
     * @ return The size of the Queue
     */
    int size() const;

private:
    /**
     * Pointer to the beginning of the queue.
     */
    Queue* front;

    /**
     * Pointer to the end of the queue.
     */
    Queue* rear;

    /**
     * The current size of the queue.
     */
    int length;
};

#endif

/**
 * @file queue.h
 *
 * @author Jason Turley
 * @date (created) 27 July 2018
 */
#ifndef QUEUE_H
#define QUEUE_H

/**
 * Queue: This is a templated queue class (meaning it contains data
 * of templated type T, which is a placeholder for a type).
 *
 * The queue is implemented as a singly-linked list of nodes
 */
class Queue {
private:
    /**
    * The Node class is private within class Queue due to the
    * principle of encapsulation -- the user does not need to
    * know how our queue is implemented.
    */
    class Node {
    public:
        /**
         * Node constructor.
         *
         * @param ndata The data to be added to the Node
         */
        Node(const int ndata)
            : data(ndata), next(nullptr)
        { /* nothing */ }

        /**
        * The data contained in this Node.
        */
        int data;

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
     * Destructor deletes all allocated Nodes
     */
    ~Queue();

    /**
     * Inserts a new node at the end of the Queue.
     *
     * @param data The data to be inserted
     */
    void enqueue(const int data);

    /**
     * Removes the first node pushed onto the Queue, decreasing its size by 1.
     *
     * @return The data contained inside the Node
     */
    int dequeue();

    /**
     * Gets the size of the Queue.
     * Marked const because it promises not to alter the node in any way.
     *
     * @return The size of the Queue
     */
    int size() const;

    /**
     * Returns the the data held inside the front of the queue, without removing the node.
     *
     * @return The first node's data
     */
    int getFront() const;

private:
    /**
     * Pointer to the beginning of the queue.
     */
    Node* front;

    /**
     * Pointer to the end of the queue.
     */
    Node* end;

    /**
     * The current size of the queue.
     */
    int length;

    /**
     * Destroys every node in the linked list.
     */
    void destroyList(Node** head_ref);
};

#endif

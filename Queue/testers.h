/**
 * @file testers.cpp - test cases for the queue class
 *
 * @author Jason Turley
 * @date (created) 29 July 2018
 */
#ifndef TESTERS_H
#define TESTERS_H


#include <cassert>
#include "queue.h"

/* TODO:
    test push, pop, size, copying, destroying
 */


Queue* createQueue()
{
    Queue* q = new Queue();
    return q;
}

void destroyQueue(Queue* &queue)
{
    assert(queue);
    delete(queue);
    queue = nullptr;
}


Queue* test_queue = createQueue();

/**
 * Test that queue has no initial size
 */
void test1()
{
    assert(test_queue->size() == 0);
}

void test2()
{
    for (int i = 0; i < 5; i++)
        test_queue->enqueue(i);
    assert(test_queue->size() == 5);
}

#endif

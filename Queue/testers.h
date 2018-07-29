/**
 * @file testers.cpp - test cases for the queue class
 *
 * @author Jason Turley
 * @date (created) 29 July 2018
 */
#ifndef TESTERS_H
#define TESTERS_H

#include <cassert>
#include <climits>
#include "queue.h"

/* TODO:
    test push, pop, size, copying, destroying
 */

// Verrify that queue has no initial size
void test1()
{
    Queue test_queue;
    assert(test_queue.size() == 0);
}

// Verify that enqueue() correctly updates size
void test2()
{
    Queue test_queue;
    for (int i = 0; i < 5; i++)
        test_queue.enqueue(i);
    assert(test_queue.size() == 5);
}

// Verify that dequeue() removes correct nodes in the right order
void test3()
{
    Queue test_queue;
    int x;

    for (int i = 0; i < 5; i++)
        test_queue.enqueue(i);

    for (int i = 0; i < 5; i++) {
        x = test_queue.dequeue();
        assert(x == i);
    }

    assert(test_queue.size() == 0);
}

// Verify getFront() works
void test4()
{
    Queue test_queue;
    int x;
    const int data = 10;

    x = test_queue.getFront();      // should return INT_MIN since no enqueue happened
    assert(x == INT_MIN);

    test_queue.enqueue(data);
    x = test_queue.getFront();
    assert(x == data);
}

#endif

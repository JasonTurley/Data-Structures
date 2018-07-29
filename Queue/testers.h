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

// Verrify that queue has no initial size
void test1()
{
    Queue test_queue;
    assert(test_queue.size() == 0);
}

// Verify that enqueue() works
void test2()
{
    Queue test_queue;
    for (int i = 0; i < 5; i++)
        test_queue.enqueue(i);
    assert(test_queue.size() == 5);
}

#endif

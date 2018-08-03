/**
 * @file heap.cpp
 * Implementation of a binary heap
 */
#include <cmath>        // floor
#include <limits.h>     // INT_MIN
#include <algorithm>    // swap
#include <iostream>
#include "heap.h"

using namespace std;

Heap::Heap()
{
    length = 0;
}

size_t Heap::parent(size_t currIdx) const
{
    return floor((length - 1) / 2);
}

size_t Heap::leftChild(size_t currIdx) const
{
    return (2 * currIdx) + 1;
}

size_t Heap::rightChild(size_t currIdx) const
{
    return (2 * currIdx) + 2;
}


bool Heap::hasChild(size_t currIdx) const
{
    // A parent will always have at least a left child
    return (leftChild(currIdx) < elements.size());
}

size_t Heap::minChild(size_t currIdx) const
{
    if (hasChild(currIdx)) {
        return min(leftChild(currIdx), rightChild(currIdx));
    }

    return 0;
}

int Heap::getMin() const
{
    if (length)
        return elements[0];
    return INT_MIN;
}

void Heap::insert(const int& value)
{
    elements.push_back(value);
    size_t pIdx = parent(length);

    if (value < elements[pIdx])
        heapifyUp(length);

    length++;
}

int Heap::remove()
{
    int retval = elements[0];       // save the root element
   
    length--;
    std::swap(elements[0], elements[length]);
    heapifyDown(0);                 // restore heap property

    return retval;
}

void Heap::heapifyUp(size_t currIdx) 
{
    if (currIdx == 0)
        return;

    size_t pIdx = floor ((currIdx - 1) / 2);

    if (elements[currIdx] < elements[pIdx]) {
        std::swap(elements[currIdx], elements[pIdx]);
        
        currIdx = pIdx;
        heapifyUp(currIdx);
    }

    return;
}

void Heap::heapifyDown(size_t currIdx)
{
    size_t pIdx = currIdx;
    currIdx = minChild(pIdx);

    // If there is a child less than the parent
    if (currIdx != 0 && elements[pIdx] > elements[currIdx]) {
        std::swap(elements[currIdx], elements[pIdx]);
        pIdx = currIdx;
        heapifyDown(pIdx);
    }
    
    return;
}

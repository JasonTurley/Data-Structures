/**
 *
 *
 */
#include <cmath>        // floor
#include "heap.h"


int Heap::getMin() const
{
    if (size)
        return elements[0];
    return INT_MIN;
}

void Heap::insert(int value) const
{
    elements[size] = value;
    size_t pIndex = floor (size - 1 / 2);

    if (value < elements[pIndex])
        heapifyUp(size);

    size++;
}

void Heap::heapifyUp(size_t cIndex)
{
    if (cIndex == 0)
        return;

    pIndex = floor (cIndex - 1 / 2);

    if (elements[cIndex] < elements[pIndex]) {
        swap(elements[cIndex], elements[pIndex]);
        
        cIndex = pIndex;
        heapifyUp(cIndex);
    }

    return;
}

void Heap::swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

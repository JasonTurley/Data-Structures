/**
 *
 *
 */
#include <iostream>
#include <cmath>        // floor
#include <limits.h>     // INT_MIN
#include "heap.h"

using namespace std;

Heap::Heap()
{
    length = 0;
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
<<<<<<< HEAD
    length++;
    size_t pIndex = floor ((length - 1) / 2);
=======
    size_t pIndex = 0;
    
    // Avoid getting a negative index
    if (length)
        pIndex = floor ((length - 1) / 2);
>>>>>>> d99b53e6251a571bf28fa9c07e61bc801df1ad01

    cout << "length: " << length << endl;
    cout << "pIndex: " << pIndex << endl;
    cout << "elems[" << pIndex << "]: " << elements[pIndex] << endl;
    if (value < elements[pIndex])
        heapifyUp(length);

}

void Heap::heapifyUp(size_t cIndex) 
{
    if (cIndex == 0)
        return;

    size_t pIndex = floor ((cIndex - 1) / 2);

    cout << "cIndex: " << cIndex << endl;
    cout << "pIndex: " << pIndex << endl;

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

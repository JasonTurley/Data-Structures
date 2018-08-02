/**
 *
 *
 *
 */
#include <iostream>
#include <assert.h>
#include "heap.h"

using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    Heap heap;

    heap.insert(4);
    heap.insert(2);

    cout << "Testing min!\n";
    
    int x = heap.getMin();
    cout << "min: " << x << endl;

    assert(x == 2);

    return 0;
}

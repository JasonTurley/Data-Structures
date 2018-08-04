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

void testInsertBasic(Heap*& heap)
{
    heap->insert(4);
    heap->insert(2);
    heap->insert(5);

    assert(heap->root() == 2);
    assert(heap->size() == 3);
}

void testRemoveBasic(Heap*& heap)
{
    int retval = heap->remove();
    
    assert(retval == 2);
    assert(heap->root() == 4);
    assert(heap->size() == 2);
}

int main(int argc, char *argv[])
{
    Heap* heap = new Heap();
    
    testInsertBasic(heap);
    testRemoveBasic(heap);

    return 0;
}

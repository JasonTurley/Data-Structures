#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "heap.h"

void test_insert(struct max_heap *heap)
{
	int a[] = {7, 2, 8, 1};
	size_t size = sizeof(a) / sizeof(a[0]);

	for (size_t i = 0; i < size; i++)
		insert(heap, a[i]);

	assert(check_max(heap) == 8);
	assert(heap->size == size);
}

void test_all(struct max_heap *heap)
{
	test_insert(heap);
}

int main()
{
	struct max_heap *heap = create_heap(4);
	test_insert(heap);
	print_heap(heap);
	destroy_heap(heap);

	return 0;
}

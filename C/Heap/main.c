#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "heap.h"

// TODO add better test cases

int main()
{
	int arr[] = {50, 100, 70, 40, 10, 90};
	size_t sz = sizeof(arr) / sizeof(arr[0]);

	struct max_heap *heap = create_heap(sz);

	for (size_t i = 0; i < sz; i++)
		insert(heap, arr[i]);

	assert(heap->size == sz);
	print_heap(heap);

	int x = extract_max(heap);
	assert(x == 100);

	print_heap(heap);
	assert(heap->size == sz-1);

	destroy_heap(heap);

	struct max_heap *heap2 = heapify(arr, sz);

	print_heap(heap2);

	destroy_heap(heap2);

	return 0;
}

/**
 * Implementation of a max heap data structure.
 */
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "heap.h"

static void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * insert() helper function used to restore heap propery.
 *
 * Utilizes tail-recursion so the compiler does not have to push subsequent calls onto the call-stack.
 */
static void sift_up(struct max_heap *heap, int data, int index)
{
	if (index == 0 || data < heap->array[parent(index)])
		return;

	swap(&heap->array[index], &heap->array[parent(index)]);

	sift_up(heap, data, parent(index));
}

struct max_heap *create_heap(size_t capacity)
{
	struct max_heap *heap = malloc(sizeof(heap));
	assert(heap);

	heap->array = malloc(sizeof(int) * capacity);
	assert(heap->array);

	heap->capacity = capacity;
	heap->size = 0;

	return heap;
}

void insert(struct max_heap *heap, int data)
{
	if (heap->size == heap->capacity) {
		fprintf(stderr, "Cannot insert data, heap is full!");
		return;
	}

	heap->array[heap->size] = data;
	sift_up(heap, data, heap->size);
	heap->size++;
}

void destroy_heap(struct max_heap *heap)
{
	if (heap) {
		free(heap->array);
		heap->array = NULL;
		free(heap);
		heap = NULL;
	}
}

void print_heap(struct max_heap *heap)
{
	for (size_t i = 0; i < heap->size; i++)
		printf("%d ", heap->array[i]);
	printf("\n");
}

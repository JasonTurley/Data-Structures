/**
 * Implementation of a max heap data structure.
 */
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "heap.h"

/**
 * Helper functions
 */
static void swap(int *x, int *y);
static void sift_up(struct max_heap *heap, int data, size_t index);
static void sift_down(struct max_heap *heap, size_t index);
static size_t  max_child_index(struct max_heap *heap, size_t index);

struct max_heap *create_heap(size_t capacity)
{
	struct max_heap *heap = malloc(sizeof(heap));
	assert(heap);

	heap->array = malloc(sizeof(size_t) * capacity);
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

int  extract_max(struct max_heap *heap)
{
	size_t retval = check_max(heap);

	/**
	 * Swap root with last element, then restore the heap property.
	 */
	swap(&heap->array[0], &heap->array[--heap->size]);
	sift_down(heap, 0);

	return retval;
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

static void swap(int *x, int *y)
{
	size_t temp = *x;
	*x = *y;
	*y = temp;
}

static void sift_up(struct max_heap *heap, int data, size_t index)
{
	if (index == 0 || data < heap->array[parent(index)])
		return;

	swap(&heap->array[index], &heap->array[parent(index)]);

	sift_up(heap, data, parent(index));
}

static void sift_down(struct max_heap *heap, size_t index)
{
	/* Current node has no children - stop recursion. */
	if (index >= (heap->size / 2) - 1)
		return;

	size_t child = max_child_index(heap, index);

	if (heap->array[index] < heap->array[child])
		swap(&heap->array[index], &heap->array[child]);

	sift_down(heap, child);
}

static size_t max_child_index(struct max_heap *heap, size_t index)
{
	if (heap->array[left_child(index)] > heap->array[right_child(index)])
		return left_child(index);
	else
		return right_child(index);
}

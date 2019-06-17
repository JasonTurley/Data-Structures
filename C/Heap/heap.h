/**
 * Declaration of a max heap data structure.
 *
 * check_max/check_min - O(1), simply return root index.
 * extract_max/extract_min - O(logN) when sifting data down the tree to restore heap property.
 * insert - O(logN) when sifting data up the tree to restore heap property.
 * delete - O(logN).
 */

#ifndef HEAP_H
#define HEAP_H

struct max_heap {
	int *array;
	size_t capacity;
	size_t size;
};

#define parent(idx) ((idx-1) / 2)
#define left_child(idx) ((idx * 2) + 1)
#define right_child(idx) ((idx * 2) + 2)

#define check_max(heap) (heap->array[0])
#define is_empty(heap) (heap->size == 0)

/**
 * Creates a heap that can hold `capacity` elements.
 */
struct max_heap *create_heap(size_t capacity);

/**
 * Inserts data into the heap. After insertion, calls sift_up() to restore heap property, if necessary.
 */
void insert(struct max_heap *heap, int data);

/**
 * Returns and removes the max element in the heap. After removal, calls sift_down() to restore heap property, if
 * necessary.
 */
int extract_max(struct max_heap *heap);

/**
 * Destroys the provided heap.
 */
void destroy_heap(struct max_heap *heap);

/**
 * Creates a max heap from an unsorted array.
 */
struct max_heap *heapify(int *arr, size_t size);

/**
 * Prints contents of the heap.
 */
void print_heap(struct max_heap *heap);

#endif // HEAP_H

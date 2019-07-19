#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "vector.h"

/**
 * Error checked wrapper for malloc.
 */
void *xmalloc(size_t size)
{
	void *ptr = malloc(size);
	if (!ptr) {
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	return ptr;
}

/**
 * Resizes the given vectors internal container.
 *
 * Declared static since it is a 'private' function.
 */
static void resize(struct vector *v)
{
	v->capacity *= 2;
	int *new_array = xmalloc(sizeof(int) * v->capacity);

	// Copy elements from old array to new array
	for (size_t i = 0; i < v->size; i++)
		*(new_array + i) = *(v->array + i);

	free(v->array);
	v->array = new_array;
}

void print_vector(struct vector *v)
{
	for (size_t i = 0; i < v->size; i++)
		printf("%d ", *(v->array + i));

	printf("\n");
}

struct vector *vector_create(size_t capacity)
{
    struct vector *v;

	if (capacity < MIN_CAPACITY)
		capacity = MIN_CAPACITY;

	// TODO round capacity to power of 2
	v = xmalloc(sizeof(struct vector));
	v->array = xmalloc(sizeof(int) * capacity);
    v->size = 0;
    v->capacity = capacity;

    return v;
}

void vector_destroy(struct vector *v)
{
	free(v->array);
	free(v);
}

size_t size(struct vector *v)
{
	return v->size;
}

size_t capacity(struct vector *v)
{
	return v->capacity;
}

bool is_empty(struct vector *v)
{
	return (v->size == 0);
}

int at(struct vector *v, size_t index)
{
	if (index > v->size) {
		fprintf(stderr, "at: index out of bounds\n");
		exit(EXIT_FAILURE);
	}

	return *(v->array + index);
}

int front(struct vector *v)
{
	return at(v, 0);
}

int back(struct vector *v)
{
	return at(v, v->size-1);
}

void push_back(struct vector *v, int elem)
{
	if (v->size == v->capacity)
		resize(v);

	*(v->array + v->size) = elem;
	v->size++;
}

void insert(struct vector *v, int elem, size_t index)
{
	if (v->size == v->capacity)
		resize(v);

	// Shift elements to the right
	for (size_t i = v->size; i > index; i--)
		*(v->array + i) = *(v->array + i - 1);

	// Insert element
	*(v->array + index) = elem;
	v->size++;
}

int pop_back(struct vector *v)
{
	if (is_empty(v)) {
		fprintf(stderr, "vector is empty!\n");
		exit(EXIT_FAILURE);
	}

	v->size--;
	return *(v->array + v->size);
}

void remove_elem(struct vector *v, int elem)
{
	size_t write_index = 0;

	for (size_t i = 0; i < v->size; i++) {
		// Write all but the target elem to array
		if (*(v->array + i) != elem)
			*(v->array + write_index++) = *(v->array + i);
	}

	// update new size
	v->size = write_index;
}

int find(struct vector *v, int elem)
{
	for (size_t i = 0; i < v->size; i++) {
		if (*(v->array + i) == elem)
			return i;
	}

	return -1;
}

/**
 * A C style implementation of std::vector.
 *
 * Modified on 3/12/19 by Jason Turley.
 */
#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <stdbool.h>
#include <stdlib.h>

/**
 * Used to set the capacity of the vector in vector_create()
 */
#define MIN_CAPACITY 16

/**
 * How much the vector will grow by in automatic allocation (2 means double).
 */
#define GROWTH_FACTOR 2

struct vector {
	int *array;			// Container of elements
	size_t size;		// The number of elements in the vector
	size_t capacity;	// The max number of elements the vector can hold
};

/**
 * Prints all elems in a given vector.
 */
void print_vector(struct vector *v);

/**
 * Returns a pointer to a newly created, empty vector.
 *
 */
struct vector *vector_create(size_t capacity);

/**
 * Destroys all container elements of the vector.
 */
void vector_destroy(struct vector *v);

/**
 * Returns the current number of elements in the vector. Note, this is not
 * necessarily equal to its capacity.
 */
static inline size_t size(struct vector *v)
{
    return v->size;
}

/**
 * Returns the number of elems this vector can hold.
 */
static inline size_t capacity(struct vector *v)
{
    return v->capacity;
}

/**
 * Checks if the current vector is empty.
 */
static inline bool is_empty(struct vector *v)
{
    return (v->size == 0);
}

/**
 * Returns the elem at a given index.
 */
int at(struct vector *v, size_t index);

/**
 * Returns the element at the front of the vector.
 */
int front(struct vector *v);

/**
 * Returns the element at the back of the vector.
 */
int back(struct vector *v);

/**
 * Adds a new element to the end of the vector, increasing its size
 * by one.
 *
 * This automatically resizes the container if necessary.
 */
void push_back(struct vector *v, int elem);

/**
 * Inserts the given element at the specified index.
 */
void insert(struct vector *v, int elem, size_t index);

/**
 * Removes and returns the last element in the vector, reducing its size by one.
 */
int pop_back(struct vector *v);

/**
 * Removes all occurrences of an elem.
 */
void remove_elem(struct vector *v, int elem);

/**
 * Searches for a value and returns the first index with that value,
 * -1 if not found.
 */
int find(struct vector *v, int elem);

#endif

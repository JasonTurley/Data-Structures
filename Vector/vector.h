/**
 * A C style implementation of std::vector.
 */
#pragma once
#include <stdbool.h>
#include <stdlib.h>

/* Forward declare vector structure. */
typedef struct vector {
    void **array;       /* container */ 
    size_t nelems;      /* current container size */
    size_t capacity;    /* max container size */
} vector;

/**
 * Used to set the capacity of the vector in vector_create()
 */
#define INITIAL_CAPACITY 8

/**
 * How much the vector will grow by in automatic allocation (2 means double).
 */
#define GROWTH_FACTOR 2

// Member Functions:

/**
 * Returns a pointer to a newly created, empty vector.
 *
 */
vector *vector_create();

/**
 * Destroys all container elements of the vector.
 */
void vector_destroy(vector *vec);

// Iterators:

// Capacity:

/**
 * Returns the current number of elements in the vector. Note, this is not
 * necessarily equal to its capacity.
 */
size_t vector_size(vector *vec);



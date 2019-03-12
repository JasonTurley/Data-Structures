#include <assert.h>
#include <stdlib.h>

#include "vector.h"
#include "utils.h"

struct vector {
	int *array;		/* Item container */
	size_t size;		/* Number of items in array */
	size_t capacity;	/* Max items array can hold */
};

static void resize(struct vector *vec)
{
	// TODO implement
	vec->size += 0; // added to stop compiler errors
}

struct vector *vector_create(size_t capacity)
{
    	struct vector *v; 
	
	if (capacity < MIN_CAPACITY)
		capacity = MIN_CAPACITY;

	// TODO round capacity to power of 2
	v = safe_malloc(sizeof(struct vector));
    	v->array = safe_malloc(sizeof(int) * capacity);
    	v->size = 0;
    	v->capacity = capacity;

    	return v;
}

size_t size(struct vector *vec)
{
	return vec->size;
}

size_t capacity(struct vector *vec)
{
	return vec->capacity;
}

void push(struct vector *vec, int item)
{
	if (vec->size + 1 > vec->capacity)
		resize(vec);

	*(vec->array + vec->size) = item;
	vec->size++;
}



#include <assert.h>
#include <stdlib.h>

#include "vector.h"
#include "utils.h"

/**
 * Resizes the given vectors internal container.
 *
 * Declared static since it is a 'private' function.
 */
static void resize(struct vector *vec)
{
	int *new_array;
	size_t i;

	vec->capacity *= 2;
	new_array = malloc(sizeof(int) * vec->capacity);
	// TODO make into function
	if (!new_array) {
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	/* copy elements */
	for (i = 0; i < vec->size; i++)
		*(new_array + i) = *(vec->array + i);

	free(vec->array);
	vec->array = new_array;
}

static void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;

}

void print_vector(struct vector *vec)
{
	size_t i;

	for (i = 0; i < vec->size; i++)
		printf("%d ", *(vec->array + i));

	printf("\n");
}

/**
 * 
 */
static void check_index(struct vector *vec, size_t index)
{
	if (index > vec->size) {
		fprintf(stderr, "index %zd out of bounds.\n", index);
		exit(EXIT_FAILURE);
	}
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

void vector_destroy(struct vector *vec)
{
	free(vec->array);
	free(vec);
}

size_t size(struct vector *vec)
{
	return vec->size;
}

size_t capacity(struct vector *vec)
{
	return vec->capacity;
}

bool is_empty(struct vector *vec)
{
	return (vec->size == 0);
}

int at(struct vector *vec, size_t index)
{
	int ret;

	check_index(vec, index);
	ret = *(vec->array + index);

	return ret;
}

void push(struct vector *vec, int item)
{
	if (vec->size + 1 > vec->capacity)
		resize(vec);

	*(vec->array + vec->size) = item;
	vec->size++;
}

void insert(struct vector *vec, size_t index, int item)
{
	if (vec->size + 1 > vec->capacity)
		resize(vec);

	size_t end = vec->size;

	while (end > index) {

		swap(&(*(vec->array + end)), &(*(vec->array + (end-1))));
		end--;
	}

	*(vec->array + index) = item;
	vec->size++;
}

int find(struct vector *vec, int item)
{
	// Is there a way to get better than O(n) for unsorted array?
	int *ptr;
	size_t i;

	for (i = 0; i < vec->size; i++) {
		ptr = vec->array + i;
		if (*ptr == item) {
			printf("Found item at index %zd.\n", i);
			return i;
		}
	}

	return -1;	// not found
}

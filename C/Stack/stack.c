/*
 * @author jason
 * @date 10/21/18
 *
 * Implementation of a stack elem structure.
 */

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#include "stack.h"

static void *xmalloc(size_t size)
{
	void *ptr = malloc(size);

	if (!ptr) {
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	return ptr;
}

stack_t *stack_create(uint32_t max_size)
{
    stack_t *s = xmalloc(sizeof(stack_t));
    s->size = 0;
    s->capacity = max_size;
    s->elements = xmalloc(sizeof(stack_t) * max_size);

    return s;
}

void push(stack_t *s, int elem)
{
    assert(s);

    if (s->size > s->capacity) {
		fprintf(stderr, "stack overflow on pushing %d\n", elem);
		exit(EXIT_FAILURE);
	}

    s->elements[s->size++] = elem;
}

int pop(stack_t *s)
{
    assert(s);

    if (is_empty(s)) {
        fprintf (stderr, "Stack underflow\n");
		exit(EXIT_FAILURE);
    }

    return s->elements[--s->size];;
}

int peek(stack_t *s)
{
    assert(s);

    return s->elements[s->size - 1];
}

uint32_t get_size(stack_t *s)
{
    assert(s);

    return(s->size);
}

bool is_empty(stack_t *s)
{
    assert(s);

    return s->size == 0;
}

void stack_destroy(stack_t *s)
{
	assert(s);

    free(s->elements);
    free(s);
}

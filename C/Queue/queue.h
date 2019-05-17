/*
 * Implementation of a queue.
 *
 * @date: 16 May 2019
 */

#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdlib.h>

#include "liblist/liblist.h"

typedef struct _queue_t {
	list_t *container;
	size_t size;
} queue_t;

/**
 * Creates a new queue on the heap.
 */
queue_t *create_queue();

/**
 * Destroys an allocated queue.
 */
void destroy_queue(queue_t *queue);

/**
 * Adds an element to the end of the queue.
 */
void enqueue(queue_t *queue, void *data);

/**
 * Removes an element from the front of the queue, and returns its value.
 */
void *dequeue(queue_t *queue);

/**
 * Returns the value at the head of the queue.
 */
void *peek(queue_t *queue);

#endif

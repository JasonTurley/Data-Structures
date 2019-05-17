#include <stdlib.h>

#include "queue.h"
#include "list.h"

queue_t *create_queue()
{
	queue_t *q = malloc(sizeof(queue_t));
	if (q == NULL) {
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	q->container = create_list();

	return q;
}

void enqueue(queue_t *queue, void *data)
{
	push_back(queue->container, data);
}

void *dequeue(queue_t *queue)
{
	return pop_front(queue->container);
}

void destroy_queue(queue_t *queue)
{
	destroy_list(queue->container);
	free(queue);
}

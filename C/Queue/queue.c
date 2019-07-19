#include <stdlib.h>

#include "queue.h"
#include "liblist/liblist.h"

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

void enqueue(queue_t *q, void *data)
{
	push_back(q->container, data);
}

void *dequeue(queue_t *q)
{
	return pop_front(q->container);
}

void destroy_queue(queue_t *q)
{
	destroy_list(q->container);
	free(q);
}

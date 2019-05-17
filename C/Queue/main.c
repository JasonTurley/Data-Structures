#include <stdlib.h>
#include <stdio.h>

#include "queue.h"

int main()
{
	queue_t *q = create_queue();
	short x = 12;
	enqueue(q, &x);
	destroy_queue(q);

	return 0;
}

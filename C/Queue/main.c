#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "queue.h"

#define N (16)

int *create_test_int_array(size_t size)
{
	int *arr = malloc(sizeof(int) * size);

	if (!arr) {
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	for (size_t i = 0; i < size; i++)
		arr[i] = i;

	return arr;
}

void test_enqueue()
{
	queue_t *q = create_queue();
	int *a = create_test_int_array(N);

	for (int i = 0; i < N; i++)
		enqueue(q, &(a[i]));

	for (int i = 0; i < N; i++) {
		int ret = *((int *)dequeue(q));
		printf("%d ", ret);
	}

	printf("\n");
	free(a);
	destroy_queue(q);
}
void test_all()
{
	test_enqueue();
}

int main()
{
	test_all();

	return 0;
}

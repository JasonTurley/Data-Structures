/**
 * main.c - Test functions. "echo $?" should return 0.
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "list.h"

#define N 10

int strcmp(const char *s1, const char *s2);

void test_push_front()
{
	list_t *list = create_list();

	int a[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

	for (int i = 0; i < N; i++)
		push_front(list, a + i);

	assert(list->head);
	assert(list->tail);
	assert(size(list) == N);

	for (int i = 0; i < N; i++) {
		int *x = pop_back(list);
		assert(x == a + i);
	}

	assert(size(list) == 0);
	assert(!list->head);
	assert(!list->tail);
}

void test_extract()
{
	list_t *list = create_list();

	for (int i = 0; i < N; i++)
		push_back(list, &i);

	int *ip = extract(list, 4);

	printf("%d", *ip);

	destroy_list(list);
}

void test_all()
{
	test_push_front();
	test_extract();
}

int main()
{
	test_all();

	return 0;
}

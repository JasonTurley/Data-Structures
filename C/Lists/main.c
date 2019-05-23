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

void test_push_front(list_t *list)
{
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

void test_push_back();

void test_empty(list_t *list)
{
	assert(empty(list));
}

void test_insert(list_t *list)
{
	// push arbitrary data 
	for (int i = 0; i < N; i++)
		push_back(list, &i);

	insert(list, "test insert", 4);
	
	assert(size(list) == N + 1);
	char *testdata = get(list, 4);

	int ret = strcmp(testdata, "test insert");

	assert(ret == 0);
}

int main()
{
	list_t *mylist = create_list();
	
	test_empty(mylist);
	test_push_front(mylist);
	test_insert(mylist);
	destroy_list(mylist);

	return 0;
}

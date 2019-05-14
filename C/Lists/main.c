#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "list.h"

#define N 10

struct node *head = NULL;
struct node *tail = NULL;

void test_push_front()
{
	int i;
	
	for (i = 0; i < N; i++)
		push_front(i+1);
	
	assert(size() == N);
	assert(head != NULL);
	assert(tail != NULL);
}

void test_destroy_list()
{
	destroy_list();
	assert(head == NULL);
	assert(tail == NULL);
}

/* 
 * Test link list functions
 */
int main(int argc, char **argv)
{
	test_push_front();
	test_destroy_list();

	return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "list.h"

#define N 10

struct node *head = NULL;
struct node *tail = NULL;

void test_push_front(list_t *list)
{
	for (int i = 0; i < N; i++) {
		push_front(list, &i);
	}

	assert(size(list) == N);
}

/* 
 * Test link list functions
 */
int main()
{
	list_t *mylist = create_list();

	test_push_front(mylist);

	return 0;
}

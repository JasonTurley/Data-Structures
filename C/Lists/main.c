#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "list.h"

#define N 10

struct node *head = NULL;
struct node *tail = NULL;

char *str = "abcdefghijklmnopqrstuvwxyz";

void test1(list_t *list)
{
	for (int i = 0; i < N; i++) 
		push_front(list, str + i);

	assert(size(list) == N);

	for (int i = N; i > 0; i--) {
		char *x = pop_front(list);
		assert(x == str + (i-1));
	}

	assert(size(list) == 0);
}

/* 
 * Test link list functions
 */
int main()
{
	list_t *mylist = create_list();
	
	test1(mylist);

	destroy_list(mylist);

	return 0;
}

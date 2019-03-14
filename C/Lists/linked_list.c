#include <stdlib.h>
#include <stdio.h>

#include "linked_list.h"

// NOTE: implement head ptr first, then tail later.

// TODO put in separate utility file
static void check_address(void *addr)
{
	if (addr == NULL) {
		fprintf(stderr, "Error in allocating memory.\n");
		exit(EXIT_FAILURE);
	}
}

/** 
 * Returns a new node with given value
 */
static struct node *create_node(int value)
{
	struct node *ret = malloc(sizeof(struct node));
	check_address(ret);

	ret->data = value;
	ret->next = NULL;

	return ret;
}

struct linked_list *create_list()
{
	struct linked_list *ll = malloc(sizeof(struct linked_list));
	check_address(ll);

	ll->head = ll->tail = NULL;
	ll->size = 0;

	return ll;
}

void destroy_list(struct linked_list *list)
{
	struct node *ptr = list->head;

	while (ptr != NULL) {
		list->head = ptr->next;
		free(ptr);
		ptr = list->head;
	}
	
	free(list);
}

size_t size(struct linked_list *list)
{
	return list->size;
}

void push_front(struct linked_list *list, int value)
{
	struct node *new = create_node(value);

	/* Is this the first insertion into the list? */
	if (list->head == NULL) {
		list->head = new;
	} else {
		struct node *tmp = list->head;
		list->head = new;
		list->head->next = tmp;
	}

	list->size++;
}

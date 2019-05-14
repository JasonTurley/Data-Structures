#include <stdlib.h>
#include <stdio.h>

#include "list.h"

extern struct node *head;
extern struct node *tail;

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
	ret->prev = NULL;
	ret->next = NULL;

	return ret;
}

void push_front(int value)
{
	struct node *tmp = create_node(value);

	if (!head && !tail) {
		tail = tmp;
	} else {
		tmp->next = head;
		head->prev = tmp;
	}

	head = tmp;
}

void push_back(int value)
{
	struct node *tmp = create_node(value);

	if (!head && !tail) {
		head = tmp;
	} else {
		tmp->prev = tail;
		tail->next = tmp;
	}

	tail = tmp;
}

int size()
{
	struct node *ptr = head;
	int count = 0;

	while (ptr) {
		ptr = ptr->next;
		count++;
	}

	return count;
}

void destroy_list()
{
	struct node *ptr = head;

	while (ptr) {
		head = ptr->next;
		free(ptr);
		ptr = head;
	}

	head = NULL;
	tail = NULL;
}
		
void print_list()
{
	struct node *ptr = head;

	while (ptr) {
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}

	printf("\n");
}

#include <stdlib.h>
#include <stdio.h>

#include "list.h"

static void check_address(void *addr)
{
	if (addr == NULL) {
		fprintf(stderr, "Error in allocating memory.\n");
		exit(EXIT_FAILURE);
	}
}

list_t *create_list()
{
	list_t *list = malloc(sizeof(list_t));
	check_address((list_t *) list);

	list->head = NULL;
	list->tail = NULL;
	list->size = 0;

	return list;
}

void push_front(list_t *list, void *value)
{
	node *newnode = malloc(sizeof(node));
	check_address(newnode);

	newnode->data = value;

	if (empty(list)) {
		list->tail = newnode;
	} else {
		newnode->next = list->head;
		list->head->prev = newnode;
	}

	list->head = newnode;
	list->size++;

	printf("debug: added %d to list\n", (*(int *)list->head->data));
}

void push_back(list_t *list, void *value)
{
	node *newnode = malloc(sizeof(node));
	check_address(newnode);

	newnode->data = value;

	if (empty(list)) {
		list->head = newnode;
	} else {
		newnode->prev = list->tail;
		list->tail->next = newnode;
	}

	list->tail = newnode;
	list->size++;
}

void *pop_front(list_t *list)
{
	return NULL;
}

bool empty(list_t *list)
{
	return (list->head == NULL && list->tail == NULL);
}

int size(list_t *list)
{
	return list->size;
}

void destroy_list()
{
}
		
void print_list(list_t *list)
{
	node *head = list->head;

	while (head) {
		printf("%d ", (*(int *)head->data));
		head = head->next;
	}

	printf("\n");
}

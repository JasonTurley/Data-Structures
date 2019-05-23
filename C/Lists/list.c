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
	node *ret = list->head;
	void *retval = NULL;

	if (empty(list))
		return retval;

	if (list->head == list->tail) {
		// only one node in list
		list->head = NULL;
		list->tail = NULL;
	} else {
		list->head = ret->next;
		list->head->prev = NULL;
		ret->next = NULL;
	}

	retval = ret->data;
	free(ret);
	list->size--;

	return retval;
}

void *pop_back(list_t *list)
{
	node *ret = list->tail;
	void *retval = NULL;

	if (empty(list))
		return retval;

	if (list->head == list->tail) {
		// one node in list
		list->head = NULL;
		list->tail = NULL;
	} else {
		list->tail = ret->prev;
		list->tail->next = NULL;
		ret->prev = NULL;
	}

	retval = ret->data;
	free(ret);
	list->size--;

	return retval;
}

inline bool empty(list_t *list)
{
	return (list->head == NULL && list->tail == NULL);
}

inline size_t size(list_t *list)
{
	return list->size;
}

void insert(list_t *list, size_t index, void *value)
{
	if (empty(list) || size(list) == 0)
		push_front(list, value);

	if (index >= size(list))
		push_back(list, value);

	node *ptr = list->head;

	for (size_t i = 0; i < index-1; i++)
		ptr = ptr->next;

	node *newnode = malloc(sizeof(node));
	check_address(newnode);
	newnode->data = value;

	newnode->next = ptr->next;
	ptr->next = newnode;
	newnode->prev = ptr;

	if (newnode->next)
		newnode->next->prev = newnode;
}

void destroy_list(list_t *list)
{
	while (size(list) != 0) 
		pop_front(list);

	free(list);
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

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
	insert(list, value, 0);
}

void push_back(list_t *list, void *value)
{
	insert(list, value, size(list));
}

void *pop_front(list_t *list)
{
	return extract(list, 0);
}

void *pop_back(list_t *list)
{
	return extract(list, size(list));
}

void insert(list_t *list, void *value, size_t index)
{
	node *newnode = malloc(sizeof(node));
	check_address(newnode);
	newnode->data = value;

	list->size++;

	// Insert at head
	if (index == 0) {
		if (empty(list)) {
			list->tail = newnode;
		} else {
			newnode->next = list->head;
			list->head->prev = newnode;
		}
		list->head = newnode;
	// Insert at tail
	} else if (index >= size(list)) {
		if (empty(list)) {
			list->head = newnode;
		} else {
			newnode->prev = list->tail;
			list->tail->next = newnode;
		}
		list->tail = newnode;
	// Insert at given index
	} else {
		node *ptr = list->head;

		// Select the node right before the index to insert
		// in order to update the links
		for (size_t i = 0; i < index-1; i++)
			ptr = ptr->next;

		// Update links
		newnode->next = ptr->next;
		ptr->next = newnode;
		newnode->prev = ptr;

		if (newnode->next)
			newnode->next->prev = newnode;
	}
}

void *extract(list_t *list, size_t index)
{
	node *ptr = NULL;
	void *retval = NULL;

	if (empty(list))
		return retval;

	if (index == 0) {
		// Remove the head
		ptr = list->head;
		if (list->head == list->tail) {
			// removing last node in list
			list->head = NULL;
			list->tail = NULL;
		} else {
			list->head = ptr->next;
		}
	} else if (index >= size(list) - 1) {
		ptr = list->tail;
		if (list->head == list->tail) {
			// removing last node in list
			list->head = NULL;
			list->tail = NULL;
		} else {
			list->tail = ptr->prev;
		}
	} else {
		// Advance pointer to the target node
		for (size_t i = 0; i < index; i++)
			ptr = ptr->next;

		// Unlink the node
		ptr->prev = ptr->next;
		if (ptr->next)
			ptr->next->prev = ptr->prev;
	}

	retval = ptr->data;
	ptr->next = NULL;
	ptr->prev = NULL;

	free(ptr);
	ptr = NULL;
	
	list->size--;

	return retval;
}

void destroy_list(list_t *list)
{
	while (!empty(list))
		pop_front(list);

	free(list);
}
		

void *get(list_t *list, size_t index)
{
	if (index > size(list) - 1) {
		printf("index %zd exceeds current list size %zd\n", index,
		size(list));
		return NULL;
	}

	node *ptr = list->head;

	for (size_t i = 0; i < index; i++)
		ptr = ptr->next;

	return ptr->data;
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
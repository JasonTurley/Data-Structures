/**
 * Implementation of a doubly Linked List.
 * Self Study 3/14/19
 */

#ifndef __LIST_H__
#define __LIST_H__

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define empty(list) (list->head == NULL && list->tail == NULL)
#define size(list) (list->size)

typedef struct _node {
	void *data;
	struct _node *prev;
	struct _node *next;
} node;

typedef struct _list_t {
	node *head;
	node *tail;
	size_t size;
} list_t;

/**
 * Returns povoid *er to a new list_t struct.
 */
list_t *create_list();

/**
 * Frees contents of list.
 */
void destroy_list();

/**
 * Adds an item to the front of the list.
 */
void push_front(list_t *list, void *value);

/**
 * Adds an item to the end of the list.
 */
void push_back(list_t *list, void * value);

/**
 * Removes the node at the head of the list, and returns its value.
 */
void *pop_front(list_t *list);

/**
 * Removes the node at the tail of the list, and returns its value.
 */
void *pop_back(list_t *list);

/**
 * Inserts a node at the given index, with 0 being the first index.
 */
void insert(list_t *list, void *value, size_t index);

/**
 * Removes the node at the given index, and returns its data. 0 is the head
 * position.
 */
void *extract(list_t *list, size_t index);

/**
 * Returns the data of the node at the given index, without removing it from
 * the list.
 */
void *get(list_t *list, size_t index);

/**
 * For each node in the list, prints the address of its value.
 */
void print_list(list_t *list);

#endif

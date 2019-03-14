/** 
 * Linked List.
 * Self Study 3/14/19
 */

#ifndef __LIST_H__
#define __LIST_H__

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// TODO implement doubly linked?
static struct node {
	int data;
	struct node *next;
};

struct linked_list {
	struct node *head;
	struct node *tail;
	size_t size;
};

/**
 * Creates a new linked list struct.
 */
struct linked_list *create_list();

/**
 * Frees all memory associated with list.
 */
void destroy_list(struct linked_list *list);

/** 
 * Returns the number of data elements in list.
 */
size_t size(struct linked_list *list);

/**
 * Returns whether or not list is empty.
 */
bool is_empty(struct linked_list *list);

/**
 * Returns the value of the item at index (staring at 0).
 */
int value_at(size_t index);

/**
 * Adds an item to the front of the list.
 */
void push_front(struct linked_list *list, int value);

/** 
 * Adds an item to the end of the list.
 */
void push_back(struct linked_list *list, int value);

/** 
 * Removes and returns the value at the front of the list.
 */
int pop_front(struct linked_list *list);

/**
 * Removes and returns the value at the end of the list.
 */
int pop_back(struct linked_list *list);

/**
 * Returns the value at the front of the list, without removing it.
 */
int check_front(struct linked_list *list);

/**
 * Returns the value at the back of the list, without removing it.
 */
int check_back(struct linked_list *list);

/**
 * Inserts a value at index.
 */
void insert(struct linked_list *list, size_t index, int value);

/**
 * Removes node at given index.
 */
void erase(size_t index);

/**
 * Returns the value at the nth position from the end
 */
int value_n_from_end(struct linked_list *list, size_t n);

/**
 * Reverses the list.
 */
void reverse(struct linked_list *list);

/**
 * Removes the first node in the list with given value.
 */
void remove_value(int value);

#endif

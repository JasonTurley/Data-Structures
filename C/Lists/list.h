/** 
 * Implementation of a doubly Linked List.
 * Self Study 3/14/19
 */

#ifndef __LIST_H__
#define __LIST_H__

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct node {
	int data;
	struct node *prev;
	struct node *next;
} node;

extern struct node *head;
extern struct node *tail;

/**
 * Adds an item to the front of the list.
 */
void push_front(int value);

/** 
 * Adds an item to the end of the list.
 */
void push_back(int value);

/**
 * Returns the size of the list.
 */
int size();

/**
 * Frees contents of list.
 */
void destroy_list();

/**
 * Prints contents of list.
 */
void print_list();

/**
 * Returns true if the current list is empty.
 */
bool is_empty(struct node *head);

/**
 * Returns the value of the item at index (staring at 0).
 */
int value_at(size_t index);

/** 
 * Removes and returns the value at the front of the list.
 */
int pop_front(struct node **head);

/**
 * Removes and returns the value at the end of the list.
 */
int pop_back(struct node **tail);

/**
 * Returns the value at the front of the list, without removing it.
 */
int check_front(struct node *head);

/**
 * Returns the value at the back of the list, without removing it.
 */
int check_back(struct node *tail);

/**
 * Inserts a value at index.
 */
void insert(struct node **head, size_t index, int value);

/**
 * Removes node at given index.
 */
void erase(size_t index);

/**
 * Returns the value at the nth position from the end
 */
int value_n_from_end(struct node *node, size_t n);

/**
 * Reverses the list.
 */
void reverse(struct node **head);

/**
 * Removes the first node in the list with given value.
 */
void remove_value(int value);

#endif

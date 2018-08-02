// Doubly linked list implementation and function declarations
#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
	struct Node *prev;
};

// Function definitions

void push(struct Node **head, int new_data);

// Utility functions

struct Node *build(int new_data)
{
	struct Node *node = (struct Node*) malloc(sizeof(node));
	node->data = new_data;
	node->next = NULL;
	node->prev = NULL;
	
	return node;
}

void print_list(struct Node *head)
{
	while(head != NULL) {
		printf("%d ", head->data);
		head = head->next;
	}
    puts("\n");
}

#endif

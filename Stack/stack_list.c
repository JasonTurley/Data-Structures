// A linked-list implementation of a stack
// Created: 26 July 2018
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>     // INT_MIN

// Stack blueprint
typedef struct stack {
    int data;
    struct stack* next;
} stack;

// An error checked malloc
void* ec_malloc(int data) {
    if (data <= 0) {
        return NULL;
    }

    void* ret = malloc(data);
    if (!ret) {
        perror("Failed to allocate data\n");
        exit(-1);
    }
    return ret;
}

// Returns a pointer to a newly allocated node
stack* new_node(int data) {
    stack* s = ec_malloc(data);
    s->data = data;
    s->next = NULL;

    return s;
}

// Pushes new node to top of list
void push(stack** top, int data) {
    stack* node = new_node(data);   // error checking handled internally

    // Special case for insertion at head
    if (!(*top)) {
        *top = node;
    } else {
        node->next = *top;
        *top = node;                 // update the top of the stack
    }
}

// Removes top-most node and returns its data. If the list
// is empty, returns INT_MIN
int pop(stack** top) {
    if (*top) {
	stack* to_free = *top;
	*top = (*top)->next;

	int ret = to_free->data;
	to_free->next = NULL;
	free(to_free);
	to_free = NULL;

	return ret;
    }
    return INT_MIN;
}

// Returns the value of the top node on the stack. Does not 
// remove the node from the list
int peek(stack* top) {
    if (top) {
        int ret = top->data;
        return ret;
    }
    return INT_MIN;
}

// Check if stack is empty
int isEmpty(stack* top) {
    return (top == NULL);
}

int main() {
    stack* top = NULL;
    int x;

    push(&top, 1);
    x = peek(top);
    printf("peeked: %d\n", x);

    push(&top, 2);
    
    x = pop(&top);
    printf("popped: %d\n", x);

    x = pop(&top);
    printf("popped: %d\n", x);

    x = pop(&top);
    printf("popped: %d\n", x);

    printf("Stack is empty: %d\n", isEmpty(top));

    return 0;
}

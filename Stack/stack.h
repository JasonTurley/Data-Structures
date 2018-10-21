/*
 * @author jason
 * @date 10/21/18
 *
 * Header for a stack data structure.
 */

#ifndef _STACK_H_
#define _STACK_H_

#include <stdint.h>

/*
 * Represents data for stack.
 */
typedef struct node_t {
    int data;
    struct node_t *next;
    //struct node *prev;
} node_t;


typedef struct stack_t {
    node_t *head; /* top of stack */   
    node_t *data;
    uint32_t size;
} stack_t;


node_t *new_node(int data);

stack_t *stack_create(); 

void push(stack_t *, int);

int pop(stack_t *);

void stack_destroy(stack_t *);

#endif

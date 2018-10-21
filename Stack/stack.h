/*
 * @author jason
 * @date 10/21/18
 *
 * Header for a stack data structure.
 */

#ifndef _STACK_H_
#define _STACK_H_

#include <stdint.h>

typedef struct stack_t {
    int *data;
    uint32_t size;
    struct stack_t *next;
    //stack_t *prev;
} stack_t;

stack_t *stack_create(); 

void push(stack_t *, int);

int pop(stack_t *);

void stack_destroy(stack_t *);

#endif

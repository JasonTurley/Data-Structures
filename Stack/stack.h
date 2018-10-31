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
 * Represents a stack.
 */
typedef struct stack_t { 
    uint32_t size;      /* current stack size */
    uint32_t capacity;  /* max elements */
    int *elements;      /* list of data */
} stack_t;


stack_t *stack_create(uint32_t max_size); 

void push(stack_t * s, int);

int pop(stack_t * s);

void resize(stack_t* s);

void stack_destroy(stack_t *s);

#endif

/**
 * @author jason
 * @date 10/21/18
 *
 * Header for a stack data structure.
 */

#ifndef _STACK_H_
#define _STACK_H_

#include <stdint.h>
#include <stdbool.h>

/**
 * Represents a stack.
 */
typedef struct stack_t {
    int *elements;      // holds stack elements
    uint32_t size;      // current number of elements in the stack
    uint32_t capacity;  // max number of elements the stack can hold
} stack_t;

/**
 * Creates a stack with a capacity of max_size.
 */
stack_t *stack_create(uint32_t max_size);

/**
 * Adds an element to the top of the stack.
 */
void push(stack_t *s, int elem);

/**
 * Removes and returns the top element in the stack.
 */
int pop(stack_t *s);

/**
 * Returns the top element in the stack without removing it.
 */
int peek(stack_t *s);

/**
 * Returns the number of elements in the stack.
 */
uint32_t size(stack_t *s);

/**
 * Returns whether or not the stack is empty.
 */
bool is_empty(stack_t *s);

/**
 * Frees memory associated with the stack.
 */
void stack_destroy(stack_t *s);

#endif

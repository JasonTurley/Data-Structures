/*
 * @author jason
 * @date 10/21/18
 *
 * Implementation of a stack data structure.
 */

#include <stdlib.h>
#include <assert.h>

#include "stack.h"
#include "utils.h"

/*
 * Creates a node with `data
 */
node_t *new_node(int data)
{
    node_t *n = safe_malloc(sizeof(node_t));    
    n->data = data;
    n->next = NULL;
}

stack_t *stack_create() 
{
    stack_t *s = safe_malloc(sizeof(stack_t));
    s->data = NULL;
    s->size = 0;

    return s;
}

void push(stack_t *s, int data)
{
    assert(s);
    node_t *n = new_node(data);

    // Insert node into linked list
    if (!s->head) {
        s->head = n;
    } else {
        s->head->next = n;
        s->head = n;
    }

    s->size++;
}

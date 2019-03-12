#include "doubly-linked-list.h"

void push(struct Node **head, int new_data)
{
    /* 1. Add data to newly made node */
    struct Node *new_node = build(new_data);

    /* 2. link with head */
    new_node->next = *head;
   
    if ((*head) != NULL) 
       (*head)->prev = new_node;

    /* 3. update head pointer */
    *head = new_node; 
}


// Driver program to test functions
int main()
{
    // always initialize pointers to NULL
    struct Node *node = NULL;
    push(&node, 2);
    push(&node, 3);
    print_list(node);

    return 0;
}

// singly linked list implementation and functions
#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
};

// Given the start of a list and an int, inserts a new node at the front of a list
void push(struct Node **head, int new_data)
{
    // If there's no list, exit function
    if (!head)
    {
        puts("Error: no list found");
        return;
    }

    struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
    
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}

// Deletes node at k, where k is the position of node
void deleteNodeK(struct Node **head, int k)
{
    if (!head)
    {
        puts("Error: no list found");
        return;
    }

    struct Node *temp, *prev;
    temp = *head;
    prev = *head;

    // Select node directly before the one to be delete
    // change what it points to
    int i;
    for (i = 1; i < k-1; i++)
    {
        prev = prev->next;
    }
    temp = prev->next;
    prev->next = temp->next;

    // Delete selected node
    free(temp);
}

// This function prints the contents of a linked list starting from a given node
void printList(struct Node *n)
{
    while(n)
    {
        printf(" %d", n->data);
        n = n->next;
    }
    puts("\n");
}

int main(int argc, char *argv[])
{
    // start with empty list
    struct Node* head = NULL;

    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    puts("Current list:\t");
    printList(head);
    puts("List after deletion:\t");
    deleteNodeK(&head, 3);
    printList(head);
    
    return 0;
}
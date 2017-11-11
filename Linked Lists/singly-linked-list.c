// singly linked list implementation and functions
#include <stdio.h>
#include <stdlib.h>

#define IF_EQ(a, b) if (a == b)

struct Node 
{
    int data;
    struct Node *next;
};

// Given the start of a list and an int, inserts a new node at the front of a list
void push(struct Node **head, int new_data)
{
    // If there's no list, exit function
    IF_EQ(head, NULL)
    {
        puts("Error: no list found");
        return;
    }

    struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
    
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}

// Inserts node at the end of a list
void pushAtEnd(struct Node **head, int new_data)
{
    IF_EQ(head, NULL)
    {
        puts("Error: no list found");
        return;
    }

    struct Node *tail = *head;
    struct Node *temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = new_data;
    temp->next = NULL;

    // Advance tail to end of list
    while (tail->next != NULL)
        tail = tail->next;
    
    tail->next = temp;
}

// Deletes node at k, where k is the position of node
void deleteNodeK(struct Node **head, int k)
{
    IF_EQ(head, NULL)
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

// Given the start of a list, prints the data at the middle of the list
int midData(struct Node **head)
{
    IF_EQ(head, NULL)
        return;

    struct Node* temp = *head;
    int mid = listLength(*head)/2;
    int i = 0;
    IF_EQ(mid % 2, 0)
    {
        mid++;
    }
    for ( ; i < mid-1; i++)
        temp = temp->next;

    return temp->data;
}

// This function prints the size of a list starting with the given node
int listLength(struct Node *n)
{
    int length = 0;
    while(n)
    {
        n = n->next;
        length++;
    }
    return length;
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
    ////deleteNodeK(&head, 3);
    printList(head);
    puts("List after insert at end:\t");
    pushAtEnd(&head, 7);
    printList(head);
    printf("%d\n", listLength(head));
    printf("%d\n", midData(&head));

    return 0;
}
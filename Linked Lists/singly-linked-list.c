// singly linked list implementation and functions
#include <stdio.h>
#include <stdlib.h>

/* MACROS */
#define IF_EQ(a, b) if (a == b)	// Checks if two elements are equal

// Linked List struct
struct Node 
{
    int data;
    struct Node *next;
};

// Given the start of a list and an int, inserts a new node at the front of a list
void push(struct Node **head, int new_data)
{

    struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
    
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}

// Removes the first node from a list and returns its data
int pop(struct Node **head)
{
	struct Node *curr = *head;
	int data = curr->data;
	// Update head so we don't lose it
	*head = curr->next;
	
	curr = NULL;
	return data;
}

// Inserts node at the end of a list
void pushAtEnd(struct Node **head, int new_data)
{
    IF_EQ(*head, NULL)
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
    IF_EQ(*head, NULL)
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

// Given the start of a list, prints the data at the middle of the list
int midData(struct Node **head)
{
    IF_EQ(*head, NULL)
        return -1;

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

// Reverses linked list
void reverse(struct Node **head)
{
	IF_EQ(*head, NULL)	
		return;

	struct Node *prev, *curr, *next;
	prev = NULL;
	curr = *head;

	// swap pointers
	while (curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	// Update head
	*head = prev;
}

// Insert nodes of a linked list h2 into h1 at alternating positions
void mergeList(struct Node **h1, struct Node **h2)
{
	struct Node *curr1, *curr2, *next1, *next2;
	curr1 = *h1;
	curr2 = *h2;
	
	while (curr1 != NULL && curr2 != NULL)
	{
		next1 = curr1->next;
		next2 = curr2->next;
		curr1->next = curr2;
		curr2->next = next1;
		curr1 = next1;
		curr2 = next2;
	}
	// update list heads
	*h2 = curr2;
}

// Deletes the entirity of a list
void deleteList(struct Node **head)
{
	struct Node *curr, *next;
	curr = *head;
	// traverse list from head->next onwards
	while (curr) 
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	*head = NULL;
}

// Given a sorted list, insert node at proper position
void sortedInsert(struct Node **head, struct Node *newNode)
{
	struct Node *curr, *next;
	curr = next = *head;
	// If next node data is larger than newNode's data, insert here
	while (next->data <= newNode->data && curr) 
	{
		next = curr->next;
		curr = next;
	}
	// Now at proper position to insert
	// link nodes
	curr = newNode;
	newNode = next;

}


// Driver program to test functions
int main(int argc, char *argv[])
{
    // start with empty list
    struct Node* head = NULL;

    // 1->2->3->4->8->10->NULL
    push(&head, 1);
    pushAtEnd(&head, 2);
    pushAtEnd(&head, 3);
    pushAtEnd(&head, 4);
    pushAtEnd(&head, 8);  
    pushAtEnd(&head, 10);

    puts("Current list:\t");
    printList(head);

    struct Node* newNode;
    newNode->data = 7;
    printf("Insert 7:\n");
    sortedInsert(&head, newNode);
    printList(head); 
    
   

    return 0;
}

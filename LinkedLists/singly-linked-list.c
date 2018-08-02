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

// Constructor
struct Node *newNode(int data)
{
	struct Node *new_node = (struct Node*) malloc(sizeof(*new_node));
	if (!new_node) { // malloc failed
		return NULL;
	}
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

// Given the start of a list and an int, inserts a new node at the front of a list
void push(struct Node **head, int new_data)
{
    struct Node *new_node = newNode(new_data);
    if (new_node) {
    	new_node->next = *head;
    	*head = new_node;
    }
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

// Inserts a node at given position, with the head at index 0
void insertNth(struct Node **head, int new_data,  int pos)
{
	// special case for inserting at beginning
	if (pos == 0) {
		push(head, new_data);
    }

	struct Node *temp = *head;
	// Select node directly before the given position
	int i;
	for (i = 0; i < pos-1; i++)	{	
		if (!temp) return;
		temp = temp->next;
	}
	// Insert node at position
	struct Node *node= newNode(new_data);
	if (!node) {
		fprintf(stderr, "Unable to allocate new node.\n");
		return;
	}
	node->next = temp->next;
	temp->next = node;
}

// Deletes node at k, where k is the position of node
void deleteNodeK(struct Node **head, int k)
{
    IF_EQ(*head, NULL) {
        puts("Error: no list found");
        return;
    }

    struct Node *temp, *prev;
    temp = *head;
    prev = *head;

    // Select node directly before the one to be delete
    // change what it points to
    int i;
    for (i = 1; i < k-1; i++) {
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
    while(n) {
        n = n->next;
        length++;
    }

    return length;
}

// Given the head of a list, prints the data from the middle index to the end
int midData(struct Node **head)
{
    IF_EQ(*head, NULL) {
        return -1;
    }

    struct Node* temp = *head;
    int mid = listLength(*head)/2;
    
    IF_EQ(mid % 2, 0) {
        mid++;
    }

    int i = 0;
    for ( ; i < mid-1; i++) {
        temp = temp->next;
    }
 
   return temp->data;
}

// This function prints the contents of a linked list starting from a given node
void printList(struct Node *n)
{
    while(n) {
        printf(" %d", n->data);
        n = n->next;
    }
 
    puts("\n");
}

// Reverses linked list
void reverse(struct Node **head)
{
	IF_EQ(*head, NULL) {
		return;
    }

	struct Node *prev, *curr, *next;
	prev = NULL;
	curr = *head;

	// swap pointers
	while (curr != NULL) {
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
	
	while (curr1 != NULL && curr2 != NULL) {
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
	while (curr) {
		next = curr->next;
		free(curr);
		curr = next;
	}
	*head = NULL;
}

// Given a sorted list, insert node at proper position
void sortedInsert(struct Node **head, struct Node *newNode)
{	
	// base case for newNode's data being less than head's data
	if (*head == NULL || newNode->data < (*head)->data) { 
		newNode->next = *head;
		*head = newNode;
		return;
	}

	struct Node *curr, *next;
	curr = next = *head;
	
	// If next node data is larger than newNode's data, insert here
	while (next->data <= newNode->data && curr) {
		next = curr->next;
		curr = next;
	}
	
    // Now at proper position to insert
	curr = newNode;
	newNode = next;
}

// Given an unsorted list, rearrange in sorted increasing order using sortedInsert()
void insertSort(struct Node **head)
{
	IF_EQ(*head, NULL) {
		return;
    }

	struct Node *result = NULL;	// build new list here
	struct Node *curr = *head;
	struct Node *next;

	// Compare each node in current list with nodes in result list
	while (curr) {
		next = curr->next;	// Tricky -- note the next pointer before we change it
		sortedInsert(&result, curr);
		curr = next;
	}

	*head = result;
}

// Append the end of list A to the beginning of list B. Afterwards, set B to NULL
void append(struct Node **aRef, struct Node **bRef)
{
	if (*aRef == NULL && *bRef) { 
		*aRef = *bRef;
		return;
	}
	
    IF_EQ(*bRef, NULL) {
        return; 
	}

	// lists are not empty, grab the last node in A
	struct Node *curr = *aRef;
	while (curr->next) {
		curr = curr->next; 
    }

    // link the two lists and set B to NULL
    curr->next = *bRef;
    *bRef = NULL;
}

// Find the middle element of a linked list given only the head
int midItem(struct Node *head)
{
    // initialize a fast and slow pointer
    struct Node *fast_ptr = head; 
    struct Node *slow_ptr = head;
    // move fast pointer ahead two and slow pointer one
    while (fast_ptr != NULL && fast_ptr->next != NULL) {
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
    }
    // slow pointer is at mid node
    return slow_ptr->data;
}

// Driver program to test functions
int main(int argc, char *argv[])
{
    // start with empty list
    struct Node* head = NULL;

    // 
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);  
    push(&head, 6);

    puts("Current list:\t");
    printList(head);
  
 //   puts("List after insertSort:\t");
    insertSort(&head);
    struct Node *head2 = NULL;
    push(&head2, 11);
    
    append(&head, &head2); 
    printList(head); 
}

#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"

// Returns the node containintg item x, otherwise returns null
struct Node* search(struct Node *root, int x) 
{
	// Base case: tree is empty
	if (root == NULL)	return NULL; 

	if (root->data == x)	return root;

	// Data is greater than target, search left subtree
	if (root->data > x)	return search(root->left, x);
	// otherwise, search right subtree
	return search(root->right, x);
}

int main()
{
	struct Node *root = malloc(sizeof(struct Node));
	root->data = 4;

	printf("Node is at address: %p\n", search(root, 4));
	printf("Node is at address: %p\n", search(root, 2));
	printf("Node is at address: %p\n", search(root, 10));
	
	return 0;
}

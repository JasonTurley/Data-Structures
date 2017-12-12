#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"

// Returns the node containintg item x, otherwise returns null
struct Node *search(struct Node *root, int x) 
{
	// Base case: tree is empty
	if (root == NULL)	return NULL; 

	if (root->data == x)	return root;

	// Data is greater than target, search left subtree
	if (root->data > x)	return search(root->left, x);
	// otherwise, search right subtree
	return search(root->right, x);
}

// Returns pointer to the smallest node in tree
Node *findMin(struct Node *root) 
{
	if (root == NULL)	return NULL;

	// The smallest node is the left-most child
	// traverse to that node
	while (root->left != NULL)
		root = root->left;
	
	return root;
}

// Returns pointer to the largest node in tree
Node *findMax(struct Node *root)
{
	if (root == NULL)	return NULL;

	// The largest node is the right-most child
	// traverse to that node
	while (root->right != NULL)
		root = root->right;
	
	return root;
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

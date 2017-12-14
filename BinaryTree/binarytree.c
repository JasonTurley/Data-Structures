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


// Returns the height of a binary tree
int height(struct Node *root)
{
	if (root == NULL)	return -1;
	
	int left_height = height(root->left);
	int right_height = height(root->right);

	return 1 + max(left_height, right_height);
}


int main()
{
	struct Node *root = malloc(sizeof(struct Node));
	root->data = 4;
	struct Node *root2, *root3, *root4, *root5;
	root2 = malloc(sizeof(struct Node));
	root3 = malloc(sizeof(struct Node));
	root4 = malloc(sizeof(struct Node));
	root5 = malloc(sizeof(struct Node));

	root->left = root2;
	root->right = root3;
	root2->left = root4;
	root2->right = root5;

	root3->left = root3->right = NULL;
	root4->left = root4->right = NULL;
	root5->left = root5->right = NULL;
//	printf("Node is at address: %p\n", search(root, 4));
//	printf("Node is at address: %p\n", search(root, 2));
//	printf("Node is at address: %p\n", search(root, 10));
	printf("Binary tree height: %d\n", height(root));
	
	
	return 0;
}

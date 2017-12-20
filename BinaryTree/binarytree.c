#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"

// Creates a node with given data
struct Node *newNode(int data)
{
	struct Node *node = malloc(sizeof(struct Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}


// insert a node to into a binary search tree
struct Node *insert(struct Node *root, int data)
{
	// If an empty tree is passed in, create a new, single node
	if (root == NULL)
		return newNode(data);

	// Otherwise, recur down the tree
	if (data <= root->data)
		root->left = insert(root->left, data);

	else	
		root->right = insert(root->right, data);

	return root;
}

// Returns the size of a binary tree
int size(struct Node *root)
{
	if (root == NULL)	
		return 0;

	// +1 for uncounted root
	return 1 + size(root->left) + size(root->right);
}

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


// Returns the maximum height of a binary tree
int height(struct Node *root)
{
	if (root == NULL)	return -1;
	
	int left_height = height(root->left);
	int right_height = height(root->right);

	return 1 + max(left_height, right_height);
}


int main()
{
	struct Node *root = NULL;
	root =	insert(root, 30);
	root =	insert(root, 40);
	root =	insert(root, 50);
	root =	insert(root, 20);
	root =	insert(root, 10);
	root =	insert(root, 15);
	root =	insert(root, 35);
	root =	insert(root, 8);


//	printf("Node is at address: %p\n", search(root, 4));
//	printf("Node is at address: %p\n", search(root, 2));
//	printf("Node is at address: %p\n", search(root, 10));
	printf("Binary tree height: %d\n", height(root));
	printf("Binary contains %d nodes\n", size(root));	
	
	return 0;
}

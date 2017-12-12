#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"

// Returns the node containintg item x, otherwise returns null
struct Node* search(struct Node *root, int x) 
{
	if (!root) 
		return NULL; // base case for empty tree
	if (root->data == x) 
		return root;
	if (root->data > x)	// current node's data is larger than target, go left
		return search(root->left, x);
	// otherwise, go right
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

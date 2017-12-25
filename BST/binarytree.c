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

/* Given a tree and a sum, return true if there is a path from the root to leaf 
   such that all the values in the path equals the given sum.
 
   Strategy: subtract node's value from sum as we recur down the tree. If the sum
   equals 0 at the end then return true.
*/
int hasPathSum(struct Node *root, int sum)
{
	if (root == NULL) {
		return (sum == 0);
	}
	else {
		// otherwise check both the subtrees
		int subSum = sum - root->data;
		return (hasPathSum(root->left, subSum) ||
			hasPathSum(root->right, subSum));	
	}
}		

// Given a binary tree, print out all of its root-node paths, one per line
void printPaths(struct Node *root)
{
	int path[1000];
	
	printPathsRecur(root, path, 0);
}

// Recursive helper function
void printPathsRecur(struct Node *root, int path[], int pathLen)
{
	if (root == NULL) return;
	
	// append this node to the path array
	path[pathLen] = root->data;
	pathLen++;

	// it's a leaf, so print the path that led to here
	if (!root->left && !root->right) {
		printArray(path, pathLen);	
	}
	else {
	// otherwise check both subtrees
		printPathsRecur(root->left, path, pathLen);
		printPathsRecur(root->right, path, pathLen);
	}
}

// Utility that prints an array on a single line
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++) {
		printf("%d ", arr[i]);		
	}
	puts("\n");
}


// Prints a binary tree with inorder traversal
void printInOrder(struct Node *root)
{
	if (root == NULL)
		return;

	printInOrder(root->left);
	printf("%d ", root->data);
	printInOrder(root->right);
}

// Return the mirrored version of a tree
void mirror(struct Node *root)
{
	if (root == NULL)
		return;

	// Recur both subtrees
	mirror(root->left);
	mirror(root->right);
	// swap the pointers
	struct Node *temp;
	temp = root->left;
	root->left = root->right;
	root->right = temp;
}

void doubleTree(struct Node *root)
{
	if (root == NULL)
		return;
	doubleTree(root->left);
	doubleTree(root->right);

	// create duplicate of current node and assign it to as the left child
	struct Node *temp = newNode(root->data);
	temp->left = root->left;
	root->left = temp;
}


int main()
{
	// tree built via insertion
	struct Node *root = NULL;
	root =	insert(root, 30);
	root =	insert(root, 40);
	root =	insert(root, 50);
	root =	insert(root, 20);
	root =	insert(root, 10);
	root =	insert(root, 15);
	root =	insert(root, 35);
	root =	insert(root, 8);

	// tree built via constructor			tree:
	struct Node *node = newNode(2);	//			2
	node->left 	  = newNode(1); //		       / /
	node->right	  = newNode(3); //		     1	  3
	
	
	printf("In order traversal of tree2: \n");
	printInOrder(node);
	
	puts("\n");
	doubleTree(node);
	printf("Double tree: \n");
	printInOrder(node);

	return 0;
}

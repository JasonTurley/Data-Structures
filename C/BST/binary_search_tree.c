/**
 * Implementation of a BinarySearchTree.
 *
 * Updated - 11/19/18
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "binary_search_tree.h"

static int max(int a, int b)
{
	return (a >= b ? a : b);
}

static struct Node *newNode(int data)
{
	struct Node *node = malloc(sizeof(struct Node));

    	if (!node) {
        	perror("Failed to allocated new node");
        	exit(-1);
    	}

	node->data = data;
	node->left = NULL;
	node->right = NULL;

    	return node;
}

struct Node *insert(struct Node *root, int data)
{
	if (!root)
		return newNode(data);

	if (data < root->data)
		root->left = insert(root->left, data);
	else if (data > root->data)
		root->right = insert(root->right, data);

	// Return the unchanged node pointer
	return root;
}

struct Node *search(struct Node *root, int x)
{
	if (!root)
		return NULL;

	if (x < root->data)
		return search(root->left, x);
	else if (x > root->data)
		return search(root->right, x);
	else
		return root;
}

struct Node *del(struct Node *root, int data)
{
	if (!root)
		return NULL;

	// Node to delete is in left sub-tree
	if (data < root->data)
		root->left = del(root->left, data);

	// Node to delete is in right sub-tree
	else if (data > root->data)
		root->right = del(root->right, data);

	// Found node to delete: deletion method depends on number of children
	else {
		// Case 1: No children
		if (!root->left && root->right) {
			free (root);
			root = NULL;
		}

		// Case 2: One child
		else if (!root->left) {
			struct Node *temp = root;
			root = root->right;
			free(temp);
			temp = NULL;
		} else if (!root->right) {
			struct Node *temp = root;
			root = root->left;
			free(temp);
			temp = NULL;

		// Case 3: Two children
		} else {
			int min = findMin(root->right);
			root->data = min;
			root->right = del(root->right, min);
		}
	}

	return root;
}

int findMin(struct Node *root)
{
	while (root->left)
		root = root->left;

	return root->data;
}

int findMax(struct Node *root)
{
	while (root->right)
		root = root->right;

	return root->data;
}

int height(struct Node *root)
{
	if (!root)
		return 0;

	return 1 + max(height(root->left), height(root->left));
}

void printInOrder(struct Node *root)
{
	if (root) {
		printInOrder(root->left);
	    	printf("%d ", root->data);
	    	printInOrder(root->right);
    	}
}

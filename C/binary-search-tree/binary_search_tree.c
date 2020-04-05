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

static struct bst_node *create_bst_node(const int data)
{
	struct bst_node *node = malloc(sizeof(struct bst_node));

    	if (!node) {
        	perror("Failed to allocated new node");
        	exit(-1);
    	}

	node->data = data;
	node->left = NULL;
	node->right = NULL;

    	return node;
}

struct bst_node *insert(struct bst_node *root, const int data)
{
	if (!root)
		return create_bst_node(data);

	if (data < root->data)
		root->left = insert(root->left, data);
	else if (data > root->data)
		root->right = insert(root->right, data);

	return root;
}

struct bst_node *search(struct bst_node *root, int x)
{
	if (!root)
		return NULL;

	if (x == root->data)
		return root;
	else if (x < root->data)
		return search(root->left, x);
	else
		return search(root->right, x);
}

struct bst_node *delete_value(struct bst_node *root, int data)
{
	if (!root)
		return NULL;

	if (data < root->data)
		root->left = delete_value(root->left, data);

	else if (data > root->data)
		root->right = delete_value(root->right, data);

	// Found node to delete: deletion method depends on number of children
	else {
		if (root->left && root->right) { // Two children
			int min = find_min(root->right);
			root->data = min;
			root->right = delete_value(root->right, min);
		} else {
			struct bst_node *oldRoot = root;
			root = (root->left) ? root->left : root->right;
			free (oldRoot);
			oldRoot = NULL;
		}
	}

	return root;
}

struct bst_node *delete_tree(struct bst_node *root)
{
	if (!root)
		return NULL;

	delete_tree(root->left);
	delete_tree(root->right);
	free(root);
	root = NULL;

	return root;
}


int find_min(struct bst_node *root)
{
	if (!root)
		return 0;

	while (root && root->left)
		root = root->left;

	return root->data;
}

int find_max(struct bst_node *root)
{
	if (!root)
		return 0;

	while (root->right)
		root = root->right;

	return root->data;
}

int get_height(struct bst_node *root)
{
	if (!root)
		return 0;

	return 1 + max(get_height(root->left), get_height(root->left));
}

void print_tree(struct bst_node *root)
{
	if (root) {
		print_tree(root->left);
		printf("%d ", root->data);
		print_tree(root->right);
	}
}

/**
 * Implementation of a BinarySearchTree.
 *
 * This legacy code is for educational purposes, the c++ version is the one
 * the program uses.
 *
 * Updated - 11/19/18
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "binarytree.h"

/**
 * Creates a node with given data
 */
 struct Node *new_node(int data)
{
	struct Node *node = malloc(sizeof(struct Node));

    if (node == NULL) {
        perror("Failed to allocated new node");
        exit(-1);
    }

	node->data = data;
	node->left = NULL;
	node->right = NULL;

    return node;
}


/** 
 * Insert a node to into a binary search tree
 */
struct Node *insert(struct Node *root, int data)
{
    if (root) {
        if (data <= root->data) {
            root->left = insert(root->left, data);
        } else {
            root->right = insert(root->right, data);
        }
    } else {
        return new_node(data);
    }
}

/** 
 * Returns the size of a binary tree
 */
size_t size(struct Node *root)
{
	if (root) {	
	    return 1 + size(root->left) + size(root->right);
    }
	
    return 0;
}

/** 
 * Returns the node containintg item x, otherwise returns null
 */
struct Node *search(struct Node *root, int x) 
{
	if (root) {	
        if (x == root->data) { 
            return root;
        } else if (x < root->data) {
            search(root->left, data);
        } else {
            search(root->right, data);
        }
    }

    return NULL;
}

/** 
 * Returns a pointer to the node with the smallest data
 */
Node *find_min(struct Node *root) 
{
    if (root) {
	    // The smallest node is the left-most child
	    while (root->left != NULL)
	        root = root->left;
	
	    return root;
    }

    return NULL;
}

/**
 * Returns pointer to the largest node in tree
 */
Node *find_max(struct Node *root)
{
	if (root) {
	    // The largest node is the right-most child
	    while (root->right != NULL)
		    root = root->right;
	
	    return root;
    }

    return NULL;
}

/** 
 * Returns the maximum height of a binary tree
 */
int height(struct Node *root)
{
	if (root) {
	    int left_height = height(root->left);
	    int right_height = height(root->right);

	    return 1 + max(left_height, right_height);
    }

    return -1;
}

/** 
 * Prints a binary tree with inorder traversal
 */
void printInOrder(struct Node *root)
{
	if (root) {
		printInOrder(root->left);
	    printf("%d ", root->data);
	    printInOrder(root->right);
    }
}

/**
 * Return the mirrored version of a tree
 */
void mirror(struct Node *root)
{
	if (root) {
		// Recur both subtrees
	    mirror(root->left);
	    mirror(root->right);
	
        // swap the pointers
	    struct Node *temp;
	    temp = root->left;
	    root->left = root->right;
	    root->right = temp;
    }
}

/**
 * Creates a copy of each node, and assigns it as its left child
 */
void double_tree(struct Node *root)
{
	if (root == NULL)
		return;
	double_tree(root->left);
	double_tree(root->right);

	// create duplicate of current node and assign it to as the left child
	struct Node *temp = new_node(root->data);
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
	struct Node *node = new_node(2);	//			2
	node->left 	  = new_node(1); //		       / /
	node->right	  = new_node(3); //		     1	  3
	
	
	printf("In order traversal of tree2: \n");
	printInOrder(node);
	
	puts("\n");
	doubleTree(node);
	printf("Double tree: \n");
	printInOrder(node);

	return 0;
}

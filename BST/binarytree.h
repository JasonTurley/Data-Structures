/**
 * @file binarytree.h
 *
 * @date (modified) 1 August 2018
 */
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <stdio.h>

/* Represents a tree Node */
typedef struct Node {
	int data;		/* data item */
	struct Node *left;	/* pointer to left child */
	struct Node *right;	/* pointer to right child */
} Node;	

/**
 * Searches for the node with target value x. If found, returns a
 * pointer to the node. Otherwise, returns NULL.
 *
 * @param root The start of the tree.
 * @param x Target value
 * @return The target node
 */
struct Node *search(struct Node *root, int x);

/**
 * Finds the node with the smallest value in the tree.
 *
 * @param root The start of the tree.
 * @return The smallest value node
 */
struct Node *findMin(struct Node *root);

/**
 * Finds the node with the largest value in the tree.
 *
 * @param root The start of the tree.
 * @return The largest value node
 */
struct Node *findMax(struct Node *root);

/**
 * Returns the length of the longest path in the tree.
 *
 * @param root The start of the tree.
 * @return Size of the tree's longest path
 */
int max_height(struct Node *root);

/**
 * Returns the length of the shortest path in the tree.
 *
 * @param root The start of the tree.
 * @return Size of the tree's shortest path
 */
int min_height(struct Node *root);

/**
 * Returns the number of leaf nodes in the tree. Note, a
 * leaf node is defined as a node without any children.
 *
 * @param root The start of the tree.
 * @return Amount of leaf nodes.
 */
int countLeaves(struct Node *root);

/**
 *
 *
 */
int levelOrderTraversal(struct Node *root);

/**
 * Prints a path of nodes in the tree.
 *
 * @param root The start of the tree.
 */
void printPaths(struct Node *root);

/**
 * Helper function to print the paths of a tree.
 *
 * @param root The start of the tree.
 * @param path An array of nodes
 * @param pathLen Size of the path array
 */
void printPathsRecur(struct Node *root, int path[], int pathLen);

/* Helper functions */
int min(int x, int y) { return (x < y) ? x : y; }
int max(int x, int y) { return (x > y) ? x : y; }
void printArray(int arr[], int size);


#endif


















/**
 * @file binary_search_tree.h - Implementation of a binary search tree.
 *
 * @date (modified) 11 June 2019
 */

#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_

#include <stdio.h>

/* Represents a node in a binary search tree */
struct Node {
	int data;
	struct Node *left;
	struct Node *right;
};

/**
 * Deletes every node within the tree.
 *
 * @param root The start of the tree.
 */
struct Node *delete_tree(struct Node *root);

/**
 * Inserts a node within the tree.
 *
 * @param root The start of the tree.
 * @param data The data to insert.
 * @return address of updated root.
 */
struct Node *insert(struct Node *root, int data);

/**
 * Searches for the node with target value x. If found, returns a
 * pointer to the node. Otherwise, returns NULL.
 *
 * @param root The start of the tree.
 * @param data Target value
 * @return The target node
 */
struct Node *search(struct Node *root, int data);

/**
 * Deletes a node from the tree.
 *
 * @param root The start of the tree.
 * @param data The data to delete.
 */
struct Node *delete_value(struct Node *root, int data);

/**
 * Finds the node with the smallest value in the tree.
 *
 * @param root The start of the tree.
 * @return The smallest value node
 */
int find_min(struct Node *root);

/**
 * Finds the node with the largest value in the tree.
 *
 * @param root The start of the tree.
 * @return The largest value node
 */
int find_max(struct Node *root);

/**
 * Returns the height of a tree.
 *
 * @param root The start of the tree.
 * @return Height of tree.
 */
int height(struct Node *root);

/**
 * Prints node values in ascending order.
 *
 * @param root The start of the tree.
 */
void printInOrder(struct Node *root);

/**
 * Returns the number of leaf nodes in the tree. Note, a
 * leaf node is defined as a node without any children.
 *
 * @param root The start of the tree.
 * @return Amount of leaf nodes.
 */
int countLeaves(struct Node *root);

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

#endif // _BINARY_SEARCH_TREE_H_


















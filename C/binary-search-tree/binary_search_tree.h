/**
 * binary_search_tree.h - Declaration of a binary search tree.
 *
 * (modified) 4 April 2020
 */

#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_

/* Represents a node in a binary search tree */
struct bst_node {
	int data;
	struct bst_node *left;
	struct bst_node *right;
};

/**
 * Inserts a node within the tree.
 *
 * @param root The start of the tree.
 * @param data The data to insert.
 * @return address of updated root.
 */
struct bst_node *insert(struct bst_node *root, const int data);

/**
 * Searches for the node with target value x. If found, returns a
 * pointer to the node. Otherwise, returns NULL.
 *
 * @param root The start of the tree.
 * @param data Target value
 * @return The target node
 */
struct bst_node *search(struct bst_node *root, int data);

/**
 * Deletes a node from the tree.
 *
 * @param root The start of the tree.
 * @param data The data to delete.
 */
struct bst_node *delete_value(struct bst_node *root, const int data);

/**
 * Deletes every node within the tree.
 *
 * @param root The start of the tree.
 */
struct bst_node *delete_tree(struct bst_node *root);

/**
 * Finds the node with the smallest value in the tree.
 *
 * @param root The start of the tree.
 * @return The smallest value node
 */
int find_min(struct bst_node *root);

/**
 * Finds the node with the largest value in the tree.
 *
 * @param root The start of the tree.
 * @return The largest value node.
 */
int find_max(struct bst_node *root);

/**
 * Returns the height of a tree.
 *
 * @param root The start of the tree.
 * @return Height of tree.
 */
int get_height(struct bst_node *root);

/**
 * Prints the contents of the tree in order.
 *
 * @param root The start of the tree.
 */
void print_tree(struct bst_node *root);

#endif // _BINARY_SEARCH_TREE_H_


















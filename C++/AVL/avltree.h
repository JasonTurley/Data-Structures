/**
 * @file AVLTree.h
 * Declaration of the AVLTree class. An AVLTree is a common self-balancing
 * Binary Search Tree. This guarantees O(logN) operations.
 *
 * @author Jason Turley
 * @date 11 August 2018
 *
 * Modified Summer 2019:
 * - Add templates
 * - Cleaner interface and implementations
 */

#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>

using std::ostream;

/**
 * The AVLTree class represents a memory linked AVL Tree.
 */
template <class K, class V>
class AVLTree
{
private:
	/**
	 * Node represents an element in an AVLTree; it contains a key-value
	 * pair, pointers to its left and right elements, and its height.
	 */
	struct Node {
		K key;
		V value;
		Node* left;
		Node* right;
		int height;

		/**
		 * Node constructor.
		 */
		Node(const K& newKey, const V& newValue)
			: key(newKey)
			, value(newValue)
			, left(nullptr)
			, right(nullptr)
			, height(0)
		{
			/* nothing */
		}
	};

public:
	/**
	 * Constructs an empty AVLTree.
	 */
	AVLTree();

	/**
	 * Copy constructor.
	 */
	AVLTree(const AVLTree& other);

	/**
	 * Releases memory consumed by AVLTree.
	 */
	~AVLTree();

	/**
	 * Assignment operator.
	 */
	const AVLTree& operator=(const AVLTree& rhs);

	/**
	 * Frees all nodes in the tree and sets it to be empty.
	 */
	void clear();

	/**
	 * Inserts a key and value into the AVLTree.
	 */
	void insert(const K& key, const V& value);

	/**
	 * Removes a ket from the AVLTree. The key is assumed to exist in the
	 * tree.
	 */
	void remove(const K& key);

	/**
	 * Returns whether or not a node is in the AVLTree.
	 */
	V find(const K& key) const;

	/**
	 * Returns the height of a tree, or -1 if the tree is empty.
	 */
	int heightOrNeg1(const Node*& t) const;

	/**
	 * Prints the AVLTree (default to stdout).
	 */
	void print(ostream& os = std::cout);

	friend ostream& operator<<(ostream& os, const AVLTree& tree)
	{
		tree.print(os);
		return os;
	}

private:

	/**
	 * The root of the AVLTree.
	 */
	Node* root;

	/**
	 * Frees memory of the AVL tree.
	 */
	 void clear(Node* subRoot);

	/**
	 * Private recursive helper function for public #insert function.
	 */
	void insert(Node*& subRoot, const K& key, const V& value);

	/**
	 * Private recursive helper function for public #find function.
	 */
	V find(Node* subRoot, const K& key) const;

	/**
	 * Returns 1 + the max height of a tree's subtrees.
	 */
	int height(Node* subRoot) const;

	/**
	 * Rotates the tree left (there is an imbalance on the right side).
	 */
	void rotateLeft(Node*& subRoot);

	/**
	 * Rotates the tree right (there is an imbalance on the left side).
	 */
	void rotateRight(Node*& subRoot);

	/**
	 * Performs a left-right rotation.
	 * Simply calls leftRotate and rightRotate.
	 */
	void rotateLeftRight(Node*& subRoot);

	/**
	 * Performs a right-left rotation.
	 * Simply valls rightRotate and leftRotate.
	 */
	void rotateRightLeft(Node*& subRoot);

	/**
	 * Rebalances a node by performing the appropriate rotations.
	 * If no rotations are required, still updates the nodes height.
	 */
	void balance(Node*& subRoot);

	/**
	 * Helper function for #operator= and AVLTree(const AVLTree&).
	 */
	Node *copy(const Node* subRoot);
};

#endif

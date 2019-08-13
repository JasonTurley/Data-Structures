/**
 * @file binarytree.h
 * Declaration of the BinaryTree class. Contains member and helper functions.
 *
 * @date (modified) 4 August 2018
 */
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <cstddef>

using std::ostream;

/**
 * The BinaryTree class represents a templated linked-memory data structure.
 */
template <typename T>
class BinaryTree
{
    private:
        /**
         * Represents a tree node, a piece of data within a BinaryTree.
         */
        struct Node {
            T data;
            Node* left;
            Node* right;

            /**
             * Node constructor; the left and right children are set to
             * nullptr.
             * @param data The info to store in the tree.
             */
            Node(const T& data) : data(data), left(nullptr), right(nullptr)
            { /* nothing */
            }
        };

    public:
        /**
         * Constructs a BinaryTree.
         */
        BinaryTree();

        /**
         * Copy Constructor.
         * @param other The BinaryTree to copy.
         */
        BinaryTree(const BinaryTree& other);

        /**
         * Destructor; releases memory held in tree nodes.
         */
        ~BinaryTree();

        /**
         * Assignment operator.
         * @param rhs The tree to make a copy of.
         * @return A reference to the current tree.
         */
        const BinaryTree& operator=(const BinaryTree& rhs);

	/**
	 * Output operator.
	 * @param os The output stream to print to.
	 */
	friend ostream& operator<<(ostream& os, const BinaryTree<T>& tree)
	{
		tree.print(os);
		return os;
	}

        /**
         * Inserts a node into the tree.
         * @oaram data The data to insert into the tree.
         */
        void insert(const T& data);

        /**
         * Checks if the data is present in the tree.
         * @param data The data to look for.
         * @return Whether or not data is in the tree.
         */
        bool search(const T& data) const;

        /**
         * Removes a node from the tree.
         * @param data The data to remove.
         */
        void remove(const T& data);

        /**
         * Returns the height of a tree.
         * @return Tree hieght.
         */
        int height() const;

        /**
         * The number of nodes in a tree.
         * @return Size of tree
         */
        size_t size() const
        {
            return size_;
        }

	/**
	 * Returns the smallest value in the tree.
	 */
	const T& getMinValue() const;

	/**
	 * Returns the greates value in the tree.
	 */
	const T& getMaxValue() const;


private:

        Node* root;

        size_t size_;

	Node* getRoot() const { return root; }
        /**
         * Helper function for inserting a node into the tree.
         * @param subRoot current node in tree.
         * @param data The data to insert.
         */
        void insert(Node*& subRoot, const T& data);

        /**
         * Helper function for finding a node in tree.
         * @param subRoot current node in tree.
         * @param data The data to find.
         */
        bool search(const Node* subRoot, const T& data) const;

	/**
	 * Helper function for removing a node.
	 */
	Node* remove(Node* subRoot, const T& data);

        /**
         * Helper function for finding height of a tree.
         * @param subRoot The root of a tree.
         * @return Tree height.
         */
        int height(const Node* subRoot) const;

	/**
	 * Returns a pointer to the node with the smallest data.
	 * @return Node with smallest data.
	 */
	Node *findMin(Node* subRoot) const;

	/**
	 * Returns a pointer to the node with the greatest data.
	 * @return Node with greatest data.
	 */
	Node *findMax(Node* subRoot) const;


        /**
         * Helper function for operator= and cctor.
         * @param subRoot The root to copy.
         * @return A pointer to an allocated node
         */
        Node* copy(const Node* subRoot);

        /**
         * Deletes tree.
         * @param subRoot The root of the tree to delete.
         */
        void clear(Node* subRoot);

	/**
	 * Prints the contents of the tree in increasing order.
	 */
	void print(ostream& os) const;

	/**
	 * Helper function to recursively print the tree
	 */
	void print(ostream& os, const Node* subRoot) const;

};

#endif

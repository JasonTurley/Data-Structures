/**
 * @file AVLTree.h
 * Declaration of the AVLTree class. An AVLTree is a common self-balancing
 * Binary Search Tree. This guarantees O(logN) operations.
 *
 * @author Jason Turley
 * @date 11 August 2018
 */

#ifndef AVLTREE_H
#define AVLTREE_H

/**
 * The AVLTree class represents a memory linked AVL Tree.
 */
class AVLTree
{
private:
    /**
     * Node represents an element in an AVLTree. It contains a data,
     * pointers to its left and right elements, and its height.
     */
    struct Node {
        int data;
        Node* left;
        Node* right;
        int height;

        /**
         * Node constructor.
         */
        Node(const int& ndata)
            : data(ndata), left(nullptr), right(nullptr), height(0)
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
     * Releases memory consumed by AVLTree.
     */
    ~AVLTree();

    /**
     * Adds a node with `ndata` into an AVLTree.
     */
    void insert(const int& ndata);

    /**
     * Returns whether or not a node with `data` is in the AVLTree.
     */
    bool find(const int& data) const;
    /**
     * Returns the height of a node; that is, the length of the longest path
     * from that node to a leaf.
     */
    int height() const;


private:

    Node* root;

	/**
	 * Frees memory of the tree.
	 */
	 void clear(Node*& subRoot);
    /**
     * Private recursive helper function for public #insert function.
     */
    void insert(Node*& subRoot, const int& data);

    /**
     * Private recursive helper function for public #find function.
     */
    bool find(Node*& subRoot, const int& data);

    /**
     * Private recursive helper function for public #height function.
     */
    int height(const Node* subRoot) const;

    /**
     * Rotates the tree left-wards (There is an imbalance on the right side).
     */
    void leftRotate(Node*& subRoot);

    /**
     * Rotates the tree right-wards (There is an imbalance on the left side).
     */
    void rightRotate(Node*& subRoot);

    /**
     * Performs a left-right rotation.
     * Simply calls leftRotate and rightRotate.
     */
    void leftRightRotate(Node*& subRoot);

    /**
     * Performs a right-left rotation.
     * Simply valls rightRotate and leftRotate.
     */
    void rightLeftRotate(Node*& subRoot);

    /**
     */
    void balance(Node*& subRoot);
};

#endif

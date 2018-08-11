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
     * Node represents an element in an AVLTree. It contains a value,
     * pointers to its left and right elements, and its height.
     */
    struct Node {
        int value;
        Node* left;
        Node* right;
        int height;
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
     * Adds a node with `value` into an AVLTree. 
     */
    void insert(const int& value) const;

    /**
     * Returns whether or not a node with `value` is in the AVLTree.
     */
    bool find(const int& value) const;
    /**
     * Returns the height of a node; that is, the length of the longest path
     * from that node to a leaf.
     */
    int height() const;


private:

    Node* root;
    
    /**
     * Private recursive helper function for public #insert function.
     */
    void insert(Node*& node, const int& value);

    /**
     * Private recursive helper function for public #find function.
     */
    bool find(Node*& node, const int& value);

    /**
     * Private recursive helper function for public #height function. 
     */
    int height(Node*& node) const;

    /**
     * Returns the height of the given node.
     */
    inline int getNodeHeight(Node*& node) const { return node->height; }

    /**
     * Rotates the tree left-wards (There is an imbalance on the right side).
     */
    void leftRotate(Node*& node);

    /**
     * Rotates the tree right-wards (There is an imbalance on the left side).
     */
    void rightRotate(Node*& node);

    /**
     * Performs a left-right rotation.
     * Simply calls leftRotate and rightRotate.
     */
    void leftRightRotate(Node*& node);

    /**
     * Performs a right-left rotation.
     * Simply valls rightRotate and leftRotate.
     */
    void rightLeftRotate(Node*& node);
    
    /**
     * Returns the balance factor of a current node; that is, the difference
     * between the node's left and right sub-trees.
     */
    int balanceFactor(Node*& node);

    /**
     * If necessary, rebalances an AVLTree after insertion.
     */
    void rebalance(Node*& node);
};

#endif

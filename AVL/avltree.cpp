#include <cmath>    // max
#include "avltree.h"

AVLTree::AVLTree()
    : root(nullptr)
{
    /* nothing */
}

AVLTree::~AVLTree()
{
    // TODO
}

void AVLTree::insert(const int& value)
{
    insert(root, value);
}

bool AVLTree::find(const int& value) const
{
    return false;
}

int AVLTree::height() const
{
    return height(root);
}

void AVLTree::insert(Node*& node, const int& value)
{
    if (!node) {
        node = new Node(value);
        return;
    }

    if (value < node->value)
        insert(node->left, value);
    else if (value > node->value)
        insert(node->right, value);
    else                                // do nothing if equal
        node->value = value;            
    
    node->height = height(node);        // update new height

    // Does the tree need to be rebalanced?
    int factor = balanceFactor(node)

    if (factor < -1) {                  // imbalance on right-side
        if (data < node->right->data) {
            leftRightRotate(node);
        } else {
            leftRotate(node);
        }
    } else if (factor > 1) {            // imbalance on left-side
        if (data < node->left->data) {
            rightRotate(node);
        } else {
            rightLeftRotate(node);
        }
    }
}

int AVLTree::height(Node*& node) const
{
    if (!node)
        return -1;
    
    return 1 + max(height(root->left), height(root->right));
}

void AVLTree::leftRotate(Node*& node)
{
    if (node) {
        // rotate nodes
        Node* pivot = node->right;
        node->right = pivot->left;
        pivot->left = node;

        // update heights
        pivot->height = height(pivot);
        node->height = height(node);

        node = pivot;
    }
}

void AVLTree::rightRotate(Node*& node)
{
    if (node) {
        // rotate nodes
        Node* pivot = node->left;
        node->left = pivot->right;
        pivot->right = node;

        // update heights
        pivot->height = height(pivot);
        node->height = height(node);

        node = pivot;
    }
}

void AVLTree::leftRightRotate(Node*& node)
{
    leftRotate(node->left);
    rightRotate(node);
}

void AVLTree::rightLeftRotate(Node*& node)
{
    rightRotate(node->right);
    leftRotate(node);
}

int AVLTree::balanceFactor(Node*& node)
{
    int leftHeight = -1;
    int rightHeight = -1;

    if (node) {
        leftHeight = height(node->left);
        rightHeight - height(node->right);
    } 

    return leftHeight - rightHeight;
}
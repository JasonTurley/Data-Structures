#include "avltree.h"

#define max(x, y) ((x) > (y) ? (x) : (y))

AVLTree::AVLTree()
    : root(nullptr)
{
    /* nothing */
}

AVLTree::~AVLTree()
{
        clear(root);
}

void AVLTree::clear(Node*& subRoot)
{
        if (subRoot) {
                clear(subRoot->left);
                clear(subRoot->right);
                delete subRoot;
        }
}

void AVLTree::insert(const int& ndata)
{
    insert(root, ndata);
}

bool AVLTree::find(const int& ndata) const
{
    return false;
}

int AVLTree::height() const
{
    return height(root);
}

void AVLTree::insert(Node*& subRoot, const int& ndata)
{
        if (subRoot == nullptr)
                subRoot = new Node{ndata};
        else if (ndata < subRoot->data)
                insert(subRoot->left, ndata);
        else if (ndata > subRoot->data)
                insert(subRoot->right, ndata);

        balance(subRoot);
}

int AVLTree::height(const Node* subRoot) const
{
        return (subRoot == nullptr) ? -1 : subRoot->height;
}

void AVLTree::leftRotate(Node*& subRoot)
{
    if (subRoot) {
        // rotate nodes
        Node* pivot = subRoot->right;
        subRoot->right = pivot->left;
        pivot->left = subRoot;

        // update heights
        pivot->height = max(height(pivot->left), height(pivot->right)) + 1;
        subRoot->height = max(height(subRoot->right), subRoot->height) + 1;

        subRoot = pivot;
    }
}

void AVLTree::rightRotate(Node*& subRoot)
{
    if (subRoot) {
        // rotate nodes
        Node* pivot = subRoot->left;
        subRoot->left = pivot->right;
        pivot->right = subRoot;

        // update heights
        pivot->height = max(height(pivot->left), height(pivot->right)) + 1;
        subRoot->height = max(height(subRoot->left), subRoot->height) + 1;

        subRoot = pivot;
    }
}

void AVLTree::leftRightRotate(Node*& subRoot)
{
    leftRotate(subRoot->left);
    rightRotate(subRoot);
}

void AVLTree::rightLeftRotate(Node*& subRoot)
{
    rightRotate(subRoot->right);
    leftRotate(subRoot);
}

void AVLTree::balance(Node*& subRoot)
{
        if (subRoot == nullptr)
                return;

        if (height(subRoot->left) - height(subRoot->right) > 1) {
                if (height(subRoot->left->left) >= height(subRoot->left->right))
                        rightRotate(subRoot);
                else
                        leftRightRotate(subRoot);
        } else if (height(subRoot->right) - height(subRoot->left) > 1) {
                if (height(subRoot->right->right) > height(subRoot->right->left))
                        leftRotate(subRoot);
                else
                        rightRotate(subRoot);

        }

        subRoot->height =
                max(height(subRoot->left), height(subRoot->right)) + 1;
}



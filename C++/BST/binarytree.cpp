
#include "binarytree.h"

using namespace std;

template <typename T>
BinaryTree<T>::BinaryTree() 
    : root(nullptr), size_(0)
{   /* nothing */
}

template <typename T>
BinaryTree<T>::BinaryTree(const BinaryTree& other)
    : root(copy(other.root))
{   /* nothing */
}

template <typename T>
BinaryTree<T>::~BinaryTree()
{
    // TODO
}

template <typename T>
const BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree<T>& rhs)
{
    if (this != &rhs) {         // avoid self assignment
        clear(root);
        root = copy(rhs.root);
    }
    return *this;
}

template <typename T>
void BinaryTree<T>::insert(const T& data)
{
    insert(root, data);
}

template <typename T>
void BinaryTree<T>::insert(Node*& subRoot, const T& data)
{
    if (subRoot) {
        if (data <= subRoot->data)
            insert(subRoot->left, data);
        else
            insert(subRoot->right, data);
    } else {
        subRoot = new Node(data);
        size_++;
    }
}

template <typename T>
bool BinaryTree<T>::search(const T& data) const
{
    return search(root, data);
}

template <typename T>
bool BinaryTree<T>::search(const Node* subRoot, const T& x) const
{
    if (subRoot == nullptr)
        return false;

    else if (subRoot->data == x)
        return true;
    else if (x < subRoot->data)
        return search(subRoot->left, x);
    else
        return search(subRoot->right, x);
}

template <typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::copy(const Node* subRoot)
{
    if (subRoot) {
        Node* newNode = new Node(subRoot->data);
        newNode->left = copy(subRoot->left);
        newNode->right = copy(subRoot->right);

        return newNode;
    }

    return nullptr;
}

template <typename T>
void BinaryTree<T>::clear(Node* subRoot)
{
    // post order traveral
    if (subRoot) {
        clear(subRoot->left);
        clear(subRoot->right);
        delete subRoot;
    }
}

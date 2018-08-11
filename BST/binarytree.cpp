
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
void BinaryTree<T>::insert(const Node* subRoot, const T& data)
{
    // Insert the node and increase the size
    if (subRoot == nullptr) {
        subRoot = new Node(data);
        size_++;
    }

    else if (data < subRoot->data)
        insert(subRoot->left, data);
    else
        insert(subRoot->right, data);
}

template <typename T>
bool BinaryTree<T>::search(const T& data) const
{
    if (root == nullptr)
        return false;

    if (root->data == data)
        return true;
    else if (data < root->data)
        search(root->left);
    else
        search(root->right);
}

template <typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::copy(const Node* subRoot)
{
    if (subRoot == nullptr)
        return nullptr;

    Node* newNode = new Node(subRoot->data);
    newNode->left = copy(subRoot->left);
    newNode->right = copy(subRoot->right);

    return newNode;
}

template <typename T>
void BinaryTree<T>::clear(Node* subRoot)
{
    if (subRoot == nullptr)
        return;

    // post order traveral
    clear(subRoot->left);
    clear(subRoot->right);
    delete subRoot;
}

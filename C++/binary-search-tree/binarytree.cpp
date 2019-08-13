
#include "binarytree.h"

#define max(a, b) ((a) > (b) ? (a) : (b))

#define IS_LEAF(ptr) ((!ptr->left) && (!ptr->right))
#define HAS_ONE_CHILD(ptr) ((ptr->left && !ptr->right) || (!ptr->left && ptr->right))

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
	clear(root);
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
void BinaryTree<T>::remove(const T& x)
{
        remove(root, x);
}

template <typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::remove(Node* subRoot, const T& x)
{
        if (!subRoot) return nullptr;
        else if (x < subRoot->data) subRoot->left  = remove(subRoot->left, x);
        else if (x > subRoot->data) subRoot->right = remove(subRoot->right, x);
        else {
                // We found the node to remove! How many children does it have?
                if (IS_LEAF(subRoot)) {
                        delete subRoot;
                        subRoot = nullptr;
                } else if (HAS_ONE_CHILD(subRoot)) {
                        Node *ptr = subRoot;
                        if (subRoot->left)
                                subRoot = subRoot->left;
                        else
                                subRoot = subRoot->right;

                        delete ptr;
                        ptr = nullptr;
                } else {
                        // Since the smallest value in the right subtree is
                        // greater than all values in the left subtree, make
                        // that the new root.
                        Node *ptr = findMin(subRoot->right);
                        subRoot->data = ptr->data;
                        subRoot->right = remove(subRoot->right, ptr->data);
                }

                size_--;
        }

        return subRoot;
}

template<typename T>
int BinaryTree<T>::height() const
{
	return height(root);
}

template<typename T>
int BinaryTree<T>::height(const Node* subRoot) const
{
	if (!subRoot)
		return 0;

	int leftHeight = height(subRoot->left);
	int rightHeight = height(subRoot->right);

	return 1 + max(leftHeight, rightHeight);
}

template <typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::findMin(Node* subRoot) const
{
	Node* ptr = subRoot;

	while (ptr && ptr->left)
		ptr = ptr->left;

	return ptr;
}

template <typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::findMax(Node* subRoot) const
{
	Node* ptr = subRoot;

	while (ptr && ptr->right)
		ptr = ptr->right;

	return ptr;
}

template <typename T>
const T& BinaryTree<T>::getMinValue() const
{
        // No error check
        Node *ptr = findMin(root);
        return ptr->data;
}

template <typename T>
const T& BinaryTree<T>::getMaxValue() const
{
        // No error check
        Node *ptr = findMax(root);
        return ptr->data;
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

template <typename T>
void BinaryTree<T>::print(ostream &os) const
{
	print(os, root);
}

template <typename T>
void BinaryTree<T>::print(ostream &os, const Node* subRoot) const
{
        if (subRoot) {
                print(os, subRoot->left);
                os << subRoot->data << " ";
                print(os, subRoot->right);
        }
}

template class BinaryTree<int>;

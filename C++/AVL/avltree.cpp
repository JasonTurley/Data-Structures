#include "avltree.h"

#define max(x, y) ((x) > (y) ? (x) : (y))

template <class K, class V>
AVLTree<K, V>::AVLTree()
    : root(nullptr)
{
    /* nothing */
}

template <class K, class V>
AVLTree<K, V>::AVLTree(const AVLTree& other)
{
	copy(other.root);
}

template <class K, class V>
const AVLTree<K, V>& AVLTree<K, V>::operator=(const AVLTree& rhs)
{
	if (this != &rhs) {	                // avoid self assignemnt
		clear(this->root);	        // free previous memory
		this->root = copy(rhs.root);
	}

	return *this;
}

template <class K, class V>
AVLTree<K, V>::~AVLTree()
{
        clear();
}

template <class K, class V>
void AVLTree<K, V>::clear()
{
	clear(root);
	root = nullptr;
}

template <class K, class V>
typename AVLTree<K, V>::Node* AVLTree<K, V>::copy(const Node* subRoot)
{
	if (subRoot) {
		// Recursively copy this node and its children
		Node* newNode = new Node(subRoot->key, subRoot->value);
		newNode->left = copy(subRoot->left);
		newNode->right = copy(subRoot->right);

		return newNode;
	}

	return nullptr;
}

template <class K, class V>
void AVLTree<K, V>::clear(Node* subRoot)
{
	if (subRoot) {
		clear(subRoot->left);
		clear(subRoot->right);
		delete subRoot;
	}
}

template <class K, class V>
void AVLTree<K, V>::insert(const K& key, const V& value)
{
        insert(root, key, value);
}

template <class K, class V>
void AVLTree<K, V>::insert(Node*& subRoot, const K& key, const V& value)
{
        if (subRoot == nullptr)
                subRoot = new Node {key, value};
        else if (key < subRoot->key)
                insert(subRoot->left, key, value);
        else if (key > subRoot->key)
                insert(subRoot->right, key, value);
        else
                return; // no duplicates

        //FIXME balance(subRoot);
}

template <class K, class V>
V AVLTree<K, V>::find(const K& key) const
{
        return find(root, key);
}

template <class K, class V>
V AVLTree<K, V>::find(Node* subRoot, const K& key) const
{
        if (subRoot == nullptr)
                return V();
        else if (key < subRoot->key)
                return find(subRoot->left, key);
        else if (key > subRoot->key)
                return find(subRoot->right, key);
        else
                return subRoot->value;
}

template <class K, class V>
int AVLTree<K, V>::height(Node* subRoot) const
{
        if (subRoot == nullptr)
                return -1;

        return 1 + max(height(subRoot->left), height(subRoot->right));
}

template <class K, class V>
int AVLTree<K, V>::heightOrNeg1(const Node*& t) const
{
        return (t == nullptr) ? -1 : t->height;
}



template class AVLTree<std::string, std::string>;

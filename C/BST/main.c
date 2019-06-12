#include <stdio.h>
#include <assert.h>

#include "binary_search_tree.h"

void test_insert()
{
	struct Node *root = NULL;
	root = insert(root, 12);
	root = insert(root, 20);
	root = insert(root, 50);
	root = insert(root, 8);

	assert(height(root) == 2);

	printInOrder(root);

	root = del(root, 8);
	root = del(root, 50);
	root = del(root, 20);
	root = del(root, 12);

	assert(height(root) == 0);

	printInOrder(root);
}

void test_all()
{
	test_insert();
}

int main()
{
	test_all();
	return 0;
}

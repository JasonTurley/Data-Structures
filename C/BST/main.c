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

	root = delete_value(root, 8);
	root = delete_value(root, 50);
	root = delete_value(root, 20);
	root = delete_value(root, 12);

	assert(height(root) == 0);

	printInOrder(root);
}

void test_find_min()
{
	struct Node *root = NULL;

	int x = find_min(root);

	printf("min: %d\n", x);
}

void test_delete_tree()
{
	struct Node *root = NULL;

	assert(height(root) == 0);

	root = insert(root, 25);
	root = insert(root, 40);
	root = insert(root, 17);

	assert(height(root) == 2);

	root = delete_tree(root);

	assert(height(root) == 0);
}

void test_all()
{
	test_insert();
	test_find_min();
	test_delete_tree();
}

int main()
{
	test_all();
	return 0;
}

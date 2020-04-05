#include <stdio.h>
#include <assert.h>

#include "binary_search_tree.h"

void test_insert()
{
	struct bst_node *root = NULL;

	root = insert(root, 12);
	root = insert(root, 20);
	root = insert(root, 50);
	root = insert(root, 8);

	print_tree(root);
	assert(get_height(root) == 2);

	root = delete_value(root, 8);
	root = delete_value(root, 50);
	root = delete_value(root, 20);
	root = delete_value(root, 12);

	assert(get_height(root) == 0);

}

void test_find_min()
{
	struct bst_node *root = NULL;

	int x = find_min(root);

	printf("min: %d\n", x);
}

void test_delete_tree()
{
	struct bst_node *root = NULL;

	assert(get_height(root) == 0);

	root = insert(root, 25);
	root = insert(root, 40);
	root = insert(root, 17);

	assert(get_height(root) == 2);

	root = delete_tree(root);

	assert(get_height(root) == 0);
}

void test_delete_value()
{
	struct bst_node *root = NULL;

	root = insert(root, 30);
	root = insert(root, 20);
	root = insert(root, 50);
	root = insert(root, 40);
	root = insert(root, 15);

	printf("Tree before deletion (no childern): \n");
	print_tree(root);

	delete_value(root, 15);

	print_tree(root);
	printf("\nTree after deletion (no childern): \n");
	printf("\n");
}

void test_all()
{
	test_insert();
	test_find_min();
	test_delete_tree();
	test_delete_value();
}

int main()
{
	test_all();
	return 0;
}

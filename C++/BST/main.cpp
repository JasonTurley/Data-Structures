
#include <iostream>
#include <cassert>
#include "binarytree.h"


int main()
{
    BinaryTree<int> binary_tree;

    binary_tree.insert(20);
    binary_tree.insert(10);
    binary_tree.insert(30);
    
    printf("Tree size: %zd\n", binary_tree.size());
    assert(binary_tree.size() == 3);

    // Test search
    assert(binary_tree.search(20) == true);
    assert(binary_tree.search(10) == true);
    assert(binary_tree.search(-6) == false);

    return 0;
}

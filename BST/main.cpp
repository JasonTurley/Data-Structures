
#include <iostream>
#include <cassert>
#include "binarytree.h"


int main()
{
    BinaryTree<int> binary_tree;

    binary_tree.insert(20);
    binary_tree.insert(10);
    binary_tree.insert(30);
    
    assert(binary_tree.size() == 3);

    assert(binary_tree.search(10) == true);
    assert(binary_tree.search(30) == true);
    assert(binary_tree.search(45) == false);

    return 0;
}

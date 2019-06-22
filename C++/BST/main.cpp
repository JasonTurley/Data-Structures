#include <iostream>
#include <cassert>

#include "binarytree.h"

using std::cout;
using std::endl;

void testInsert()
{
        BinaryTree<int> bt;

        bt.insert(20);
        bt.insert(10);
        bt.insert(30);
        bt.insert(25);
        bt.insert(7);

        assert(bt.size() == 5);
        assert(bt.height() == 3);
}

void testSearch()
{
        BinaryTree<int> bt;

        bt.insert(20);
        bt.insert(10);
        bt.insert(30);
        bt.insert(25);
        bt.insert(7);

        assert(bt.search(10) == true);
        assert(bt.search(400) == false);
}

void testGetMinValue()
{
        BinaryTree<int> bt;

        bt.insert(20);
        bt.insert(12);
        bt.insert(30);
        bt.insert(17);
        bt.insert(8);
        bt.insert(27);
        bt.insert(40);
        bt.insert(15);

        assert(bt.getMinValue() == 8);
}

void testGetMaxValue()
{
        BinaryTree<int> bt;

        bt.insert(20);
        bt.insert(12);
        bt.insert(30);
        bt.insert(17);
        bt.insert(8);
        bt.insert(27);
        bt.insert(40);
        bt.insert(15);

        assert(bt.getMaxValue() == 40);
}

void testRemove()
{
        BinaryTree<int> bt;

        bt.insert(20);
        bt.insert(12);
        bt.insert(30);
        bt.insert(17);
        bt.insert(8);
        bt.insert(27);
        bt.insert(40);
        bt.insert(15);

        cout << "Tree before removal(leaf): \n";
        cout << bt << endl;

        // remove leaf node
        bt.remove(8);
        cout << "Tree after removal(leaf): \n";
        cout << bt << endl;

        cout << "Tree before removal(1 child): \n";
        cout << bt << endl;

        // remove one child node
        bt.remove(17);
        cout << "Tree after removal(1 child): \n";
        cout << bt << endl;

        cout << "Tree before removal(2 children): \n";
        cout << bt << endl;

        // remove one child node
        bt.remove(20);
        cout << "Tree after removal(2 children): \n";
        cout << bt << endl;


}

void testAll()
{
        testInsert();
        testSearch();
        testGetMinValue();
        testGetMaxValue();
        testRemove();
}

int main()
{
        testAll();
        return 0;
}

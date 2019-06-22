#include <cassert>
#include <iostream>

#include "avltree.h"

using std::cout;
using std::endl;

void testInsert()
{
        AVLTree tree;

        tree.insert(50);
        tree.insert(40);
        tree.insert(30);
        tree.insert(20);

        cout << tree.height() << endl;
}

void testAll()
{
        testInsert();
}

int main()
{
        testAll();

        return 0;
}

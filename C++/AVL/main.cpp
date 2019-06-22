#include <cassert>
#include <iostream>
#include <string>

#include "avltree.h"

using std::cout;
using std::endl;
using std::string;

void testFind()
{
        AVLTree<string, string> tree;

        tree.insert("C", "C++");
        tree.insert("int", "bool");
        tree.insert("char *", "string");
        tree.insert("malloc", "new");
        tree.insert("free", "delete");

        cout << "find(C) -> " << tree.find("C") << endl;
        cout << "find(int) -> " << tree.find("int") << endl;
        cout << "find(malloc) -> " << tree.find("malloc") << endl;
        cout << "find(char *) -> " << tree.find("char *") << endl;
        cout << "find(free) -> " << tree.find("free") << endl;
        cout << "find(not-in-tree) -> " << tree.find("not-in-tree") << endl;
}

void testAll()
{
        testFind();
}

int main()
{
        testAll();


        return 0;
}

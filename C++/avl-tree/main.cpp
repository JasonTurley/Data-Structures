#include <cassert>
#include <iostream>
#include <string>

#include "avltree.h"

using std::cout;
using std::endl;
using std::string;

void printBefore(string rotationDirection)
{
        cout << "Tree before " << rotationDirection << " rotation:\n";
}

void printAfter(int n)
{
        cout << "Tree after inserting " << n << endl;
}

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

        cout << tree << endl;
}

void testRotateLeft()
{
        AVLTree<int, int> tree;

        tree.insert(8, 8);
        tree.insert(6, 6);
        tree.insert(10, 10);
        tree.insert(15, 15);

        printBefore("left");
        cout << tree << endl;

        tree.insert(26, 26);
        printAfter(26);
        cout << tree << endl;
}

void testRotateRight()
{
        AVLTree<int, int> tree;

        tree.insert(30, 30);
        tree.insert(20, 20);
        tree.insert(40, 40);
        tree.insert(10, 10);

        printBefore("right");
        cout << tree << endl;

        tree.insert(7, 7);
        printAfter(7);
        cout << tree << endl;
}

void testRotateLeftRight()
{
        AVLTree<int, int> tree;

        tree.insert(20, 20);
        tree.insert(10, 10);
        tree.insert(30, 30);
        tree.insert(7, 7);

        printBefore("left-right");
        cout << tree << endl;

        tree.insert(9, 9);
        printAfter(9);
        cout << tree << endl;
}

void testRotateRightLeft()
{
        AVLTree<int, int> tree;

        tree.insert(20, 20);
        tree.insert(10, 10);
        tree.insert(30, 30);
        tree.insert(50, 50);

        printBefore("right-left");
        cout << tree << endl;

        tree.insert(40, 40);
        printAfter(40);
        cout << tree << endl;

}

void testAll()
{
        testFind();
        testRotateLeft();
        testRotateRight();
        testRotateLeftRight();
        testRotateRightLeft();
}

int main()
{
        testAll();


        return 0;
}

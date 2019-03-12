#include <iostream>
#include <string>

#include "hashtable.h"

using namespace std;

int main()
{
    HashTable myhash;

    myhash.insert("Jason", "red");
    myhash.insert("Paul", "blue");
    myhash.insert("Jalen", "");
    myhash.insert("Dad", "pink");
    myhash.insert("Bran", "yellow");

    size_t n = myhash.elements();

    cout << "num elems before remove: " << n << endl;

    myhash.remove("Paul");

    n = myhash.elements();

    cout << "num elems after remove: " << n << endl;
    return 0;
}

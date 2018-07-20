#include <iostream>
#include <string>

#include "hash.h"

using namespace std;

int main()
{
    Hash myhash;

    myhash.insert("Jason", "red");
    myhash.insert("Paul", "blue");
    myhash.insert("Jalen", "");
    myhash.insert("Dad", "pink");
    myhash.insert("Bran", "yellow");

    cout << "remove('Bran'): " << myhash.remove("Bran") << endl;
    return 0;
}

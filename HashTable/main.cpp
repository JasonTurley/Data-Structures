#include <iostream>
#include <string>

#include "hash.h"

using namespace std;

int main()
{
    Hash myhash;

    myhash.insert("Jason", "red");
    myhash.insert("Paul", "blue");

    cout << "remove('Paul'):" << myhash.remove("Paul") << endl;

    return 0;
}

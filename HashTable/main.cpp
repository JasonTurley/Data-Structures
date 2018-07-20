#include <iostream>
#include <string>

#include "hash.h"

using namespace std;

int main()
{
    Hash myhash;

    myhash.insert("Jason", "red");
    myhash.insert("Paul", "blue");

    bool ret = myhash.search("Jason");
    bool ret2 = myhash.search("Sarah");

    cout << "Jason in list?" << ret << endl;
    cout << "Sarah in list?" << ret2 << endl;

    return 0;
}

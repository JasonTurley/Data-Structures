/**
 * Driver function.
 */

#include <iostream>
#include <string>

#include "queue.h"

using namespace std;

int main() {
    Queue q;
    q.enqueue(4);
    q.enqueue(3);

    cout << "size: " << q.size() << endl;

    return 0;
}

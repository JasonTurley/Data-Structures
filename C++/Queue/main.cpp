#include <iostream>

#include "queue.h"

using namespace std;

int main()
{
        Queue<int> q(10);

        cout << "size: " << q.size() << endl;
        cout << "capacity: " << q.capacity() << endl;

        cout << "front: " << q.front() << endl;
        cout << "back: " << q.back() << endl;

        return 0;
}

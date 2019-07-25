#include <cassert>
#include <iostream>

#include "queue.h"

using namespace std;

void testCopyConstrcutor()
{
        Queue<int> q1(4);

        q1.enqueue(100);
        q1.enqueue(200);

        Queue<int> q2 = q1;

        assert(q1.getSize() == q2.getSize());
        assert(q1.getCapacity() == q2.getCapacity());
        assert(q1.getFront() == q2.getFront());
        assert(q1.getBack() == q2.getBack());
}

void testEnqueue()
{
        const int N = 10;
        Queue<int> q(N);

        assert(q.empty() == true);

        // fill queue halfway
        for (int i = 1; i <= N/2; i++)
                q.enqueue(i);

        assert(q.getCapacity() == N);
        assert(q.getSize() == N/2);
        assert(q.getFront() == 1);
        assert(q.getBack() == N/2);
        assert(q.full() == false);

}

void testDequeue()
{
        const int N = 7;
        Queue<int> q(N);

        for (int i = 1; i <= N; i++)
                q.enqueue(i);

        assert(q.full() == true);

        for (int i = 1; i <= N; i++) {
                int ret = q.dequeue();
                assert(ret == i);
        }

        assert(q.empty() == true);
}

void testAll()
{
        testEnqueue();
        testDequeue();
        testCopyConstrcutor();
}

int main()
{
        testAll();

        return 0;
}

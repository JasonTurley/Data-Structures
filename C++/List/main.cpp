#include <iostream>
#include <cassert>

#include "list.h"

using namespace std;

void test_insert()
{
        #define N (10)

        List<int> list1;

        for (int i = 0; i < N; i++)
                list1.insertFront(i + 1);

        assert(list1.size() == N);

        list1.print();
}

int main()
{
        test_insert();

	return 0;
}

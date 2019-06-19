#include <iostream>
#include <cassert>

#include "list.h"

using namespace std;

#define N (10)

void test_insert()
{

        List<int> list1;

        for (int i = 0; i < N; i++)
                list1.insertFront(i + 1);

        assert(list1.size() == N);

        list1.print();
}

void test_front_back()
{
	List<int> list1;

	for (int i = 0; i < N + N; i++)
		list1.insertBack(i);

	assert(list1.front() == 0);
	assert(list1.back() == N + N - 1);

	assert(list1.size() == N + N);
}

int main()
{
        test_insert();
	test_front_back();

	return 0;
}

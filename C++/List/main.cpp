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

	List<int> list2;

	for (int i = 0; i < N + N; i++)
		list2.insertBack(i);

	assert(list2.front() == 0);
	assert(list2.back() == N + N - 1);

	assert(list2.size() == N + N);
}

void test_erase()
{
        List<int> *list1 = new List<int>();

        for (int i = 0; i < 30; i++)
                list1->insertBack(i);

        assert(list1->size() == 30);

        for (int i = 0; i < 30; i++)
                list1->popFront();

        assert(list1->size() == 0);

        delete list1;
}

void test_all()
{
        test_insert();
        test_erase();
}

int main()
{
        test_all();

	return 0;
}

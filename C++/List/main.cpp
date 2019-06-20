#include <iostream>
#include <cassert>

#include "list.h"

using std::cout;
using std::endl;

#define N (10)

void testInserts()
{
        List<int> list1;

        // test insertFront
        for (int i = 1; i <= N; i++)
                list1.insertFront(i);

        assert(list1.size() == N);

	List<int> list2;

        // test insertBack
	for (int i = 0; i < N; i++)
		list2.insertBack(i);

        assert(list2.size() == N);
}

void testPops()
{
        List<int> list;

        // test popFront
        list.popFront();
        assert(list.empty());

        // test on N element list
        for (int i = 1; i <= N; i++)
                list.insertFront(i);

        for (int i = N; i > 0; i--)
                assert(list.popFront() == i);

        assert(list.empty());
}

void testValueAt()
{
        List<int> list;

        // test on N element list
        for (int i = 0; i < N; i++)
                list.insertBack(i);

        // test value at each index
        for (int i = 0; i < N; i++)
                assert(list.valueAt(i) == i);

        assert(list.size() == N);
}

void testAll()
{
        testInserts();
        testPops();
        testValueAt();
}

int main()
{
        testAll();

	return 0;
}

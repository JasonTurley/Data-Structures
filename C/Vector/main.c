#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

#define N (10)
#define M (24)

void test_push_back()
{
	struct vector *v = vector_create(N);

	assert(v);
	assert(size(v) == 0);
	assert(capacity(v) == MIN_CAPACITY);

	for (int i = 1; i <= N; i++)
		push_back(v, i);

	assert(size(v) == N);

	vector_destroy(v);	// no memory leaks
}

void test_at()
{
	struct vector *v = vector_create(32);

	for (int i = 0; i < M; i++)
		push_back(v, i);

	assert(at(v, 10) == 10);
	assert(at(v, 20) == 20);

	vector_destroy(v);
}

void test_resize()
{
	struct vector *v = vector_create(16);

	for (int i = 1; i <= 24; i++)
		push_back(v, i);

	assert(capacity(v) == 32);
	assert(size(v) == 24);

	vector_destroy(v);
}

void test_insert()
{
	struct vector *v = vector_create(N);
	int elem = 99;
	int index = 4;

	for (int i = 1; i <= N; i++)
		push_back(v, i);

	printf("vector before insert: ");
	print_vector(v);

	insert(v, elem, index);
	printf("vector after insert: ");
	print_vector(v);

	vector_destroy(v);
}

void test_all()
{
	test_push_back();
	test_at();
	test_resize();
	test_insert();
}

int main()
{
	test_all();

   	return 0;
}



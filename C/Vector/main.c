#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

void run_all_tests();

int main()
{
	run_all_tests();

    	return 0;
}


void test_push()
{
	size_t i;
	size_t n = 10;
	struct vector *v = vector_create(n);
	assert(v);
	assert(size(v) == 0);
	assert(capacity(v) == MIN_CAPACITY);

	for (i = 0; i < n; i++)
		push(v, (int) i+1);

	assert(size(v) == n);

	vector_destroy(v);	// no memory leaks
}

void test_at()
{
	struct vector *v = vector_create(32);
	int ret;
	size_t i;

	for (i = 0; i < 16; i++) {
		push(v, (int) i);
		ret = at(v, i);
		assert(ret == (int) i);
	}
	
	vector_destroy(v);
}

void test_resize()
{
	struct vector *v = vector_create(16);
	size_t i;

	for (i = 0; i < 20; i++) 
		push(v, (int) i);

	assert(capacity(v) == 32);
	assert(size(v) == 20);

	vector_destroy(v);
}

void test_insert()
{
	struct vector *v = vector_create(10);
	size_t i;

	for (i = 0; i < 10; i++)
		push(v, (int) i);

	print_vector(v);
	insert(v, 4, 88);
	print_vector(v);

	assert(size(v) == 11);
	assert(at(v, 4) == 88);
	vector_destroy(v);
}

void run_all_tests()
{
	test_push();
	test_at();
	test_resize();
	test_insert();
}

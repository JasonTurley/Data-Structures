#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

void test_push()
{
	size_t i;
	size_t n = 10;
	struct vector *v = vector_create(n);
	assert(v);
	assert(size(v) == 0);
	assert(capacity(v) == MIN_CAPACITY);

	for (i = 0; i < n; i++) {
		push(v, (int) i+1);
	}

	assert(size(v) == n);
}

int main()
{
	test_push();
    	return 0;
}

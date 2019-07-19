#include <assert.h>
#include <stdio.h>

#include "stack.h"

#define N (16)

void test_push()
{
	stack_t *s = stack_create(N);

	for (int i = 1; i <= N; i++)
		push(s, i);

	assert(size(s) == N);

	stack_destroy(s);
}

void test_pop()
{
	stack_t *s = stack_create(N);

	for (int i = 1; i <= N; i++)
		push(s, i);

	assert(size(s) == N);

	for (int i = N; i > 0; i--)
		assert(pop(s) == i);

	assert(size(s) == 0);

	stack_destroy(s);
}

void test_peek()
{
	stack_t *s = stack_create(N);

	for (int i = 1; i <= N; i++)
		push(s, i);

	assert(peek(s) == N);
	assert(size(s) == N);

	stack_destroy(s);
}

void test_is_empty()
{
	stack_t *s = stack_create(N);

	assert(is_empty(s));

	push(s, 1);

	assert(!is_empty(s));

	stack_destroy(s);
}

void test_all()
{
	test_push();
	test_pop();
	test_peek();
	test_is_empty();
}

int main()
{
	test_all();

    return 0;
}

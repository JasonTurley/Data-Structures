#include <stdio.h>
#include <assert.h>

#include "hashtable.h"

void test_create_table()
{
	#define ht1_size 10
	#define ht2_size 100

	hashtable_t *ht1 = create_table(ht1_size);
	hashtable_t *ht2 = create_table(ht2_size);

	assert(ht1 != NULL);
	assert(ht2 != NULL);
	assert(ht1->size == ht1_size);
	assert(ht2->size == ht2_size);

	destroy_table(ht1);
	destroy_table(ht2);
}

void test_exists()
{
	hashtable_t *ht = create_table(17);
	struct pair il = {"Spingfield", "Illinois"};

	assert(exists(ht, il.key) == false);

	insert(ht, &il);

	assert(exists(ht, il.key) == true);

	destroy_table(ht);
}

void test_gets()
{
	hashtable_t *ht = create_table(17);
	struct pair ma = {"Bethesda", "Maryland"};

	assert(get(ht, ma.key) == NULL);

	insert(ht, &ma);

	assert(ht->size == 1);
	assert(get(ht, ma.key) == ma.value);

	destroy_table(ht);
}

void test_all()
{
	test_create_table();
	test_exists();
}

int main()
{
	test_all();

	return 0;
}

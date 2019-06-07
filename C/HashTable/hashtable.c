#include <stdlib.h>
#include <stdio.h>

#include "hashtable.h"

static void* xmalloc(size_t size)
{
	void *ptr = malloc(size);
	if (!ptr) {
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	return ptr;
}

hashtable_t *create_table(size_t tsize)
{
	if (tsize <= 0)
		tsize = 17;

	hashtable_t *ht = xmalloc(sizeof(hashtable_t));

	ht->slots = xmalloc(sizeof(struct pair) * tsize);
	ht->size = 0;
	ht->nelems = 0;

	for (size_t i = 0; i < tsize; i++)
		ht->slots[i] = NULL;

	return ht;
}

void destroy_table(hashtable_t *ht)
{
	for (size_t i = 0; i < ht->size; i++) {
		if (ht->slots[i]) {
			free(ht->slots[i]);
			ht->slots[i] = NULL;
		}
	}

	free(ht);
}

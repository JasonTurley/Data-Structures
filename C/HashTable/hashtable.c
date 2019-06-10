#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "hashtable.h"

/**
 * Error checked malloc.
 */
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
	hashtable_t *ht = xmalloc(sizeof(hashtable_t));

	ht->slots = xmalloc(sizeof(struct pair) * tsize);
	ht->size = tsize;
	ht->nelems = 0;

	for (size_t i = 0; i < tsize; i++)
		ht->slots[i] = NULL;

	return ht;
}

int hash(char *key, size_t tsize)
{
	int h = 0;

	for (size_t i = 0; i < strlen(key); i++)
		h = 33 * h + key[i];

	return h % tsize;
}

void insert(hashtable_t *ht, struct pair *pair)
{
	int hashed_idx = hash(pair->key, ht->size);
	int idx = hashed_idx;

	while (1) {
		if (ht->slots[idx] == NULL || ht->slots[idx]->key == pair->key) {
			if (ht->slots[idx] == NULL)
				ht->slots[idx] = xmalloc(sizeof(struct pair));

			ht->slots[idx]->key = strdup(pair->key);
			ht->slots[idx]->value = strdup(pair->value);

			ht->size++;
			return;
		}

		idx = (idx + 1) % ht->size;

		if (idx == hashed_idx) {
			fprintf(stderr, "Unable to insert into table\n");
			return;
		}
	}
}

char *get(hashtable_t *ht, char *key)
{
	int hashed_idx = hash(key, ht->size);
	int idx = hashed_idx;

	while (1) {
		if (ht->slots[idx])
			if (strcmp(ht->slots[idx]->key, key) == 0)
				return ht->slots[idx]->value;

		idx = (idx + 1) % ht->size;

		if (idx == hashed_idx)
			return NULL;
	}
}

bool exists(hashtable_t *ht, char *key)
{
	char *v = get(ht, key);
	bool ret = (v == NULL ? false : true);

	return ret;
}

void destroy_table(hashtable_t *ht)
{
	for (size_t i = 0; i < ht->size; i++) {
		if (ht->slots[i]) {
			free(ht->slots[i]->key);
			free(ht->slots[i]->value);
			free(ht->slots[i]);
		}
	}

	ht->size = 0;
	free(ht->slots);
	free(ht);
}

/**
 * hashtable.h - implementation of a hash table with linear probing collision
 * resolution strategy.
 *
 * @author: Jason Turley
 * @date: 6 June 2019
 */

#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

// macros
#define LOAD_FACTOR 0.7

struct pair {
	void *key;
	void *value;
};

typedef struct _hashtable {
	struct pair **slots;
	size_t nelems;
	size_t size;
} hashtable_t;

/**
 * Creates a hashtable with `tsize` slots.
 */
hashtable_t *create_table(size_t tsize);

/**
 * Inserts a key-value pair into the hash table.
 */
void insert(hashtable_t ht, void *key, void *value);

/**
 * Returns the value associated with the key.
 */
void *get(hashtable_t ht, void *key);

/**
 * Destroys the given hashtable.
 */
void destroy_table(hashtable_t *ht);

#endif

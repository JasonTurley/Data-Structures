#include <assert.h>
#include <stdlib.h>

#include "vector.h"
#include "utils.h"

vector *vector_create()
{
    vector *v = safe_malloc(sizeof(vector));
    v->array = safe_malloc(sizeof(void *) * INITIAL_CAPACITY);
    v->size = 0;
    v->capacity = INITIAL_CAPACITY;

    return v;
}

size_t vector_size(vector *vec)
{
    assert(vec);
    return vec->size;
}

void *vector_get(vector *vec, size_t n)
{
    assert(vec);

    return vec->array[n];
}

void vector_push_back(vector *vec, void *element)
{
    assert(vec);

    // Test for reallocation
    if (vec->size == vec->capacity) {
        vec->capacity *= GROWTH_FACTOR;
        vec->array = safe_realloc(vec->array, sizeof(void *) * vec->capacity);
    }

    vec->array[vec->size++] = element;
}

void vector_pop_back(vector *vec)
{
    assert(vec);

    if (vec->size == 0) {
        perror("vector is empty");
        return;
    }

    // The next call to vector_push_back() will overwrite current element, thus
    // "removing" it
    vec->size--;
}

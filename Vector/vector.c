#include <assert.h>
#include <stdlib.h>

#include "vector.h"
#include "utils.h"

vector *vector_create()
{
    vector *v = safe_malloc(sizeof(vector));
    v->array = safe_malloc(sizeof(void *) * INITIAL_CAPACITY);
    v->nelems = 0;
    v->capacity = INITIAL_CAPACITY;

    return v;
}

size_t vector_size(vector *vec)
{
    assert(vec);
    return vec->nelems;
}

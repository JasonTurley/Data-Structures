#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

int main()
{
    vector *my_vec = vector_create(); 
    size_t i;
    size_t amount_to_push = 20;

    // add elements to vector
    for (i = 0; i < amount_to_push; i++) {
        vector_push_back(my_vec, &i);
    }
    assert(vector_size(my_vec) == amount_to_push);

    // test vector_destroy
    vector_destroy(&my_vec);

    if (my_vec) {
        printf("Failed to destroy vector\n");
        printf("size: %zd\n", my_vec->size);
    }

    return 0;
}

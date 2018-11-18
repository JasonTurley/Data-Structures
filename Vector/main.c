#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

int main()
{
    vector *my_vec = vector_create(); 
    int i;

    // add elements to vector
    for (i = 0; i < 4; i++) {
        vector_push_back(my_vec, &i);
    }
    assert(vector_size(my_vec) == 4);

    // remove elemets
    for (i = 0; i < 2; i++) {
        vector_pop_back(my_vec);
    }
    assert(vector_size(my_vec) == 2);
    
    int *ret = vector_get(my_vec, 1);
    if (ret) {
        printf("retval: %d\n", *ret);
    }

    return 0;
}

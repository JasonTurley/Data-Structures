#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

int main()
{
    vector *my_vec = vector_create();
    size_t s = vector_size(my_vec);

    printf("Current size %zd\n", s);
    return 0;
}

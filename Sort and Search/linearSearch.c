#include <stdio.h>
#include <stdlib.h>

#define SIZE(n) sizeof(n)/sizeof(n[0]);

// walks through each index of array until it finds target item
// otherwise, returns -1
// tkaes O(n)
int linearSearch(int *arr, size_t size, int target)
{  
 
    for (int i = 0; i < size; i++)
    {
        // We found the item, return its index
        if (arr[i] == target)
            return i;
    }
    // The item was not found 
    return -1;
}

int main(int argc, char **argv[])
{
    int array[] = {4, 23, 1, 6, 90};
    size_t size = SIZE(array);
    int x = 90;

    int result = linearSearch(array, size, x);
    (result == -1) ? printf("Element was not found\n")
                   : printf("Element was found at index %d\n", result);
}
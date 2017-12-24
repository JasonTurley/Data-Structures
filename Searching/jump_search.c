#include <stdlib.h>
#include <math.h> /* sqrt */
#include "utils.h"

// Assumes array is sorted
int jump_search(int *arr, int x, int n) 
{
    int i, block;

    block = (int)sqrt(n);
    
    if (arr[0] == x) {
        return arr[0];
    }
    // check every index i, 2i, 4i, ..., ki
    while (arr[block] < x && block < n) {
        if (arr[block] == x) {
            return block;
     
       }
       // printf("arr[%d] = %d \n", block, arr[block]); 
        block *= 2;
    }
    // Found element larger than target, or at end of array
    // perform linear search from (block/2)+1 to n
    for (i = (block/2)+1; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    // Target was not found
    return -1;
}


// Driver function
int main()
{
    int arr[] = {0, 1, 1, 2, 3, 5, 8, 16, 21, 55, 89, 144, 223, 317, 610, 720}; 
    int size = sizeof(arr)/sizeof(arr[0]);

    print_array(arr, size);

    int result = jump_search(arr, 505, size);

    (result == -1) ? printf("Element is not in the array\n")
                   : printf("Element was found at index %d\n", result);
                   
    
    
}   

#include <stdlib.h>
#include "utils.h"

int interloper_search(int *arr, int x, int n)
{
    int lo, hi; // beginning and ending indices of array
    int pos;    // calculated position
    
    lo = 0, hi = n-1;

    while (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
       
     // Probing position with keeping uniform distribution in mind
     pos = lo + ((double)(hi-lo)/
             (arr[hi]-arr[lo])*(x-arr[lo]));
  
    // Target is at current position
    if (arr[pos] == x)  
        return pos;
    
    // If x is larger than current position, check upper part of array
    if (arr[pos] < x) 
        lo = pos+1;
    // otherwise check lower
    else 
        hi = pos-1;
    }      
    // Element not found
    return -1;

}


// Driver function
int main()
{
    int arr[] = {0, 1, 1, 2, 3, 5, 8, 16, 21, 55, 89, 144, 223, 317, 610, 720}; 
    int size = sizeof(arr)/sizeof(arr[0]);

    print_array(arr, size);


    int result = interloper_search(arr, 2, 16);
    (result == -1) ? printf("Element is not in the array\n")
                   : printf("Element was found at index %d\n", result);
}             
    
    
   

#include <stdio.h>

// A recursively binary search function. It returns the location of target 
// in a given array arr[l, ... , r], otherwise returns -1
// Runs in O(logn)
int binarySearch(int *arr, int l, int r, int target)
{
    if (r >= 1)
    {
        // Find the middle index of array
        int mid = l + (r-1)/2;          

        // Check if the target is at the middle
        if (arr[mid] == target) 
            return mid;
        
        // If the target is smaller than middle item, search left half of array
        if (arr[mid] > target)
            return binarySearch(arr, l, mid, target);
        
        // Else search right half
        return binarySearch(arr, mid, r-1, target);
    }
    // Target item was not found
    return -1;
}

int main(int argc, char** argv[])
{
    int arr[] = {2, 5, 7, 10, 22, 35, 57};
    int n = sizeof(arr)/sizeof(arr[0]); 
    int x = 35;
    printf("Size of n is %d\n", n);
    int result = binarySearch(arr, 0, n-1, x);
    (result == -1) ? printf("Element is not in the array\n")
                   : printf("Element was found at index %d\n", result);
    return 0;
}
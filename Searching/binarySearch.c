#include <stdio.h>

// A recursively binary search function. It returns the location of target 
// in a given array arr[l, ... , r], otherwise returns -1
// Runs in O(logn) time since it divides search section in half
int BinarySearch(int *arr, int l, int r, int x)
{
    if (l <= r) 
    {
        // Find the middle index of array
        int mid = l + (r-1)/2;          

        // Check if the target is at the middle
        if (arr[mid] == x) 
            return mid;
        
        // If the target is smaller than middle item, search left half of array
        if (arr[mid] > x)
            return BinarySearch(arr, l, mid, x);
        
        // Else search right half
        return BinarySearch(arr, mid, r-1, x);
    }
    // Target item was not found
    return -1;
}

// iterative approach
int BinarySearchIt(int *arr, int n, int x)
{
    int low = 0;
    int high = n-1;
    int mid;

    while (low <= high) 
    { 
        mid = low + (high - low)/2;
        
        if (arr[mid] == x)  
            return mid;        
       
        if (arr[mid] > x)
            high = mid-1;
        else
            low = mid+1;
    }
    return -1; 
}

int main(int argc, char* argv[])
{
    int arr[] = {2, 5, 7, 10, 22, 35, 57, 60, 65, 71, 80, 84, 92, 99};
    int n = sizeof(arr)/sizeof(arr[0]); 
    int x = 45;
  
    int result = BinarySearchIt(arr, n, x);

    (result == -1) ? printf("Element is not in the array\n")
                   : printf("Element was found at index %d\n", result);
    return 0;
}

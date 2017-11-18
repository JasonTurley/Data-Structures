// Merge two subarrays of arr[]

#include <stdio.h>

/* Divide and Conquer algorighm: Runs in O(nlogn)
 * Divides input array into to two halves before sorting them and merging them back together
 * arr[] is the input array; l is starting index; r is ending index
 */
int mergeSort(int arr[], int l, int r)
{
    // base case for one element array
    if (l >= r)
        return arr;
    if (r > l)
    {
        int mid = (l+r)/2;
        // Call mergeSort on left subarray
        mergeSort(arr, l, mid);
        // Call mergeSort on right subarray
        mergeSort(arr, mid+1, r);
        // Merge the two lists together
        merge(arr, l, mid, r);
    }
    // Return the sorted array
    return arr;
}

/* Merge sort helper function */
int merge(int arr[], int l, int mid, int r)
{

}

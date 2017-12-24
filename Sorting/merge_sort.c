// Merge two subarrays of arr[]

#include <stdio.h>

/* Divide and Conquer algorighm: Runs in O(nlogn)
 * Divides input array into to two halves before sorting them and merging them back together
 * arr[] is the input array; l is starting index; r is ending index
 */
void merge_sort(int arr[])
{
    // base case: arr is < 2 elements
    int i, n;
    n = sizeof(arr);
    if (n < 2)   return;
    int mid = n/2;
    // create subarrays of half the size of original array
    int left[mid], right[n-mid];  
    // fill array with respective left and right values
    for (i = 0; i < mid-1; i++) left[i] = arr[i];
    for (i = mid; i < n-1; i++) right[i] = arr[i];

    merge_sort(left);
    merge_sort(right);
    merge(left, right, arr);

}

/* Merge sort helper function */
int merge(int left[], int right[], int arr[])
{
    int i, j, k;                /* counters */
    int nL, nR;                 /* size of left and right arrays */
    
    i = j = k = 0;
    nL = sizeof(left);
    nR = sizeof(right);

    while (i < nL && j < nR) {
        if (left[i] < right[j]) {
            arr[k] = left[i]
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    // if one array runs out, append on remaining elements of other array
    while (i < nL) {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < nR) {
        arr[k] = right[j];
        j++;
        k++;
    }
    return arr;
}

// utility to print arrays
void print_array(int arr[])
{
    int n = sizeof(arr);    
    int i;
    for (i = 0; i < n; i++) 
        printf("%d ", arr[i]);
    puts("\n");
}

int main()
{
    int arr[] = {64, 32, 15, 22, 7, 30};
    print_array(arr);
    merge_sort(arr);
    print_array(arr);
    return 0;
}

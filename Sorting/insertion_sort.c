#include <stdio.h>
#include "utils.h"


void insertion_sort(int arr[], int n)
{
    int i, j;           /* counters*/
    int value;          /* value to be compared */

    for (int i = 1; i < n; i++) {
        value = arr[i];
        j = i;
 
        while(j > 0 && arr[j-1] > value) {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = value;
    }   
}

int main()
{
    int arr[] = {14, 8, 5, 6};
    print_array(arr, 4);
    insertion_sort(arr, 4);    
    print_array(arr, 4); 
}   

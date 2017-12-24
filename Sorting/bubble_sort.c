#include <stdio.h>
#include "utils.h"

void bubble_sort(int arr[], int n)
{
    int i, j;   
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j+1] < arr[j])
                swap(&arr[j+1], &arr[j]);
        }
    }   
}

int main()
{
    int arr[] = {4, 1, 5, 3};
    print_array(arr, 4);
    bubble_sort(arr, 4);    
    print_array(arr, 4); 
}   

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// passing by value would not actually save the changes
// need to pass by pointer or reference
// reference is safer since values cannot be null,
// however, pointers allow function to compile in C and C++
void swap(int *x, int *y)
{
    int z = *x;
    *x = *y;
    *y = z;
}

void selectionSort(int *arr, size_t size)
{
    int i, j, min_idx;
    for (i = 0; i < size-1; i++)
    {
        // set min to be starting element in unsorted subarray
        min_idx = i;

        // Loop through unsorted array, checking if current element is smaller
        for (j = 1; j < size; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

    swap(&arr[min_idx], &arr[i]);  
    }  
}

// Bubble sort runs worst case O(n), even on sorted arrays
// Optimize by exiting function if array is sorted
void bubbleSort(int *arr, size_t size)
{
    int i, j;
    bool swapped;
    for (i = 0; i < size-1; i++)
    {
        swapped = false;
        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

void printArray(int *arr, int length)
{
    int i = 0;
    for ( ; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(int argc, char **argv[])
{
    int arr[] = {34, 5, 76, 21, 16, 0};
    int length = sizeof(arr)/sizeof(arr[0]);

    bubbleSort(arr, length);

    printArray(arr, length);
    
}
#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>

void print_array(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++) 
        printf("%d ", arr[i]);
    puts("\n");
}


void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

#endif 
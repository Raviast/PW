// Given an array of integers arr, return *true if and only if it is a valid mountain array*.

// Recall that arr is a mountain array if and only if:

// - arr.length >= 3
// - There exists some i with 0 < i < arr.length - 1 such that:
//     - arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
//     - arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

// **Example 1:**

// **Input:** arr = [2,1]

// **Output:**

// false

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int validMountainArray(int *arr, int arrSize)
{
    if (arrSize < 3)
    {
        return 0;
    }
    // find max value and that index
    int maxi = 0, maxIdx = 0;
    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] > maxi)
        {
            maxi = arr[i];
            maxIdx = i;
        }
    }

    // Check that one side mountain or not
    if (maxi == arr[0] || maxi == arr[arrSize - 1])
    {
        return 0;
    }

    // Now check it is a valid mountain
    for (int i = 0; i < maxIdx; i++)
    {
        if (arr[i] >= arr[i + 1])
        {
            return 0;
        }
    }
    for (int i = maxIdx; i < arrSize-1; i++)
    {
        if (arr[i] <= arr[i + 1])
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int arr[] = {0, 2, 3, 4, 5, 2, 1, 0};
    int size = sizeof(arr) / sizeof(int);

    int result = validMountainArray(arr, size);
    if (result == 1)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
    
    
    return 0;
}
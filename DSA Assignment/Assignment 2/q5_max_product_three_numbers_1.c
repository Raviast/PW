// Question 5
// Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

// Example 1:
// Input: nums = [1,2,3]
// Output: 6

// This method is for positive numbers
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *bubbleSortAdaptive(int *arr, int size)
{
    int temp;
    int isSorted;
    for (int i = 0; i < size - 1; i++) // for number of pass
    {
        isSorted = 1;
        // printf("Working on pass number %d\n", i+1);
        for (int j = 0; j < size - 1 - i; j++) // for comparison
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted)
        {
            return arr;
        }
    }
    return arr;
}

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int maxProductSubarray(int nums[], int size)
{
    int result;
    if (size < 3)
    {
        return 0;
    }
    if (size == 3)
    {
        result = nums[0] * nums[1] * nums[2];
        return result;
    }
    result = fmax((nums[0] * nums[1] * nums[size - 1]), nums[size - 1] * nums[size - 2] * nums[size - 3]);

    return result;
}

int main()
{
    int nums[] = {-7,-6,-5,1, 2, 3,4};
    int size = sizeof(nums) / sizeof(nums[0]);
    bubbleSortAdaptive(nums, size);
    int result = maxProductSubarray(nums, size);
    printf("%d\n", result);
    return 0;
}
// Question 3
// We define a harmonious array as an array where the difference between its maximum value
// and its minimum value is exactly 1.

// Given an integer array nums, return the length of its longest harmonious subsequence
// among all its possible subsequences.

// A subsequence of an array is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements.

// Example 1:
// Input: nums = [1,3,2,2,5,2,3,7]
// Output: 5

// Explanation: The longest harmonious subsequence is [3,2,2,2,3].

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

int main()
{
    int nums[] = {1, 3, 2, 2, 5, 2, 3, 7};
    int size = sizeof(nums) / sizeof(int);

    bubbleSortAdaptive(nums, size);
    // printArray(nums, size);

    int result = 0;
    for (int i = 0; i < size; i++)
    {
        int count = 1;
        int j = i + 1;
        while (nums[i] == nums[j] || nums[j] - nums[i] == 1)
        {
            count++;
            j++;
        }
        if ((nums[j - 1] - nums[i]) != 1)
        {
            count = 0;
        }
        else
        {
            result = fmax(count, result);
        }
    }
    printf("%d\n", result);
    return 0;
}
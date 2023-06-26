// <aside>
// 💡 **Question 1**
// Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2),..., (an, bn) such that the sum of min(ai, bi) for all i is maximized. Return the maximized sum.

// **Example 1:**
// Input: nums = [1,4,3,2]
// Output: 4

// **Explanation:** All possible pairings (ignoring the ordering of elements) are:

// 1. (1, 4), (2, 3) -> min(1, 4) + min(2, 3) = 1 + 2 = 3
// 2. (1, 3), (2, 4) -> min(1, 3) + min(2, 4) = 1 + 2 = 3
// 3. (1, 2), (3, 4) -> min(1, 2) + min(3, 4) = 1 + 3 = 4
// So the maximum possible sum is 4
// </aside>

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
    int nums[] = {1, 4, 3, 2};
    int size = sizeof(nums) / sizeof(int);

    printf("Input\n");
    printArray(nums, size);
    bubbleSortAdaptive(nums, size);
    int sum = 0;
    for (int i = 0; i < size; i = i + 2)
    {
        sum = sum + nums[i];
    }
    printf("Maximum possible sum for Nums array pair is- %d\n", sum);
    return 0;
}

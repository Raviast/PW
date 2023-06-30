// Given an integer array nums sorted in **non-decreasing** order, return *an array of **the squares of each number** sorted in non-decreasing order*.

// **Example 1:**

// **Input:** nums = [-4,-1,0,3,10]

// **Output:** [0,1,9,16,100]

// **Explanation:** After squaring, the array becomes [16,1,0,9,100].

// After sorting, it becomes [0,1,9,16,100].

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sortedSquares(int *nums, int numsSize)
{
    int returnArr[numsSize];
    int i = numsSize - 1;
    int left = 0, right = numsSize - 1;
    while (left <= right)
    {
        int leftp = pow(nums[left], 2);
        int rightp = pow(nums[right], 2);
        if (leftp >= rightp)
        {
            returnArr[i] = leftp;
            left++;
            i--;
        }
        else
        {
            returnArr[i] = rightp;
            right--;
            i--;
        }
    }
    for (int i = 0; i < numsSize; i++)
    {
        printf("%d ", returnArr[i]);
    }
    return 0;
}

int main()
{
    int nums[] = {-4, -1, 0, 3, 10};
    int size = sizeof(nums) / sizeof(int);
    sortedSquares(nums, size);
    return 0;
}

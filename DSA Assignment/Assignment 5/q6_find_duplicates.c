// Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears **once** or **twice**, return *an array of all the integers that appears **twice***.

// You must write an algorithm that runs in O(n) time and uses only constant extra space.

// **Example 1:**

// **Input:** nums = [4,3,2,7,8,2,3,1]

// **Output:**

// [2,3]

#include <stdio.h>
#include <stdlib.h>

void findDuplicates(int *nums, int numsSize)
{
    int returnArr[numsSize];
    int count = 0;
    for (int i = 0; i < numsSize; i++)
    {
        int index = abs(nums[i]) - 1;
        if (nums[index] < 0)
        {
            returnArr[count] = nums[index];
            count++;
        }
        else
        {
            nums[index] = -nums[index];
        }
    }
    for (int i = 0; i < count; i++)
    {
        printf("%d ", -returnArr[i]);
    }
}

int main()
{
    int nums[] = {4, 3,2,7,8,2,3,1};
    int size = sizeof(nums) / sizeof(int);

    findDuplicates(nums, size);
    return 0;
}
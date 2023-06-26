// Question 7
// An array is monotonic if it is either monotone increasing or monotone decreasing.

// An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is
// monotone decreasing if for all i <= j, nums[i] >= nums[j].

// Given an integer array nums, return true if the given array is monotonic, or false otherwise.

// Example 1:
// Input: nums = [1,2,2,3]
// Output: true

#include <stdio.h>
#include <stdlib.h>

int increasingMonotonic(int *nums, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (nums[i] < nums[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

int decreasingMonotonic(int *nums, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (nums[i] > nums[i + 1])
        {
            return 0;
        }
    }
    return 1;
}
int checkMonotonic(int *nums, int size)
{
    int result1 = increasingMonotonic(nums, size);
    int result2 = decreasingMonotonic(nums, size);
    if (nums[0] == nums[size-1])
    {
        return 0;
    }
    else if (result1 == 1 || result2 == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
    
}
int main()
{
    int nums[] = {3,3,3};
    int size = sizeof(nums) / sizeof(nums[0]);

    int result = checkMonotonic(nums, size);
    if (result ==1)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
    
    return 0;
}
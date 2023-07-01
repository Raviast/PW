// Given a binary array nums, return *the maximum length of a contiguous subarray with an equal number of* 0 *and* 1.

// **Example 1:**

// **Input:** nums = [0,1]

// **Output:** 2

// **Explanation:**

// [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.

#include <stdio.h>
#include <stdlib.h>

int findMaxLength(int *nums, int numsSize)
{
    int r = 0, count = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == 1)
        {
            r++;
        }
        else
        {
            r--;
        }
        if (r == 0)
        {
            count++;
        }
    }
    return count;
}
int main()
{
    int nums[] = {0, 1};
    int size = sizeof(nums) / sizeof(int);

    printf("Output-> %d\n", findMaxLength(nums, size));
    return 0;
}
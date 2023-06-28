// Question 1
// Given an integer array nums of length n and an integer target, find three integers
// in nums such that the sum is closest to the target.
// Return the sum of the three integers.

// You may assume that each input would have exactly one solution.

// Example 1:
// Input: nums = [-1,2,1,-4], target = 1
// Output: 2

// Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).



#include <stdio.h>
#include <stdlib.h>

int threeSumCloset(int *nums, int numsSize, int target)
{
    int arr[3][2];

    if (numsSize == 3)
    {
        return (nums[0] + nums[1] + nums[2]);
    }
    for (int i = 0; i < numsSize; i++)
    {
        if (i < 3)
        {
            int diff = abs(target - nums[i]);
            arr[i][0] = nums[i];
            arr[i][1] = diff;
        }
       
        else
        {
            int diff = abs(target - nums[i]);
            int inner_diff, arr_position, nums_arr = nums[i];
            for (int j = 0; j < 3; j++)
            {
                if (diff < arr[j][1])
                {
                    inner_diff = arr[j][1];
                    arr[j][1] = diff;
                    arr_position = arr[j][0];
                    arr[j][0] = nums_arr;
                    diff = inner_diff;
                    nums_arr = arr_position;
                }
            }
        }
    }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
        
        int sum = 0;
        for (int i = 0; i < 3; i++)
        {
            sum = sum + arr[i][0];
        }
        return sum;
    
    return 0;
}

int main()
{
    int nums[] = {-1, -2, -1,4, 0};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 1;

    int result = threeSumCloset(nums, numsSize, target);
    printf("Three sum closet is-> %d\n", result);

    return 0;
}

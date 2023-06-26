// Question 8
// You are given an integer array nums and an integer k.

// In one operation, you can choose any index i where 0 <= i < nums.length and change nums[i] to nums[i] + x where x is an integer from the range [-k, k]. You can apply this operation at most once for each index i.

// The score of nums is the difference between the maximum and minimum elements in nums.

// Return the minimum score of nums after applying the mentioned operation at most once for each index in it.

// Example 1:
// Input: nums = [1], k = 0
// Output: 0
// Explanation: The score is max(nums) - min(nums) = 1 - 1 = 0.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nums[] = {1, 3, 6};
    int k;
    int size = sizeof(nums) / sizeof(int);

    printf("Enter the value of Integer K\n");
    scanf("%d", &k);

    int max = nums[0];
    int min = nums[0];
    for (int i = 1; i < size; i++)
    {
        if (nums[i] > max)
        {
            max = nums[i];
        }
        if (min > nums[i])
        {
            min = nums[i];
        }
    }
    int diff = max - min;
    if ((diff - 2 * k) < 0)
    {
        printf("Output-> 0");
    }
    else
    {
        printf("Output-> %d", (diff - 2 * k));
    }

    return 0;
}

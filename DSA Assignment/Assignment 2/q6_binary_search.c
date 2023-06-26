// Question 6
// Given an array of integers nums which is sorted in ascending order, and an integer target,
// write a function to search target in nums. If target exists, then return its index. Otherwise,
// return -1.

// You must write an algorithm with O(log n) runtime complexity.

// Input: nums = [-1,0,3,5,9,12], target = 9
// Output: 4

// Explanation: 9 exists in nums and its index is 4

#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *nums, int size, int target)
{
    int low, mid, high;
    low = 0;
    high = size - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[low] == target)
        {
            return low;
        }
        else if (nums[high] == target)
        {
            return high;
        }
        else if (nums[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}
int main()
{
    int nums[] = {-1, 0, 3, 5, 9, 12};
    int size = sizeof(nums) / sizeof(int);
    int target;
    printf("Enter target number\n");
    scanf("%d", &target);
    int result = binarySearch(nums, size, target);
    printf("Target found at index %d\n", result);
    return 0;
}
// Question 2
// Given an array nums of n integers, return an array of all the unique quadruplets
// [nums[a], nums[b], nums[c], nums[d]] such that:
//            ● 0 <= a, b, c, d < n
//            ● a, b, c, and d are distinct.
//            ● nums[a] + nums[b] + nums[c] + nums[d] == target

// You may return the answer in any order.

// Example 1:
// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

#include <stdio.h>
#include <stdlib.h>

int compare(const void *x_void, const void *y_void)
{
    int x = *(int *)x_void;
    int y = *(int *)y_void;
    return x - y; // x-y sort the array ascending order
}

int foursum(int *nums, int size, int target)
{
    if (size < 0)
    {
        return 0;
    }

    // first sort the array

    qsort(nums, size, sizeof(int), compare);

    // two pointer approach
    int quad_arr[size / 2][4], k=0;
    for (int i = 0; i < size; i++)
    {

        int target1 = target - nums[i];
        for (int j = i + 1; j < size; j++)
        {

            int target2 = target1 - nums[j];
            int front = j + 1;
            int back = size - 1;
            while (front < back)
            {
                // Now two sum approch for remaining two elements
                int two_sum = nums[front] + nums[back];

                if (two_sum < target2)
                {
                    front++;
                }
                else if (two_sum > target2)
                {
                    back--;
                }
                else
                {

                    // two_sum == target2
                    quad_arr[k][0] = nums[i];
                    quad_arr[k][1] = nums[j];
                    quad_arr[k][2] = nums[front];
                    quad_arr[k][3] = nums[back];


                    // processing the duplicates of number 3
                    while (front < back && nums[front] == quad_arr[k][2])
                    {
                        front++;
                    }
                    // processing the duplicates of number 4
                    while (front < back && nums[back] == quad_arr[k][3])
                    {
                        back--;
                    }
                    k++;
                }
            }
            // processing the duplicates of number 2
            while (j + 1 < size && nums[j + 1] == nums[j])
            {
                j++;
            }
        }
        while (i + 1 < size && nums[i + 1] == nums[i])
        {
            i++;
        }
    }
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", quad_arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}

int main()
{
    int nums[] = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int size = sizeof(nums) / sizeof(int);
    int target;
    printf("Enter target valur for four sum\n");
    scanf("%d", &target);

    foursum(nums, size, target);
    return 0;
}
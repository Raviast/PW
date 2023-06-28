// <aside>
// 💡 **Question 3**
// A permutation of an array of integers is an arrangement of its members into a
// sequence or linear order.

// For example, for arr = [1,2,3], the following are all the permutations of arr:
// [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].

// The next permutation of an array of integers is the next lexicographically greater
// permutation of its integer. More formally, if all the permutations of the array are
// sorted in one container according to their lexicographical order, then the next
// permutation of that array is the permutation that follows it in the sorted container.

// If such an arrangement is not possible, the array must be rearranged as the
// lowest possible order (i.e., sorted in ascending order).

// ● For example, the next permutation of arr = [1,2,3] is [1,3,2].
// ● Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
// ● While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not
// have a lexicographical larger rearrangement.

// Given an array of integers nums, find the next permutation of nums.
// The replacement must be in place and use only constant extra memory.

// **Example 1:**
// Input: nums = [1,2,3]
// Output: [1,3,2]

// </aside>

#include <stdio.h>
#include <stdlib.h>

void reverse(int *nums, int start, int last)
{
    while(start < last)
    {
        int temp = nums[start];
        nums[start] = nums[last];
        nums[last] = temp;
        start++;
        last--;
    }
}

void nextPermutation(int* nums, int numsSize){
    int index1 = -1;
    int index2 = -1;

    // find first break point
    for(int i = numsSize - 2; i >=0 ; i--)
    {
        if(nums[i] < nums[i+1])
        {
            index1 = i;
            break;
        }
    }

    if(index1 == -1)
    {
        reverse(nums, 0, numsSize-1);
    }
    else{
        for(int i = numsSize-1; i>= 0; i--)
        {
            if(nums[i] > nums[index1])
            {
                index2 = i;
                break;
            }
        }
    
    // swapping index1 and index2 data
    int temp = nums[index1];
    nums[index1] = nums[index2];
    nums[index2] = temp;
    // now reverse the rest array
    reverse(nums, index1+1, numsSize-1);
    }
}
int main()
{
    int nums[] = {1,2,3};
    int numsSize = sizeof(nums)/ sizeof(int);
    nextPermutation(nums, numsSize);   
    for (int i = 0; i < numsSize; i++)
    {
        printf("%d ", nums[i]);
    }
    
    return 0;
}
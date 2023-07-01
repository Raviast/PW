// The **product sum** of two equal-length arrays a and b is equal to the sum of a[i] * b[i] for all 0 <= i < a.length (**0-indexed**).

// - For example, if a = [1,2,3,4] and b = [5,2,3,1], the **product sum** would be 1*5 + 2*2 + 3*3 + 4*1 = 22.

// Given two arrays nums1 and nums2 of length n, return *the **minimum product sum** if you are allowed to **rearrange** the **order** of the elements in* nums1.

// **Example 1:**

// **Input:** nums1 = [5,3,4,2], nums2 = [4,2,2,5]

// **Output:** 40

// **Explanation:**

// We can rearrange nums1 to become [3,5,4,2]. The product sum of [3,5,4,2] and [4,2,2,5] is 3*4 + 5*2 + 4*2 + 2*5 = 40.

#include <stdio.h>
#include <stdlib.h>

int compare(const void *x_void, const void *y_void)
{
    int x = *(int *)x_void;
    int y = *(int *)y_void;
    return x - y;
}
int minProductSum(int *nums1, int numsSize1, int *nums2, int numsSize2)
{
    qsort(nums1, numsSize1, sizeof(int), compare);
    qsort(nums2, numsSize2, sizeof(int), compare);
    int sum = 0;
    for (int i = 0; i < numsSize1; i++)
    {
        sum = sum + nums1[i] * nums2[numsSize2 - 1 - i];
    }
    return sum;
}
int main()
{
    int nums1[] = {3, 5, 4, 2};
    int nums2[] = {4, 2, 2, 5};

    int size1 = sizeof(nums1) / sizeof(int);
    int size2 = sizeof(nums2) / sizeof(int);

    int result = minProductSum(nums1, size1, nums2, size2);
    printf("%d\n", result);
    return 0;
}
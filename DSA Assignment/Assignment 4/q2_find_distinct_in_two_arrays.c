// #include <stdio.h>
// #include <stdlib.h>

// int binarySearch(int *arr, int size, int target)
// {
//     int low, mid, high;
//     low = 0, high = size - 1;
//     while (low < high)
//     {
//         mid = (low + high) / 2;
//         if (arr[mid] == target)
//         {
//             return 1;
//         }
//         else if (mid > target)
//         {
//             high = mid - 1;
//         }
//         else
//         {
//             low = mid + 1;
//         }
//     }
//     return 0;
// }

// int findDistinctIntegers(int * nums1, int * nums2, int size1, int size2)
// {
//     int result_arr[2][size1];
//     int count =0 ;
//     // checking all distinct integers in nums1 which are not present in nums2.
//         int result = -1;
//     for (int i = 0; i < size1; i++)
//     {
//         result = binarySearch(nums2, size2, nums1[i]);
//         printf("%d %d\n", nums1[i], result);
//         if (result == 1)
//         {
//             result_arr[0][count] = nums1[i];
//             // printf("%d ", result_arr[0][count]);
//             count++;
//         }
        
//     }
    
// }

// int main()
// {
//     int nums1[] = {1,2,3};
//     int nums2[] = {2,4,6};
//     int size1 = sizeof(nums1)/sizeof(int);
//     int size2 = sizeof(nums2)/sizeof(int);

//     findDistinctIntegers(nums1, nums2, size1, size2);
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nums1[] = {1, 2, 3};
    int nums2[] = {2, 4, 6};
    int n1 = sizeof(nums1) / sizeof(nums1[0]);
    int n2 = sizeof(nums2) / sizeof(nums2[0]);
    int i, j;
    int *ans1 = (int *)malloc(n1 * sizeof(int));
    int *ans2 = (int *)malloc(n2 * sizeof(int));
    int ans1Size = 0;
    int ans2Size = 0;
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < n2; j++)
        {
            if (nums1[i] == nums2[j])
                break;
        }
        if (j == n2)
            ans1[ans1Size++] = nums1[i];
    }
    for (i = 0; i < n2; i++)
    {
        for (j = 0; j < n1; j++)
        {
            if (nums2[i] == nums1[j])
                break;
        }
        if (j == n1)
            ans2[ans2Size++] = nums2[i];
    }
    printf("[");
    for (i = 0; i < ans1Size; i++)
    {
        printf("%d", ans1[i]);
        if (i != ans1Size - 1)
            printf(",");
    }
    printf("],[");
    for (i = 0; i < ans2Size; i++)
    {
        printf("%d", ans2[i]);
        if (i != ans2Size - 1)
            printf(",");
    }
    printf("]");
}

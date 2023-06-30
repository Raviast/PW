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

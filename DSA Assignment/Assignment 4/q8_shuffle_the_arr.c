#include <stdio.h>
#include <stdlib.h>

int shuffle(int *nums, int numsSize)
{
    int n= numsSize/2;
    int resultArr[numsSize];
    for (int i = 0; i < n; i++)
    {
        resultArr[2*i] = nums[i];
        resultArr[2*i+1] = nums[n+i];
    }
    for (int i = 0; i < numsSize; i++)
    {
        printf("%d ", resultArr[i]);
    }
    
}
int main()
{
    int nums[] = {1,2,3,4,5,6,7,8};
    int numsSize = sizeof(nums)/sizeof(int);
    int n = numsSize/2;

    shuffle(nums, numsSize);
    return 0;
}
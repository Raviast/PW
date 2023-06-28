#include <stdio.h>
#include <stdlib.h>

int mergeIntervals(int rows, int (*arr)[rows], int cols)
{
    printf("%d  %d\n",rows, cols );
    for (int i = 0; i < rows-1; i++)
    {
        if (arr[i][1] > arr[i+1][0])
        {
            return 1;
        }
        
    }
    return 0;
}

int main()
{
    int nums[][2]= {{1,3},{2,6},{8,10},{15,18}};
    int rows = sizeof(nums)/sizeof(nums[0]);

    int result = mergeIntervals(rows, nums, 2);
    if (result == 1)
    {
        printf("false\n");
    }
    else
    {
        printf("True\n");
    }
    
    return 0;
}
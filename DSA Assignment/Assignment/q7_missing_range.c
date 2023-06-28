#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nums[] = {0, 1, 3, 5, 50, 79};
    int size = sizeof(nums) / sizeof(int);
    int lower, upper;
    printf("Enter the value of lower integer for nums array \n");
    scanf("%d", &lower);
    printf("Enter the value of lower integer for nums array \n");
    scanf("%d", &upper);
    int missing_range[size][2];
    int count = 0;
    for (int i = 1; i < size; i++)
    {
        int prev_num = nums[i - 1] + 1;
        if (nums[i] != (nums[i - 1] + 1))
        {
            missing_range[count][0] = prev_num;
            missing_range[count][1] = nums[i] - 1;
            count++;
        }
    }
    if (nums[size - 1] != upper)
    {
        missing_range[count][0] = nums[size-1]+1;
        missing_range[count][1] = upper;
        count++;
    }
    for (int i = 0; i < count; i++)
    {
            for (int j = 0; j < 2; j++)
            {
                printf("%d ", missing_range[i][j]);
            }
            printf("\n");
    }
    

    return 0;
    }
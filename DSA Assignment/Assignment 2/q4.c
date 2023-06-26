// Question 4
// You have a long flowerbed in which some of the plots are planted, and some are not.
// However, flowers cannot be planted in adjacent plots.
// Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.

// Example 1:
// Input: flowerbed = [1,0,0,0,1], n = 1
// Output: true

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int canPlantFlower(int flowerbed[], int size, int n)
{
    if (n <= 0)
    {
        return 1;
    }
    
    for (int i = 0; i < size; i++)
    {
        if (i == 0)
        {
            if (flowerbed[i] == 0 && flowerbed[i + 1] == 0)
            {
                flowerbed[i] = 1;
                n--;
                if (n == 0)
                {
                    return 1;
                }
            }
        }

        if (flowerbed[i] == 0)
        {
            if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0)
            {
                flowerbed[i] = 1;
                n--;
                if (n == 0)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main()
{
    int flowerbed[] = {0, 0, 1, 0, 1};
    int size = sizeof(flowerbed) / sizeof(int);
    int n;

    printf("Enter the value of n\n");
    scanf("%d", &n);

    int result = canPlantFlower(flowerbed, size, n);

    if (result == 1)
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }

    return 0;
}
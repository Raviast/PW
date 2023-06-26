// Question 2
// Alice has n candies, where the ith candy is of type candyType[i]. Alice noticed that she started to gain weight, so she visited a doctor.

// The doctor advised Alice to only eat n / 2 of the candies she has (n is always even). Alice likes her candies very much, and she wants to eat the maximum number of different types of candies while still following the doctor's advice.

// Given the integer array candyType of length n, return the maximum number of different types of candies she can eat if she only eats n / 2 of them.

// Example 1:
// Input: candyType = [1,1,2,2,3,3]
// Output: 3

// Explanation: Alice can only eat 6 / 2 = 3 candies. Since there are only 3 types, she can eat one of each type.

#include <stdio.h>
#include <stdlib.h>

int checkHashset(int *arr, int target, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            // printf("%d\n", arr[i]);
            return 0;
        }
    }
    return 1;
}

int main()
{
    int candyType[] = {1, 1, 2, 2, 3, 3}; // Input size always even
    int size = sizeof(candyType) / sizeof(int);

    // Solve approach using hashset
    int count =0;
    if (size <= 0)
    {
        return 0;
    }
    else
    {
        int n = size / 2;
        int arr[n];
        for (int i = 0; i < size; i++)
        {
            if (i == 0)
            {
                arr[i] = candyType[i];
                count++;
            }
            else
            {
                int x = checkHashset(arr, candyType[i], n);
                if (x == 1 && count < n)
                {
                    arr[count] = candyType[i];
                    count++;
                }
            }
        }
    }
    printf("Alice can eat different types of candies or Output-> %d\n", count);

    return 0;
}
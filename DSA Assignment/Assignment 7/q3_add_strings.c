// Given two non-negative integers, num1 and num2 represented as string, return *the sum of* num1 *and* num2 *as a string*.

// You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.

// **Example 1:**

// **Input:** num1 = "11", num2 = "123"

// **Output:**

// "134"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int addStrings(char *num1, char *num2)
{
    int n1 = 0, n2 = 0;
    int size1 = strlen(num1), size2 = strlen(num2);

    // Convert string into integer
    for (int i = 0; i < size1; i++)
    {
        n1 = n1 * 10;
        n1 = n1 + num1[i] - '0';
    }

    for (int i = 0; i < size2; i++)
    {
        n2 = n2 * 10;
        n2 = n2 + num2[i] - '0';
    }
    int n3 = n1 + n2;

    // count length of return arr
    int count = 0;
    int return_arr[30];
    while (n3 != 0)
    {
        return_arr[count] = n3 % 10;
        n3 = n3 / 10;
        count++;
    }
    for (int i = 0; i < count/2; i++)
    {
        int j = count -1;
        int temp = return_arr[i];
        return_arr[i] = return_arr[j];
        return_arr[j] = temp;
    }
    for (int i = 0; i < count; i++)
    {
        printf("%d", return_arr[i]);
    }
    
    
}

int main()
{
    char num1[] = "134";
    char num2[] = "11";
    addStrings(num1, num2);
    return 0;
}
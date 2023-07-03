// Given a string num which represents an integer, return true *if* num *is a **strobogrammatic number***.

// A **strobogrammatic number** is a number that looks the same when rotated 180 degrees (looked at upside down).

// **Example 1:**

// **Input:** num = "69"

// **Output:**

// true

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool strobogrammaticNumber(char *num)
{
    int size = strlen(num);
    if (num == 0 || size == 0)
    {
        return 1;
    }
    if (size == 1)
    {
        if (num[0] == '0' || num[0] == '1' || num[0] == '8')
        {
            return true;
        }
    }
    int left = 0, right = size - 1;
    while (left <= right)
    {
        if (num[left] == num[right])
        {
            if (num[left] != '1' && num[left] != '0' && num[left] != '8')
            {
                return false;
            }
        }
        else
        {
            if ((num[left] != '6' || num[right] != '9') && (num[left] != '9' || num[right] != '6'))
            {
                return false;
            }
        }
        left++, right--;
    }
    return true;
}

int main()
{
    char s[] = "696";
    if(strobogrammaticNumber(s))
        printf("true");
    else
        printf("false");
    return 0;
}
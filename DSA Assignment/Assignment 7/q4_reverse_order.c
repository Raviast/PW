// Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

// **Example 1:**

// **Input:** s = "Let's take LeetCode contest"

// **Output:** "s'teL ekat edoCteeL tsetnoc"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int reverseWords(char *s)
{
    int size = strlen(s);

    int prev_flag = 0, new_flag;
    for (int i = 0; i < size; i++)
    {
        if (s[i] == ' ' || i == size - 1)
        {
            new_flag = i;

            int loop_count = (new_flag - prev_flag) / 2;
            for (int j = prev_flag, k = 0; k < loop_count; j++, k++)
            {
                char temp = s[j];
                s[j] = s[new_flag - k - 1];
                s[new_flag - k - 1] = temp;
            }
            prev_flag = new_flag+1;
        }
    }
    for (int i = 0; i < size; i++)
    {
        printf("%c", s[i]);
    }
}

int main()
{
    char s[] = "Let's take LeetCode contest";
    reverseWords(s);
    return 0;
}
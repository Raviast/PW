#include <stdio.h>
#include <string.h>

int firstUniqChar(char *s)
{
    int flag, i;
    int size = strlen(s);
    for (i = 0; i < size; i++)
    {
        flag = 1;
        for (int j = i+1; j < size; j++)
        {
            if (s[i] == s[j])
            {
                flag = 0;
            
            }
        }
        if (flag == 1)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    char s[] = "leetcode";
    printf("output %d\n", firstUniqChar(s));
    return 0;
}
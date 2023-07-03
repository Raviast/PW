// Given two strings s and t, *determine if they are isomorphic*.

// Two strings s and t are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

// **Example 1:**

// **Input:** s = "egg", t = "add"

// **Output:** true

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int searchChar(int rows, char (*map)[rows], int cols, char target)
{
    for (int i = 0; i < rows; i++)
    {
        if (map[i][0] == target)
        {
            return i;
        }
    }
    return -1;
}

bool linearSearch(char *map2, int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (target == map2[i])
        {
            return true;
        }
    }
    return false;
}
int isomorphic(char *s, char *t)
{
    int s_size = strlen(s);
    int t_size = strlen(t);
    printf("%d", s_size);
    if (s_size != t_size)
    {
        return 0;
    }
    // creating two hash map- one for <ch, ch> and one for string 2 char is already map or not
    char map1[26][26], map2[26];

    int count = 0;
    for (int i = 0; i < s_size; i++)
    {
        // check char at s[i] is map or not
        int index_i = searchChar(26, map1, 26, s[i]);
        if (index_i != -1)
        {
            if (map1[index_i][1] != t[i])
            {
                return 0;
            }
        }
        // check whether t[i] char is already map or not
        else if (linearSearch(map2, 26, t[i]))
        {
            return 0;
        }
        else
        {
            map1[count][0] = s[i];
            map1[count][1] = t[i];
            map2[count] = t[i];
            count++;
        }
        }
    return 1;
}

int main()
{
    char s[] = "foo";
    char t[] = "bar";
    printf("Output -> %d", isomorphic(s, t));
    return 0;
}

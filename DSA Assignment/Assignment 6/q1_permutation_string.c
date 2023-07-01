// A permutation perm of n + 1 integers of all the integers in the range [0, n] can be represented as a string s of length n where:

// - s[i] == 'I' if perm[i] < perm[i + 1], and
// - s[i] == 'D' if perm[i] > perm[i + 1].

// Given a string s, reconstruct the permutation perm and return it. If there are multiple valid permutations perm, return **any of them**.

// **Example 1:**

// **Input:** s = "IDID"

// **Output:**

// [0,4,1,3,2]

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int diStringMatch(char *s, int size)
{
    int low = 0, high = size;
    int ans[size + 1];
    for (int i = 0; i < size; i++)
    {
        if (s[i] == 'I')
        {
            ans[i] = low;
            low++;
        }
        else
        {
            ans[i] = high;
            high--;
        }
    }
    ans[size] = low;

    for (int i = 0; i <= size; i++)
    {
        printf("%d ", ans[i]);
    }

    return 0;
}
int main()
{
    char s[] = "IDID";
    int size = strlen(s);

    diStringMatch(s, size);
    return 0;
}

// <aside>
// 💡 **Question 7**
// You are given an m x n matrix M initialized with all 0's and an array of operations ops, where ops[i] = [ai, bi] means M[x][y] should be incremented by one for all 0 <= x < ai and 0 <= y < bi.

// Count and return *the number of maximum integers in the matrix after performing all the operations*

// **Example 1:**

// ![q4.jpg](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/4d0890d0-7bc7-4f59-be8e-352d9f3c1c52/q4.jpg)

// **Input:** m = 3, n = 3, ops = [[2,2],[3,3]]

// **Output:** 4

// **Explanation:** The maximum integer in M is 2, and there are four of it in M. So return 4.

// </aside>

#include <stdio.h>
#include <stdlib.h>

int maxCount(int m, int n, int rows, int (*ops)[rows])
{
    int res_t = m;
    int res_b = n;
    for (int i = 0; i < rows; i++)
    {
        if (ops[i][0] < m)
        {
            m = ops[i][0];
            n = ops[i][1];
        }
    }
    return m*n;
}
int main()
{
    int m, n;
    int ops[][2] = {{2, 2}, {3, 3},{1,1}};
    int rows = sizeof(ops) / sizeof(ops[0]);

    printf("Enter size of m*n matrix\n");
    scanf("%d%d", &m, &n);

    int result = maxCount(m, n, rows, ops);
    printf("Output-> %d", result);
    return 0;
}

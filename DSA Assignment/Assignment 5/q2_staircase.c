#include <stdio.h>
#include <stdlib.h>

int arrangeCoins(int n)
{
    int rows = 0;

        int temp = n;
    for (int i = 1; i < n; i++)
    {
        if (temp - i >= 0)
        {
            rows++;
        }
        
        temp = temp-i ;
    }
    return rows;
}

int main()
{
    int n;
    printf("Enter N integer value for staircase countn\n");
    scanf("%d", &n);
    int result = arrangeCoins(n);
    printf("Rows covered by coins is -> %d\n", result);
    return 0;
}

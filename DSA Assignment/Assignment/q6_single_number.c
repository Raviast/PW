#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nums[] = {2,3,2,3,4};
    int size = sizeof(nums)/sizeof(int);

    int result = 0;
    for (int i = 0; i < size; i++)
    {
        result = result^i;
    }
    printf("%d", result);
    return 0;
}
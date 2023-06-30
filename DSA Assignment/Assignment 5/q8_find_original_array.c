#include <stdio.h>
#include <stdlib.h>

int compare(const void *x_void, const void *y_void)
{
    int x = *(int *)x_void;
    int y = *(int *)y_void;
    return x - y;
}

void findOriginalArray(int *changed, int size)
{
    int returnArr[size];
    int *ptr = returnArr;
    qsort(changed, size, sizeof(int), compare);

    int n = size / 2;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int target = 2 * changed[i];
        // printf("\n%d", target);
        for (int j = i + 1; j < size; j++)
        {
            if (target == changed[j])
            {
                returnArr[count] = changed[i];
                count++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (count == n)
        {
            printf("%d ", returnArr[i]);
        }
        else
        {
            printf("[]");
        }
        
    }
}

int main()
{
    int changed[] = {6,3,0,1};
    int size = sizeof(changed) / sizeof(int);

    findOriginalArray(changed, size);
    return 0;
}
// An integer array original is transformed into a **doubled** array changed by appending **twice the value** of every element in original, and then randomly **shuffling** the resulting array.

// Given an array changed, return original *if* changed *is a **doubled** array. If* changed *is not a **doubled** array, return an empty array. The elements in* original *may be returned in **any** order*.

// **Example 1:**

// **Input:** changed = [1,3,4,2,6,8]

// **Output:** [1,3,4]

// **Explanation:** One possible original array could be [1,3,4]:

// - Twice the value of 1 is 1 * 2 = 2.
// - Twice the value of 3 is 3 * 2 = 6.
// - Twice the value of 4 is 4 * 2 = 8.

// Other original arrays could be [4,3,1] or [3,1,4].

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
    int changed[] = {1,3,4,2,6,8};
    int size = sizeof(changed) / sizeof(int);

    findOriginalArray(changed, size);
    return 0;
}

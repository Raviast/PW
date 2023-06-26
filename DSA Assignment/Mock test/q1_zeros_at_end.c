// <aside>
// 💡 **Q7.** Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the nonzero elements.

// Note that you must do this in-place without making a copy of the array.

// **Example 1:**
// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]

// </aside>

#include <stdio.h>
#include <stdlib.h>

struct myArray
{
    int totalSize;
    int usedSize;
    int *ptr;
};

void createArray(struct myArray *a, int tSize, int uSize)
{
    a->totalSize = tSize;
    a->usedSize = uSize;
    a->ptr = (int *)malloc(tSize * sizeof(int));
}

void setVal(struct myArray *a)
{
    int num;
    for (int i = 0; i < a->usedSize; i++)
    {
        printf("Enter you numbe at %d index\t", i);
        scanf("%d", &num);
        a->ptr[i] = num;
    }
}

void show(struct myArray *a)
{
    for (int i = 0; i < a->usedSize; i++)
    {
        printf("%d ", a->ptr[i]);
    }
    printf("\n");
}

int linearSearch(struct myArray *a, int target)
{
    for (int i = 0; i < a->usedSize; i++)
    {
        if (a->ptr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int zerosAtEnd(struct myArray *a)
{
    int count = 0, index;
    for (int i = 0; i < a->usedSize; i++)
    {
        index = linearSearch(a, 0);
        if (index >= 0)
        {
            for (int j = index; j < a->usedSize; j++)
            {
                a->ptr[j] = a->ptr[j + 1];
            }
            count++;
        }
    }
    printf("%d count\n", count);
    int i = 1;
    while (count != 0)
    {
        a->ptr[a->usedSize - i] = 0;
        count--;
        i++;
    }

    return 0;
}

int main()
{
    struct myArray nums;
    int total_size = 50;
    int target, used_size, result;

    printf("Enter Array Size-\n");
    scanf("%d", &used_size);
    createArray(&nums, total_size, used_size);
    setVal(&nums);
    show(&nums);

    zerosAtEnd(&nums);
    printf("After performing operation Zeros at end of an array\n");
    show(&nums);
    return 0;
}

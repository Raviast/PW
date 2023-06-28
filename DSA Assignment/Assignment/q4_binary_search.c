// <aside>
// 💡 **Q3.** Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

// You must write an algorithm with O(log n) runtime complexity.

// **Example 1:**
// Input: nums = [1,3,5,6], target = 5

// Output: 2

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

int binarySearch(struct myArray *a, int target)
{
    int low, mid, high;
    low = 0;
    high = a->usedSize - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a->ptr[mid] == target)
        {
            return mid;
        }
        if (a->ptr[mid] > target)
        {
            high = mid - 1;
        }
        if (a->ptr[mid] < target)
        {
            low = mid + 1;
        }
    }
    if (a->ptr[mid] < target)
    {
        return (high + 1);
    }
    else
    {
        return (low);
    }
}

int main()
{
    struct myArray nums;
    int total_size = 50;
    int target, used_size;

    printf("Enter Array Size-\n");
    scanf("%d", &used_size);
    createArray(&nums, total_size, used_size);
    setVal(&nums);
    show(&nums);

    printf("Enter Integer Target number\n");
    scanf("%d", &target);
    printf("The Target found at index is Or The target should be at index %d\n", binarySearch(&nums, target));
    show(&nums);
    return 0;
}

// <aside>
// 💡 **Q4.** You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

// Increment the large integer by one and return the resulting array of digits.

// **Example 1:**
// Input: digits = [1,2,3]
// Output: [1,2,4]

// **Explanation:** The array represents the integer 123.

// Incrementing by one gives 123 + 1 = 124.
// Thus, the result should be [1,2,4].

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

void incrementByOne(struct myArray *a)
{
    int num =0, remainder =0, j=1;
    for (int i = 0; i < a->usedSize; i++)
    {
        num = num*10 + a->ptr[i];
    }
    num = num +1;
    while (num != 0)
    {
        remainder = num%10;
        if (remainder != a->ptr[a->usedSize-j])
        {
            a->ptr[a->usedSize-j] = remainder;
        }
        j++;
        num = num/10;
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

    printf("Incrementing by 1 gives or after operation\n");
    incrementByOne(&nums);
    show(&nums);
    return 0;
}

// <aside>
// 💡 **Question 1**
// Given three integer arrays arr1, arr2 and arr3 **sorted** in **strictly increasing** order, return a sorted array of **only** the integers that appeared in **all** three arrays.

// **Example 1:**

// Input: arr1 = [1,2,3,4,5], arr2 = [1,2,5,7,9], arr3 = [1,3,4,5,8]

// Output: [1,5]

// **Explanation:** Only 1 and 5 appeared in the three arrays.

// </aside>

#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *arr, int size, int target)
{
    int low, mid, high;
    low = 0, high = size - 1;
    while (low < high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            return 1;
        }
        else if (mid > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return 0;
}

int checkAvailableEveryWhere(int *arr1, int *arr2, int *arr3, int size1, int size2, int size3)
{
    int result_arr[size1];
    int count = 0;
    for (int i = 0; i < size1; i++)
    {
        int result1 = binarySearch(arr2, size2, arr1[i]);
        if (result1 == 1)
        {
            int result2 = binarySearch(arr3, size3, arr1[i]);
            if (result2 == 1)
            {
                result_arr[count] = arr1[i];
                count++;
            }
            
        }
    }
    for (int i = 0; i < count; i++)
    {
        printf("%d ", result_arr[i]);
    }
    
    return 0;
}
int main()
{
    int arr1[] = {1, 2, 3, 4, 5}, arr2[] = {1, 2, 5, 7, 9}, arr3[] = {1, 3, 4, 5, 8};
    int size1 = sizeof(arr1) / sizeof(int);
    int size2 = sizeof(arr2) / sizeof(int);
    int size3 = sizeof(arr3) / sizeof(int);

    checkAvailableEveryWhere(arr1, arr2, arr3, size1, size2, size3);
    
    return 0;
}

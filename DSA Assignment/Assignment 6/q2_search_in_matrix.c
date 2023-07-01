// Searach in a 2D matric using binary search algorithm

// You are given an m x n integer matrix matrix with the following two properties:

// - Each row is sorted in non-decreasing order.
// - The first integer of each row is greater than the last integer of the previous row.

// Given an integer target, return true *if* target *is in* matrix *or* false *otherwise*.

// You must write a solution in O(log(m * n)) time complexity.

// **Example 1:**
// **Input:** matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3

// **Output:** true

#include <stdio.h>
#include <stdlib.h>

int searchMatrix(int rows, int (*arr)[rows], int cols, int tar)
{
    int low, mid, high, row_num, col_num, mid_element;
    low = 0;
    high = (rows * cols) - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        row_num = mid / cols;
        col_num = mid % cols;
        mid_element = arr[row_num][col_num];

        if (mid_element == tar)
        {
            return 1;
        }
        else if (mid_element > tar)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int matrix[][4] = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int rows = sizeof(matrix) / sizeof(matrix[0]);
    int cols = sizeof(matrix[0]) / sizeof(matrix[0][0]);
    int target;

    printf("Enter target number\n");
    scanf("%d", &target);
    if (searchMatrix(rows, matrix, cols, target) == 1)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }

    return 0;
}

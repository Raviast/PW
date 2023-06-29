// <aside>
// 💡 **Question 3**
// Given a 2D integer array matrix, return *the **transpose** of* matrix.

// The **transpose** of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.

// **Example 1:**

// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]

// Output: [[1,4,7],[2,5,8],[3,6,9]]

// </aside>

#include <stdio.h>
#include <stdlib.h>

int *transposeMatrix(int size, int (*arr)[size], int rows, int cols)
{
    int transpose[cols][rows];
    int *matrix = &transpose[0][0];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            transpose[j][i] = arr[i][j];
        }
    }
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            printf("%d  ", transpose[i][j]);
        }
        printf("\n");
    }
    
    return matrix;
}

int main()
{
    int matrix[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int rows = sizeof(matrix) / sizeof(matrix[0]);
    int cols = sizeof(matrix[0]) / sizeof(matrix[0][0]);
    printf("%d %d\n", rows, cols);

    int size = rows;
    int *result = transposeMatrix(size, matrix, rows, cols);
    return 0;
}

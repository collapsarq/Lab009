#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "multiply_matrices.h"

int main()
{
    int height1 = 0, wide1 = 0, height2 = 0, wide2 = 0, size = 0, result_size = 0;
    printf("Input height of first matrix: ");
    scanf("%d", &height1);
    printf("Input wide of first matrix: ");
    scanf("%d", &wide1);
    printf("Input height of second matrix: ");
    scanf("%d", &height2);
    printf("Input wide of first matrix: ");
    scanf("%d", &wide2);

    if ((height1 != wide2) || (height2 != wide1))
    {
        printf("Error! Invalid input.");
            return -1;
    }

    if (height1 >= wide1)
    {
        size = height1;
        result_size = wide1;
    }
    else
    {
        size = wide1;
        result_size = height1;
    }

    int** first_matrix = (int**)malloc(size * sizeof(int*));
    int** second_matrix = (int**)malloc(size * sizeof(int*));
    int** result_matrix = (int**)malloc(size * sizeof(int*));

    for (int i = 0; i < size; i++)
    {
        first_matrix[i] = (int*)malloc(size * sizeof(int));
        second_matrix[i] = (int*)malloc(size * sizeof(int));
        result_matrix[i] = (int*)malloc(size * sizeof(int));
    }

    printf("Input first matrix:\n");
    fill_matrix(height1, wide1, size, first_matrix);

    printf("Input second matrix:\n");
    fill_matrix(height2, wide2, size, second_matrix);

    multiply_matrices(size, first_matrix, second_matrix, result_matrix);

        printf("\nThe result of multiplying:\n");
        get_matrix(result_size, result_matrix);

            for (int i = 0; i < size; i++)
            {
                free(first_matrix[i]);
                free(second_matrix[i]);
                free(result_matrix[i]);
            }
        free(first_matrix);
        free(second_matrix);
        free(result_matrix);

        return 0;
}



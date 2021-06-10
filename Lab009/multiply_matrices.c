#define _CRT_SECURE_NO_WARNINGS
#ifndef MULTIPLY_MATRICES
#define MULTIPLY_MATRICES
#include <stdio.h>
#include "multiply_matrices.h"

void fill_matrix(int height, int wide, int size, int** matrix)
{
    int i = 0, j = 0;

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < wide; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
        if (wide < size)
        {
            for (j = wide; j < size; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }
    if (height < size)
    {
        for (i = height; i < size; i++)
        {
            matrix[i][j] = 0;
        }
    }
}

void multiply_matrices(int size, int** first_matrix, int** second_matrix, int** result_matrix) 
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
        {
            result_matrix[i][j] = 0;
            for (int k = 0; k < size; k++)
                result_matrix[i][j] += first_matrix[i][k] * second_matrix[k][j];
        }
}

void get_matrix(int size, int** matrix)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            printf("%3d ", matrix[i][j]);
        printf("\n");
    }
}
#endif
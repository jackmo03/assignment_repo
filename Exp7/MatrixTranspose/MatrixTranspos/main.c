#include <stdio.h>
#include <stdlib.h>

void InputMatrix(double *A,int m,int n)//输入矩阵
{
    int ret;
    for (int i=0; i<=m-1; i++)
    {
        for (int j=0; j<n; j++)
        {
            ret = scanf("%lf", &A[i*n+j]);
            if (ret!=1)
            {
                printf("Input error!\n");
                fflush(stdin);
                break;
            }
        }
        if (ret!=1)
            break;
    }
}

void PrintMatrix(double *A, int m, int n)//输出矩阵
{
    for (int i=0; i<=m-1; i++)
    {
        for (int j=0; j<n; j++)
            printf("%lg\t", A[i*n+j]);

        printf("\n");
    }
}

int main()
{
    int row, column, ret;
    double *matrix = NULL, *matrixT = NULL;
    printf("请输入矩阵的行数、列数(m n):\n");

    ret = scanf("%d %d", &row, &column);
    while (ret!=2)
    {
        printf("Input error!\n");
        fflush(stdin);
    }

    matrix  = (double*)calloc(row*column, sizeof(double));
    matrixT = (double*)calloc(column*row, sizeof(double));
    if (matrix == NULL || matrixT == NULL)
    {
        printf("Not enough memory!\n");
        exit(1);
    }

    else
    {
        for (int i=0; i<row; i++)
        {
            for (int j=0; j<column; j++)
                matrix[i*column+j] = 0;
        }

        printf("Please enter the matrix:\n");
        InputMatrix(matrix, row, column);

        for (int i=0; i<row; i++)
        {
            for (int j=0; j<column; j++)
                matrixT[j*row+i] = matrix[i*column+j];
        }
    }
    printf("The transposed matrix is:\n");
    PrintMatrix(matrixT, column, row);

    return 0;
}

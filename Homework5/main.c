#include <stdio.h>
#include <stdlib.h>

void InputMatrix(double *A,int m,int n)//�������
{
    for (int i=0; i<=m-1; i++)
    {
        for (int j=0; j<n; j++)
            scanf("%lf", &A[i*n+j]);
    }
}

void PrintMatrix(double *A, int m, int n)//�������
{
    for (int i=0; i<=m-1; i++)
    {
        for (int j=0; j<n; j++)
            printf("%lg\t", A[i*n+j]);

        printf("\n");
    }
}

void MulMatrix(int m,int n,int k,double *A,double *B,double *C)//AΪm��n�о���BΪn��k�о���
{
    for (int i=0; i<=m-1; i++)
    {
        for (int j=0; j<=k-1; j++)
        {
            for (int p=0; p<=n-1; p++)
                C[i*k+j] += A[i*n+p] * B[p*k+j];
        }
    }
}

int main()
{
    int rowA22,  columnA22, rowB22, columnB22;
    double *matrixA22 = NULL, *matrixB22 = NULL, *matrixC22 = NULL;
    printf("���������A��������������\n");
    scanf("%d%*c%d", &rowA22, &columnA22);

    matrixA22 = (double*)calloc(rowA22*columnA22, sizeof(double));
    if (matrixA22 == NULL)
    {
        printf("No enough memory!\n");
        exit(1);
    }

    printf("����������ʽA��\n");
    InputMatrix(matrixA22, rowA22, columnA22);

    printf("���������B��������������\n");
    scanf("%d%*c%d", &rowB22, &columnB22);

    matrixB22 = (double*)calloc(rowB22*columnB22, sizeof(double));
    if (matrixB22 == NULL)
    {
        printf("No enough memory!\n");
        exit(1);
    }

    if (rowB22 != columnA22)
        printf("Input error!\n");

    printf("����������ʽB��\n");
    InputMatrix(matrixB22, rowB22, columnB22);

    matrixC22 = (double*)calloc(rowA22*columnB22, sizeof(double));
    MulMatrix(rowA22, columnA22, columnB22, matrixA22, matrixB22, matrixC22);

    printf("Result:\n");
    PrintMatrix(matrixC22, rowA22, columnB22);

    free(matrixA22),free(matrixB22),free(matrixC22);
    return 0;
}

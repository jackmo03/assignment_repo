#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 51

void InputArray(char *A, int *B)
{
    int i, j, k;
    fgets(A, 50, stdin);
    for (i=MAXLEN-1; i>=0; i--)
    {
        if (*(A+i)!='\0' && *(A+i)!='\n')
        {
            k = i;
            break;
        }
    }

    for (j=0; i>=0 && j<=k; i--, j++)
    {
        if (*(A+i)>=48 && *(A+i)<=57)
            *(B+j) = *(A+i) - 48;
        else
        {
            printf("Input error!\n");
            fflush(stdin);
            break;
        }
    }
}

void OutputArray(int *A)
{
    int i=50;
    for (i=MAXLEN-1;i>0;i--)
    {
        if (A[i]!=0)
            break;
    }
    for (;i>=0;i--)
        printf("%d", A[i]);

    printf("\n");
}

void AddArray(int *A, int *B, int *C)
{
    int i, temp, carry;//carryÊÇ½øÎ»
	for(i=0, carry=0; i<=MAXLEN-1; i++)
	{
		temp = A[i] + B[i] + carry;
		carry = 0;
		C[i] = temp%10;
		carry = temp/10;
	}
}

int main()
{
    int partA[MAXLEN], partB[MAXLEN], sum[MAXLEN];
    char temp[MAXLEN], choice = 'n';
    do
    {
        for (int i=0; i<MAXLEN; i++)
            partA[i] = 0, partB[i] = 0, sum[i] = 0, temp[i] = '\0';

        printf("Please enter integer A:");
        InputArray(temp, partA);
        printf("Please enter integer B:");
        InputArray(temp, partB);
        AddArray(partA, partB, sum);

        printf("Result:\n");
        OutputArray(sum);

        printf("Do you want to exit?(Y/y):");
        scanf("%c", &choice);
    }while(choice!='Y' && choice!='y');
    return 0;
}

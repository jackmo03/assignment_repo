#include <stdio.h>
#include <stdlib.h>

int main()
{
    int factorA22, factorB22;//iΪ��ָ�꣬factorB22Ϊ��ָ��

    //ʹ��forѭ���ṹ
    printf(" 1  2  3  4  5  6  7  8  9\n");
    printf(" -  -  -  -  -  -  -  -  -\n");

    for (factorA22=1;factorA22<=9;factorA22++)
    {
        for (factorB22=1;factorB22<=9;factorB22++)
            printf("%2d ",factorA22*factorB22);

        printf("\n");
    }

    //ʹ��whileѭ���ṹ
    printf("\n 1  2  3  4  5  6  7  8  9\n");
    printf(" -  -  -  -  -  -  -  -  -\n");

    factorA22=factorB22=1;
    while (factorA22<=9)
    {
        while (factorB22<=9 && factorB22<=factorA22)
        {
            printf("%2d ",factorA22*factorB22);
            factorB22++;
        }
        printf("\n");
        factorB22=1;
        factorA22++;
    }

    //ʹ��do-while�ṹ
    printf("\n 1  2  3  4  5  6  7  8  9\n");
    printf(" -  -  -  -  -  -  -  -  -\n");

    factorA22=factorB22=1;
    do
    {
        do
        {
            if(factorB22>=factorA22)
                printf("%2d ",factorA22*factorB22);
            else
                printf("   ");
            factorB22++;

        }while(factorB22<=9);

        printf("\n");
        factorB22=1;
        factorA22++;

    }while(factorA22<=9);

    return 0;
}

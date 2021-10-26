#include <stdio.h>
#include <stdlib.h>

double fact(int n)
{
    int i;
    double result;
    for(i=0;i<=n;i++)
        if (i==1)
            result=1;
        else
            result=fact(i-1)*i;
    return result;
}

int main()
{
    int i;
    double sum=0;
    for(i=1;i<=10;i++)
        sum=sum+fact(i);
    printf("1!+2!...+10!=%f\n",sum);
    return 0;
}

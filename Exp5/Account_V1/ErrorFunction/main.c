#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    double sum;
    for(i=1;i<=10;i++)
        sum=sum+fact(i);
    printf("1!+2!...+10!=%f\n",sum);
    return 0;
}

double fact(int n)
{
    int i;
    double result;
    for(i=0;i<=n;i++)
        fact(n)=fact(i-1)*i;
    return result;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    double sum=1,item=1,eps=1e-6;
    for(i=1;item>=eps;i++)
    {
        item=fact(i)/multi(2*i+1);
        sum=sum+item;
    }
    printf("PI=%.5lf\n",sum*2);
    return 0;
}

int fact(int n)
{
    int i;
    int res;
    for(i=1;i<=n;i++)
        res=res*i;
    return res;
}
int multi(int n)
{
    int i;
    int res=1;
    for(i=3;i<=n;i=i+2)
        res=res*i;
    return res;
}

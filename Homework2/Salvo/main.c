#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i22, n22;//n为被淹没的次数

    for(i22=n22=0;i22<21;i22++)//计算被淹没的次数
    {
        if (5*i22%6==0)
            n22++;
        if (5*i22%7==0)
            n22++;
        if (6*i22%7==0)
            n22++;
    }
    printf("观众共听到%d次炮声.\n",21*3+1-n22);//由于0s时有一次炮声，需要+1

    return 0;
}

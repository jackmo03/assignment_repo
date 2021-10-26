//素数求和
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int iGroup=0, ret, iQuantity=0, iData, iDataSqrt, sum=0, iCounter1, iCounter2, iCounter3;

    //输入测试数据组数
    printf("请输入需要测试的组数M(0<M<10)：");
    ret = scanf("%d",&iGroup);

    //检查是否输入了合法数字
    if (ret!=1)
        printf("Input error!\n");

    else if (iGroup<=0||iGroup>=10)
        printf("Input error!\n");

    else
    {
        for (iCounter1=1;iCounter1<=iGroup;iCounter1++)
        {
            printf("请输入第%d组测试数据的数量N：",iCounter1);
            ret = scanf("%d",&iQuantity);

            if (ret!=1||iQuantity<=0)
            printf("Input error!\n");

            else
            {
                printf("请输入测试数据：");
                for (iCounter2=1,sum=0;iCounter2<=iQuantity;iCounter2++)
                {
                    scanf("%d",&iData);

                    if (fabs(iData)>=1000)
                        printf("Input error!\n");

                    else
                    {
                        //对素数的判定及处理
                        iDataSqrt=(int)sqrt( (double)iData );

                        for(iCounter3=2;iCounter3<=iDataSqrt;iCounter3++)
                            if(iData%iCounter3==0)
                                break;

                        if (iCounter3 > iDataSqrt && iData != 1)
                            sum = sum + iData;

                    }

                }

                printf("这组数据中所有的素数之和为：%d\n",sum);

            }

        }
    }

    return 0;
}

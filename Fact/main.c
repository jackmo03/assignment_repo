#include <stdio.h>
#include <stdlib.h>
#define RANGE 50

void ArrayMultiplication(int array22[], int factor)
{
    int i,j,temp,s22=1,carry22;//temp为阶乘元素与临时结果的乘积，carry22是进位 ，s22是位数
	array22[0]=1;
	for(i=2;i<=factor;i++)
	{
		for(j=1,carry22=0;j<=s22;j++)
		{
			temp=array22[j-1]*i+carry22;
			array22[j-1]=temp%10;
			carry22=temp/10;
		}
		while(carry22)//如果有进位就进入下面的循环
		{   s22++;        //增加进位，位数加1
            array22[s22-1]=carry22%10;
			carry22/=10;
		}
	}
}

void ArrayOutput(int array22[], int factor22)
{
    printf("%d!=", factor22);
    int i;
    for (i=RANGE-1;i>=0;i--)
    {
        if (array22[i]!=0)
            break;
    }

    for (;i>=0;i--)
        printf("%1d", array22[i]);

    printf("\n");
}

int main()
{
    int ret, counter22;
    int array22[RANGE];

    printf("请输入一个整数以计算阶乘：");
    ret = scanf("%d", &counter22);

    if (ret!=1||counter22<0||counter22>40)
    {
        printf("输入错误！\n");
        fflush(stdin);
    }

    else
    {
        if (counter22==0||counter22==1)
            printf("1");
        else
        {
            for (int i=1;i<=RANGE;i++)
                array22[i-1]=0;

            for (int factor22=1;factor22<=counter22;factor22++)
            {
                ArrayMultiplication(array22, factor22);
                ArrayOutput(array22, factor22);
            }
        }
    }


    return 0;
}

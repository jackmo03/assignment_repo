//�������
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int iGroup=0, ret, iQuantity=0, iData, iDataSqrt, sum=0, iCounter1, iCounter2, iCounter3;

    //���������������
    printf("��������Ҫ���Ե�����M(0<M<10)��");
    ret = scanf("%d",&iGroup);

    //����Ƿ������˺Ϸ�����
    if (ret!=1)
        printf("Input error!\n");

    else if (iGroup<=0||iGroup>=10)
        printf("Input error!\n");

    else
    {
        for (iCounter1=1;iCounter1<=iGroup;iCounter1++)
        {
            printf("�������%d��������ݵ�����N��",iCounter1);
            ret = scanf("%d",&iQuantity);

            if (ret!=1||iQuantity<=0)
            printf("Input error!\n");

            else
            {
                printf("������������ݣ�");
                for (iCounter2=1,sum=0;iCounter2<=iQuantity;iCounter2++)
                {
                    scanf("%d",&iData);

                    if (fabs(iData)>=1000)
                        printf("Input error!\n");

                    else
                    {
                        //���������ж�������
                        iDataSqrt=(int)sqrt( (double)iData );

                        for(iCounter3=2;iCounter3<=iDataSqrt;iCounter3++)
                            if(iData%iCounter3==0)
                                break;

                        if (iCounter3 > iDataSqrt && iData != 1)
                            sum = sum + iData;

                    }

                }

                printf("�������������е�����֮��Ϊ��%d\n",sum);

            }

        }
    }

    return 0;
}

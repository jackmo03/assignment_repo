#include <stdio.h>
#include <stdlib.h>

//�ж�ĳ���µ�����
int GetMonthDays(int iYear, int iMonth)
{
    int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int i=days[iMonth-1];

    if (iMonth==2)
    {
        if ((iYear%4==0 && iYear%100!=0) || iYear%400==0)
            i++;
    }
    return i;
}

//�ж�ĳ��ĳ��Ϊ�ܼ�
int GetWeekDay(int iYear,int iMonth,int iDay)
{
    int counter,temp,weekday,Days=0;

    for(counter=1;counter<=iMonth-1;counter++)
    {
        Days+=GetMonthDays(iYear,counter);
    }
    Days = Days + iDay;
    temp = (iYear-1)+(iYear-1)/4-(iYear-1)/100+(iYear-1)/400+Days;
    weekday = temp % 7;
    return weekday;
}

int main()
{
    int iDays, iMonth, iYear, iWeekday, counter, ret;

    printf("������1900����һ����ݣ�");
    ret=scanf("%d",&iYear);

    //�ж��Ƿ��зǷ��ַ�
    if (ret!=1||iYear<1900)
    {
        printf("Input error!\n");
        fflush(stdin);
    }

    else
    {
        for (iMonth=1;iMonth<=12;iMonth++)
        {
            //��ͷ
            printf("\n\n\t\t\t%d-%d\n", iYear, iMonth);
            printf("Sun\tMon\tTue\tWed\tThu\tFri\tSat\t\n");

            //�˸�
            iWeekday=GetWeekDay(iYear, iMonth, 1);
            for (counter=0;counter<iWeekday;counter++)
                printf("\t");

            //�������
            int temp1=GetMonthDays(iYear, iMonth);
            for (iDays=1;iDays<=temp1;iDays++)
            {
                printf("%2d\t", iDays);
                //����
                if ((iWeekday+iDays)%7==0)
                    printf("\n");
            }
        }
        printf("\n");
    }

    return 0;
}

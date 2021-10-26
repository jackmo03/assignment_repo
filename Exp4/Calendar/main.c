#include <stdio.h>
#include <stdlib.h>

//判断某个月的天数
int GetMonthDays(int iYear, int iMonth)
{
    int  D30[4]={4,6,9,11};

    if (iMonth==2)
    {
        if ((iYear%4==0 && iYear%100!=0) || iYear%400==0)
            return 29;
        else
            return 28;
    }

    else if (iMonth==D30[4])
        return 30;

    else
        return 31;

}

//判断某月某日为周几
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

    printf("请输入1900年后的一个年份：");
    ret=scanf("%d",&iYear);

    //判断是否有非法字符
    if (ret!=1||iYear<1900)
    {
        printf("Input error!\n");
        fflush(stdin);
    }

    else
    {
        for (iMonth=1;iMonth<=12;iMonth++)
        {
            //表头
            printf("\n\n\t\t\t%d-%d\n", iYear, iMonth);
            printf("Sun\tMon\tTue\tWed\tThu\tFri\tSat\t\n");

            //退格
            iWeekday=GetWeekDay(iYear, iMonth, 1);
            for (counter=0;counter<iWeekday;counter++)
                printf("\t");

            //输出日期
            int temp1=GetMonthDays(iYear, iMonth);
            for (iDays=1;iDays<=temp1;iDays++)
            {
                printf("%2d\t", iDays);
                //换行
                if ((iWeekday+iDays)%7==0)
                    printf("\n");
            }
        }
        printf("\n");
    }

    return 0;
}

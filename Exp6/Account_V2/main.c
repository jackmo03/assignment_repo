#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LENGTH 10

int uids[LENGTH],incomes[LENGTH],expenses[LENGTH];
char usernames[LENGTH][11];

void InputError()//只是一个用于报错和清除缓冲的函数（偷懒）
{
    printf("Input error!\n");
    fflush(stdin);
}

void Swap(int *x, int *y)//交换两个数
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void OutputDatas()//输出全部数据
{
    printf("ID\t  UserName\tIncome\tExpenses\t\n");
    for (int i=0; i<=(LENGTH-1); i++)
    {
        if (uids[i] >= 0)
            printf("%d\t%10s\t%d\t%d\t\n",uids[i],usernames[i],incomes[i],expenses[i]);
    }
}

int UsernameSearch(char name[], int counter)//查找
{
    int k = -1;
    for (int i=0; i<=counter; i++)
    {
        if (strcmp(name, usernames[i])==0)
            k = i;
    }
    return k;
}

int main()
{
    int ret = 0, choice = -1, counter = 0, sumIncome = 0, sumExpense = 0;//choice记录选项，counter保存数据的数量
    char name[11];
    //数组的初始化
    for (int i=0; i<=(LENGTH-1); i++)
        uids[i] = -1, incomes[i] = -1, expenses[i] = -1;
    //循环加载菜单
    do
    {
        printf("1.Input record\n2.Sort and list records in alphabetical order by user name\n3.Search records by user name\n4.Calculate and list per capita income and expenses\n5.List records which have more expenses than per capita expenses\n6.List all records\n0．Exit\nPlease enter your choice:");
        ret = scanf("%1d",&choice);
        if (ret!=1 || choice<0 || choice>6)
            InputError();
        else if (choice>1 && choice<=6 && counter==0)
            printf("Please select 1 to enter data first!\n\n");
        else
        {
            switch (choice)
            {
                //录入用户ID，用户名，本月收入，本月支出
                case 1:
                    printf("Please enter the number of users:");
                    scanf("%d",&counter);
                    printf("Please enter data(ID Username Income Expenses).\n");
                    for (int i=1; i<=counter; i++)
                    {
                        int ret, uid, income, expense;
                        char TEMP[11];
                        ret=scanf("%d %10s %d %d", &uid, TEMP, &income, &expense);
                        if (ret==4 && counter<=(LENGTH-1))
                        {
                            if (uid>=0 && uid<=99999 && income>=0 && expense>=0)
                            {
                                if (uid==uids[i-2])
                                {
                                    printf("This ID has been recorded!\n");
                                    fflush(stdin);
                                }
                                else
                                {
                                    uids[i-1] = uid, incomes[i-1] = income, expenses[i-1] = expense;
                                    strcpy(usernames[i-1], TEMP);
                                }
                            }
                            else if(uid==-1)
                                break;
                            else
                                InputError();
                        }
                        else
                            InputError();
                    }
                    break;
                //字典排序及输出
                case 2:
                    for (int i=0; i<counter-1; i++)
                    {
                        char temp[11];
                        for (int j=i+1; j<counter; j++)
                        {
                            if (strcmp(usernames[i], usernames[j])>0)
                            {
                                strcpy(temp, usernames[i]);
                                strcpy(usernames[i], usernames[j]);
                                strcpy(usernames[j], temp);
                                Swap(&uids[j], &uids[i]);
                                Swap(&expenses[j], &expenses[i]);
                                Swap(&incomes[j], &incomes[i]);
                            }
                        }
                    }
                    OutputDatas();
                    break;
                //通过用户名查找
                case 3:
                    printf("Please input the user name:\n");
                    scanf("%s", name);
                    ret = UsernameSearch(name, counter);
                    printf("Searching for \"%s\"...\n", name);
                    if (ret == -1)
                        printf("Not found!\n");
                    else
                    {
                        printf("ID\t  UserName\tIncome\tExpenses\t\n");
                        printf("%d\t%10s\t%d\t%d\t\n",uids[ret],usernames[ret],incomes[ret],expenses[ret]);
                    }
                    break;
                //计算平均收入、平均支出
                case 4:
                    for (int i=0; i<=counter; i++)
                    {
                        if (uids[i]!=-1)
                        sumIncome += incomes[i], sumExpense += expenses[i];
                    }
                    printf("Per capita income:%d\t\nPer capita expenses:%d\t\n", sumIncome/counter, sumExpense/counter);
                    break;
                //找出所有支出大于收入的用户记账信息
                case 5:
                    for (int i=0;i<=(LENGTH-1);i++)
                    {
                        if (incomes[i]<expenses[i])
                        {
                            printf("ID\t  UserName\tIncome\tExpenses\t\n");
                            printf("%d\t%10s\t%d\t%d\t\n",uids[i],usernames[i],incomes[i],expenses[i]);
                        }
                    }
                    break;
                //输出系统中所有的记账信息（按ID升序）
                case 6:
                    for (int i=0; i<(counter-1); i++)
                    {
                        int k=i;
                        for (int j=i+1; j<counter; j++)
                        {
                            if (uids[j]<uids[k])
                                k=j;
                        }
                        if (k!=i)
                        {
                            Swap(&uids[k], &uids[i]);
                            Swap(&expenses[k], &expenses[i]);
                            Swap(&incomes[k], &incomes[i]);
                            char temp[11];
                            strcpy(temp, usernames[i]);
                            strcpy(usernames[i], usernames[k]);
                            strcpy(usernames[k], usernames[i]);
                        }
                    }
                    OutputDatas();
                    break;
                default://退出程序
                    printf("Exit...");
            }
        printf("\n\n");
        }
    }while(choice!=0);
    return 0;
}

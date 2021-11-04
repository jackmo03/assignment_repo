#include <stdio.h>
#include <stdlib.h>
#define RANGE 10

int uids[RANGE],incomes[RANGE],expenses[RANGE];
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

int InputRecord()//录入用户ID，本月收入，本月支出
{
    int uid, income, expense, counter = 0;
    printf("Please enter data(ID Income Expenses).\n");
    do{
        int ret;
        ret=scanf("%d,%d,%d", &uid, &income, &expense);
        if (ret==3 && counter<=(RANGE-1))
        {
            if (uid>=0 && uid<=99999 && income>=0 && expense>=0)
                uids[counter] = uid, incomes[counter] = income, expenses[counter] = expense;
            else if (uid==-1 && income==-1 && expense==-1)
                continue;
            else
                InputError();
        }
        else
            InputError();

        counter++;
    }while(uid>=0&&income>=0&&expense>=0);
    return counter;
}

void OutputDatas()//输出全部数据
{
    printf("ID\tIncome\tExpenses\t\n");
    for (int i=0; i<=(RANGE-1); i++)
    {
        if (uids[i] >= 0)
            printf("%d\t%d\t%d\t\n",uids[i],incomes[i],expenses[i]);
    }
}

void SelectionSortOrder(int uids[], int expenses[], int choice,int counter)//选择排序
{
    int i, j, k;
    for (i=0; i<(counter-1); i++)
    {
        k=i;
        for (j=i+1; j<counter; j++)
        {
            if ((choice==2 && expenses[j]>expenses[k]) || (choice==3 && expenses[j]<expenses[k]) || (choice==7 && uids[j]<uids[k]))
                k=j;
        }
        if (k!=i)
        {
            Swap(&uids[k], &uids[i]);
            Swap(&expenses[k], &expenses[i]);
            Swap(&incomes[k], &incomes[i]);
        }
    }
}

void BubbleSortOrder(int incomes[], int choice)//冒泡排序
{
    int i, j;
    for (i=0; i<(choice-1); i++)
    {
        for (j=i+1;j<choice;j++)
        {
            if (incomes[j]<incomes[i])
            {
                Swap(&uids[j], &uids[i]);
                Swap(&incomes[j], &incomes[i]);
                Swap(&expenses[j], &expenses[i]);
            }
        }
    }
}

int BinSearch(int id)//查找
{
    int low = 0, high = (RANGE-1), mid;
    while (low<=high)
    {
        mid = (high+low)/2;
        if (id>uids[mid])
            low = mid+1;
        else if (id<uids[mid])
            high = mid-1;
        else
            return mid;
    }
    return -1;
}

int main()
{
    int ret = 0, choice = -1, counter = 0, id;
    //数组的初始化
    for (int i=0; i<=(RANGE-1); i++)
        uids[i] = -1, incomes[i] = -1, expenses[i] = -1;
    do
    {
        printf("Menu\n");
        printf("1. Input record\n");
        printf("2. Selection Sort in descending order by expenses\n");
        printf("3. Selection Sort in ascending order by expenses\n");
        printf("4. Bubble Sort in ascending order by income\n");
        printf("5. Search records by ID using Binary Search\n");
        printf("6. List records which have more expenses than income\n");
        printf("7. List all records\n");
        printf("0. Exit.\n");
        printf("   Please enter your choice:");

        ret = scanf("%1d",&choice);
        if (ret!=1 || choice<0 || choice>7)
            InputError();
        else
        {
            switch (choice)
            {
                //录入用户ID，本月收入，本月支出
                case 1:
                    counter = InputRecord();
                    break;
                //选择排序法及输出
                case 2:
                case 3:
                case 7:
                    SelectionSortOrder(uids, expenses, choice, counter);
                    OutputDatas();
                    break;
                //冒泡排序法
                case 4:
                    BubbleSortOrder(incomes, counter);
                    OutputDatas();
                    break;
                //查询ID并输出
                case 5:
                    printf("Please enter the user ID:");
                    ret=scanf("%d",&id);
                    if (ret!=1||id<0||id>99999)
                        InputError();
                    else
                    {
                        int temp=BinSearch(id);
                        if (temp!=-1)
                        {
                            printf("ID\tIncome\tExpenses\t\n");
                            printf("%d\t%d\t%d\t\n",uids[temp],incomes[temp],expenses[temp]);
                        }
                        else
                            printf("The ID doesn't exist.");
                    }
                    break;
                //找出所有支出大于收入的用户记账信息
                case 6:
                    for (int i=0;i<=(RANGE-1);i++)
                    {
                        if (incomes[i]<expenses[i])
                        {
                            printf("ID\tIncome\tExpenses\t\n");
                            printf("%d\t%d\t%d\t\n",uids[i],incomes[i],expenses[i]);
                        }
                    }
                    break;
                default:
                    printf("Exit...");
            }
        printf("\n");
        }
    }while(choice!=0);
    return 0;
}

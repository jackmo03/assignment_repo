#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 20

int main()
{
    int i, j, len, temp;
    char str[MAXLEN+1], tempStr[MAXLEN+1];
    for (i=0; i<=MAXLEN+1; i++)
        str[i] = '\0', tempStr[i] = '\0';

    printf("Please enter a string:\n");

    for (len=0; len<MAXLEN;)
    {
        temp = getchar();
        if (temp=='\n')
            break;
        else
        {
            str[len] = temp;
            len++;
        }
    }

    for (i=len-1, j=0; i>=0 && j<=len; i--, j++)
        tempStr[j] = str[i];

    if (strcmp(str, tempStr)==0 || len==0)
        printf("\"%s\" 是回文字符串.\n", str);
    else
        printf("\"%s\" 不是回文字符串.\n", str);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y, z, temp;
    printf("�蹫��xֻ��ĸ��yֻ��С��zֻ\n");

    for (int i=1;i<=100;i++)
    {
        temp = 200-8*i;
        if (temp%14==0)
        {
            x = temp/14;
            y = i;
            z = 100-x-y;

            if (x>0&&z>0)
                printf("x=%d,y=%d,z=%d\n",x,y,z);
        }
    }
    return 0;
}

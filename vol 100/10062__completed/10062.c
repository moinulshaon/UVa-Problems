#include <stdio.h>


int main()
{

    int count[130],i,j,asciiVal,flag,min;
    char c[1010];
    for (j=0;gets(c);++j)
    {
        for (i=0;i<130;++i)
            count[i]=0;
        for (i=0;c[i]!='\0';++i)
            ++count[(int)c[i]];
        if (j)
            printf("\n");

        while (1)
        {
            flag=1;
            min=1100;
            for (i=129;i>=0;--i)
            {
                if (count[i]<min && count[i]!=0)
                {
                    flag=0;
                    min=count[i];
                    asciiVal=i;
                }
            }
            if (flag)
                break;
            printf("%d %d\n",asciiVal,min);
            count[asciiVal]=0;
        }
    }
    return (0);
}

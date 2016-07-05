#include <stdio.h>

void printResult(char *fibonacci)
{
    int i,flag=0;
    for (i=0;i<252;++i)
    {
        if (fibonacci[i]=='0')
            continue;
        else
        {
            printf("%s\n",&fibonacci[i]);
            return ;
        }
    }
}


int main()
{
    char fibonacci[1001][252];
    int i,j,digit=1,number;

    for (i=0;i<1001;++i)
        for (j=0;j<251;++j)
            fibonacci[i][j]='0';
    for (i=0;i<1001;++i)
        fibonacci[i][251]='\0';

    fibonacci[0][250]='1';
    fibonacci[1][250]='2';

    for (i=2;i<1001;++i)
    {
        for (j=250;j>250-digit;--j)
        {
            fibonacci[i][j]+=fibonacci[i-1][j]+fibonacci[i-2][j]-2*'0';
            if (fibonacci[i][j]>'9')
            {
                fibonacci[i][j]-=10;
                fibonacci[i][j-1]+=1;
                if (j==250-digit+1)
                    ++digit;
            }
        }
    }

    while (scanf("%d",&number)==1)
    {
        printResult(fibonacci[number]);
    }
    return (0);

}

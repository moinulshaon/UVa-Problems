#include <stdio.h>
#include <stdlib.h>

void printResult(char *fibonacci)
{
    int i,flag=0;
    for (i=0;i<1152;++i)
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
    char fibonacci[4900][1102];
    int i,j,digit=1,number;
	/*char **fibonacci;
	fibonacci=(char**)malloc(sizeof(char*)*4900);
	for (i=0;i<=5000;++i)
		fibonacci[i]=(char*)malloc(sizeof(char)*1102);*/

    for (i=0;i<4900;++i)
        for (j=0;j<1101;++j)
            fibonacci[i][j]='0';
    for (i=0;i<4900;++i)
        fibonacci[i][1101]='\0';

    fibonacci[0][1100]='1';
    fibonacci[1][1100]='1';

    for (i=2;i<4900;++i)
    {
        for (j=1100;j>1100-digit;--j)
        {
            fibonacci[i][j]+=fibonacci[i-1][j]+fibonacci[i-2][j]-2*'0';
            if (fibonacci[i][j]>'9')
            {
                fibonacci[i][j]-=10;
                fibonacci[i][j-1]+=1;
                if (j==1100-digit+1)
                    ++digit;
            }
        }
    }

    while (scanf("%d",&number)==1)
    {
        printResult(fibonacci[number-1]);
    }
    return (0);

}

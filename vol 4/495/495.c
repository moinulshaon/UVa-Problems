#include <stdio.h>
#include <stdlib.h>
#define limit 5000

void add(char *result,char *a,char *b,int *digit)
{
    int i;
    for (i=1099;i>1099-*digit;--i)
    {
        result[i]+=a[i]+b[i]-2*'0';
        if (result[i]>'9')
        {
            result[i]-=10;
            result[i-1]+=1;
            if (i==1099-*digit+1)
                ++*digit;
        }

    }
    return ;
}
void printresult(char *result)
{
    int i;
    for (i=0;i<1100;++i)
    {
        if (result[i]=='0')
            ;
        else
        {
            printf("%s\n",&result[i]);
            return ;
        }
    }
}

int main()
{
	char result[limit][1101];
	int number,i,j,digit;

	for (i=0;i<limit;++i)
        for (j=0;j<1100;++j)
            result[i][j]='0';
    for (i=0;i<limit;++i)
        result[i][1100]='\0';
    digit=1;
    result[0][1099]=result[1][1099]='1';
	for (i=2;i<limit;++i)
	{
        add(result[i],result[i-1],result[i-2],&digit);
	}

	while (scanf("%d",&number)==1)
    {
        if (number==0)
        {
            printf("The Fibonacci number for 0 is 0\n",number);
            continue;
        }
        printf("The Fibonacci number for %d is ",number);
        printresult(result[number-1]);
    }
    return (0);

}

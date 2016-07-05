#include <stdio.h>
#define size 1000000

char digit1[size+1],digit2[size+1],result[size+1];

int main()
{
	

	int test,digitNumber,i,j;


	scanf("%d",&test);

	for (j=0;j<test;++j)
	{
		scanf("%d",&digitNumber);
		for (i=0;i<digitNumber;++i)
		{
			scanf("%1s %1s",&digit1[i],&digit2[i]);

		}
		for (i=0;i<digitNumber;++i)
			result[i]='0';
		for (i=digitNumber-1;i>=0;--i)
		{
			result[i]+=digit1[i]+digit2[i]-'0'-'0';
			if (result[i]>'9')
			{
				result[i]-=10;
				result[i-1]+=1;
			}
		}
		result[digitNumber]='\0';
		if (j)
			printf("\n");
		printf("%s\n",result);
	}
	return (0);
}
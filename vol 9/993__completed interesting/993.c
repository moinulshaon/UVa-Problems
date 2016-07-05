#include <stdio.h>
#include <math.h>

int main()
{
	unsigned long int number1,number2;
	int test,i,j,flag,length;

	scanf("%d",&test);

	for (j=0;j<test;++j)
	{
		scanf("%lu",&number1);

		
		if (number1==1)
		{
			printf("1\n");
			continue;
		}
		else if (number1==0)
		{
			printf("10\n");
			continue;
		}
		length=0;
		number2=0;
		while (number1!=1)
		{
			flag=1;
			for (i=9;i>1;--i)
			{
				if (number1%i==0)
				{
					flag=0;
					number2+=i*(unsigned long)pow(10,length++);
					number1/=i;
					break;
				}
			}
			if (flag)
			{
				printf("-1\n");
				break;
			}
		}
		if(!flag)
			printf("%lu\n",number2);
	}
	return (0);
}
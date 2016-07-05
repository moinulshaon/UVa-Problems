#include <stdio.h>
#include <math.h>
int hexadecimal(int number)
{
	int sum=0,i;
	for (i=0;number!=0;++i)
	{
		sum+=(number%10)*(int)pow(16,i);
		number/=10;
	}
	return (sum);
}

int main()
{
	int number,n,i,number2,count1,count2;

	scanf("%d",&n);

	for (i=0;i<n;++i)
	{
		count1=count2=0;
		scanf("%d",&number);
		number2=hexadecimal(number);
		while (number!=0)
		{
			if (number%2==1)
				++count1;
			number/=2;
		}
		while (number2!=0)
		{
			if (number2%2==1)
				++count2;
			number2/=2;
		}

		printf("%d %d\n",count1,count2);
	}
	return (0);
}
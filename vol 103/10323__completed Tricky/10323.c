#include <stdio.h>

long long factorial(long long n)
{
	if (n==1)
		return 1;
	else
		return n*factorial(n-1);
}

int main()
{
	long long number;

	while (scanf("%lld",&number)!=EOF)
	{
		if (number<0)
		{
			if (-number%2)
			{
				printf("Overflow!\n");
			}
			else
			{
				printf("Underflow!\n");
			}
		}
		else if (number>13)
		{
			printf("Overflow!\n");
		}
		else if (number<8)
		{
			printf("Underflow!\n");
		}
		else
			printf("%lu\n",factorial(number));
	}
	return (0);
}
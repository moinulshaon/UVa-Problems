#include <stdio.h>

int main()
{
	long int num,div,sum;

	while (scanf("%ld %ld",&num,&div)==2)
	{
		sum=num;
		while (num>=div)
		{
			sum+=num/div;
			num=num/div+num%div;
			
		}
		printf("%ld\n",sum);
	}
	return 0;
}



#include <stdio.h>

int main()
{
	long long int number;

	while (1)
	{
		scanf("%lld",&number);
		if (number<0)
			return 0;
		if (number==1)
			printf("0%%\n");
		else 
		{	
			printf("%lld%%\n",number*25);
		}
	}
}
#include <stdio.h>

int main()
{
	unsigned long int number,sum;
	int i;
	while (scanf("%lu",&number)!=EOF)
	{
		sum=1;
		for (i=0;sum<number;++i)
		{
			if (i%2)
				sum*=2;
			else
				sum*=9;
		}
		
		if (i%2)
			printf("Stan wins.\n");
		else
			printf("Ollie wins.\n");
	}
	return (0);
}
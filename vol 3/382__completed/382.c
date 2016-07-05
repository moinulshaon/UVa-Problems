#include <stdio.h>

int main()
{
	int number,i;
	int sum;
	printf("PERFECTION OUTPUT\n");
	while (1)
	{
		sum=0;
		scanf("%d",&number);
		if (number==0)
			break;
		for (i=1;i<number;++i)
		{
			if (number%i==0)
			{
				sum+=i;
			}
		}
		if (sum==number)
			printf("%5d  PERFECT\n",number);
		else if(sum<number)
			printf("%5d  DEFICIENT\n",number);
		else 
			printf("%5d  ABUNDANT\n",number);

	}
	printf("END OF OUTPUT\n");
	return (0);
}
#include <stdio.h>

int main()
{
	int number,i,temp1,temp2,save;
	int primes[25] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
	int count[25];

	while (1)
	{
		scanf("%d",&number);
		if (number==0)
			break;

		for (i=0;i<25;++i)
			count[i]=0;

		temp1=temp2=number+1;
		while (temp1>1)
		{
			--temp1;
			number=temp1;
			for (i=0;i<25;++i)
			{
				while (number%primes[i]==0)
				{
					number/=primes[i];
					++count[i];
				}
				
			}

		}


		save=0;
		printf("%3d! =",temp2-1);
		for (i=0;i<25;++i)
		{
			
			if (count[i]!=0 && save<15)
			{
				printf("%3d",count[i]);
				++save;
			}
			else if (count[i]!=0)
			{
				if (save==15)
				{	
					printf("\n      ");
					++save;
				}
				printf("%3d",count[i]);
			}
		}
		printf("\n");
		
	}
	return (0);
}
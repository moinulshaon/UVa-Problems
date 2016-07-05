#include <stdio.h>

int single_num_cycle(int n);
int main()
{
	
	int a,b,i,j;
	int count=0,numbers_of_steps,max_steps;

	while(scanf("%d %d",&a,&b)==2)
	{	
		max_steps=0;
		i=a;
		j=b;
		if (a>b)
			a^=b^=a^=b;
		for (;a<=b;++a)
		{
			numbers_of_steps=single_num_cycle(a);
			if (numbers_of_steps>max_steps)
				max_steps=numbers_of_steps;
			
		}
		printf("%d %d %d\n",i,j,max_steps);
	}
	return 0;
}
int single_num_cycle(int n)
{
	int number=1;
	while(n!=1)
	{
		n=(n & 1)?(3*n+1):(n>>1);
		++number;
	}
	return (number);
}
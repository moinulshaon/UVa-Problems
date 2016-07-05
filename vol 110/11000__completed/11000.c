#include <stdio.h>

int main()
{
	unsigned female[100],male[100];
	int i,year;

	female[0]=1;
	female[1]=1;
	male[0]=0;
	male[1]=1;
	for (i=2;i<=50;++i)
	{
		female[i]=female[i-1]+female[i-2];
		male[i]=male[i-1]+female[i-1];
	}

	while (1)
	{
		scanf("%d",&year);
		if (year==-1)
			return (0);
		printf("%u %u\n",male[year],male[year]+female[year]);
	}
}
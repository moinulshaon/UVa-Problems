#include <stdio.h>

int main()
{
	int j,i=0;
	unsigned  long number,kuti[2],shata[2],hazar[2],lakh[2],rest;
	
	while (scanf("%llu",&number)!=EOF)
	{	if (number==0)
		{
			printf("   %d. 0\n",i+1);
			++i;
			continue;
		}
		for (j=0;j<2;++j)
		{
			rest=0;
			shata[j]=lakh[j]=hazar[j]=kuti[j]=0;
		}
		rest=number%100;
		number/=100;
		for (j=0;number!=0;++j)
		{
		
		shata[j]=number%10;
		number/=10;
		hazar[j]=number%100;
		number/=100;
		lakh[j]=number%100;
		number/=100;
		kuti[j]=number%100;
		number/=100;
		}
		printf("   %d. ",i+1);
		for (j=1;j>=0;--j)
		{
			if (kuti[j])
				printf("%llu kuti ",kuti[j]);
			if (lakh[j])
				printf("%llu lakh ",lakh[j]);
			if (hazar[j])
				printf("%llu hajar ",hazar[j]);
			if (shata[j])
				printf("%llu shata ",shata[j]);
		}
		if (rest)
			printf("%llu",rest);
		printf("\n");
		++i;

	}
	return (0);
}
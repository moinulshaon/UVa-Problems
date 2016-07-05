#include <stdio.h>

int squres[317];
int main()
{
	register i;
	int result[100001],save=0,already=1,lower,higher;

	for (i=1;i<317;++i)
		squres[i]=i*i;

	for (i=0;i<100001;++i)
	{
		if (i==squres[already])
		{
			result[i]=save+=1;
			++already;
		}
		else
			result[i]=save;
	}
	while (1)
	{
		scanf("%d %d",&lower,&higher);
		if (lower==0 && higher ==0)
			return 0;
		printf("%d\n",result[higher]-result[lower-1]);
	}
}
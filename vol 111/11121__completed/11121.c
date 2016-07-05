#include <stdio.h>
#include <math.h>

void baseminus2(int number)
{
	if (!number)
		return ;
	else 
	{
		baseminus2((int)ceil((double)(number)/-2));
		printf("%d",abs(number%2));
		
	}
}

int main()
{
	int test,m,input;

	scanf("%d",&test);

	for (m=1;m<=test;++m)
	{
		scanf("%d",&input);

		if (!input)
		{
			printf("Case #%d: 0\n",m);
			continue;
		}
		printf("Case #%d: ",m);
		baseminus2(input);
		printf("\n");
	}
	return 0;
}
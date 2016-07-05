#include <stdio.h>
#include <math.h>
#define LONG long long

int main()
{
	LONG input,root,prv,now,result,i;
	int test;

	scanf("%d",&test);

	while (test--)
	{
		scanf("%lld",&input);

		if (input<1)
		{
			printf("0\n");
			continue;
		}
		result=0;
		root=(LONG)sqrt(input);
		prv=input;

		for (i=1;i<=root;++i)
		{
			now=input/i;

			result+=now;
			result+=(prv-now)*(i-1);

			prv=now;
		}

		if (prv>root)
			result+=root;
		printf("%lld\n",result);
	}

}
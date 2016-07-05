#include <stdio.h>

int main()
{
	int a,b,test,i,j,sum,temp;

	scanf("%d",&test);

	for (i=1;i<=test;++i)
	{
		scanf("%d %d",&a,&b);

		if (b<a)
		{
			temp=b;
			b=a;
			a=temp;
		}
		sum=0;
		if (a%2==0)
			++a;
		j=a;
		for (;j<=b;j+=2)
			sum+=j;
		printf("Case %d: %d\n",i,sum);
	}
	return (0);
}
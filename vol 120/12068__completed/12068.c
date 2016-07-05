#include <stdio.h>
#define LONG long long

LONG gcd(LONG m,LONG n)
{
	LONG temp;
	if (n>m)
		n^=m^=n^=m;
	while (n!=0)
	{
		temp=n;
		n=m%n;
		m=temp;
	}
	return (temp);
}


int main()
{
	int test,k,i,h;
	LONG num,den,temp;

	scanf("%d",&test);

	for (k=1;k<=test;++k)
	{
		scanf("%d",&h);

		scanf("%lld",&den);
		num=1;

		for (i=1;i<h;++i)
		{
			scanf("%lld",&temp);
			num=num*temp+den;;
			den=den*temp;


			temp=gcd(num,den);

			if (temp>1)
			{
				den/=temp;
				num/=temp;
			}

		}
		den*=h;
		temp=gcd(num,den);

		if (temp>1)
		{
			den/=temp;
			num/=temp;
		}

		printf("Case %d: %lld/%lld\n",k,den,num);


	}
	return 0;

}

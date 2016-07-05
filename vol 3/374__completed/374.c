#include <stdio.h>

long bigmod(long b,long p,long m) { 
	if (p == 0) 
		return 1; 
	else if (p%2 == 0) 
	{
		long temp=bigmod(b,p/2,m)%m;
		return temp*temp % m;
	}
	else 
		return ((b % m) * bigmod(b,p-1,m)) % m; 
}

int main()
{
	long b,p,m,temp;

	while(scanf("%ld %ld %ld",&b,&p,&m)==3)
	{
		temp=bigmod(b,p,m);
		printf("%ld\n",temp);
	}

	return (0);
}
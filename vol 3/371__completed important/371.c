#include <stdio.h>

long ackermann(long n)
{
	long step=0;
	do
	{
		n=(n & 1)?(3*n+1):(n>>1);
		++step;
	}
	while (n!=1);
	return (step);
}

int main()
{
	long a,b,temp,maxnumber,maxstep,i;

	while (1)
	{
		scanf("%ld %ld",&a,&b);
		if (a==0 && b==0)
			break;
		if (b<a)
			a^=b^=a^=b;

		maxnumber=maxstep=0;
		for (i=a;i<=b;++i)
		{
			temp=ackermann(i);
			if (temp>maxstep)
			{
				maxstep=temp;
				maxnumber=i;
			}
		}
		printf("Between %ld and %ld, %ld generates the longest sequence of %ld values.\n",a,b,maxnumber,maxstep);
	}
	return (0);
}

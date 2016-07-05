#include <stdio.h>
#define size 20000000
char primes[size+1];

int main()
{
	int number,pairno,pairs1[100001];
	register i,j;
	for (i=0;i<=size;++i)
		primes[i]=1;

	for (i=2;i<=4472;++i)
		if (primes[i])
			for (j=i*2;j<=size;j+=i)
				primes[j]=0;

    primes[0]=primes[1]=0;
	pairno=1;
	for (i=3;pairno<100001 && i<size;++i)
		if (primes[i]+primes[i+2]==2)
			pairs1[pairno++]=i;
	while (scanf("%d",&number)==1)
		printf("(%d, %d)\n",pairs1[number],pairs1[number]+2);

	return (0);
}

#include <stdio.h>
#include <math.h>
#define size 1000000
int power (int n)
{
    int sum=1,i;
    for (i=0;i<n;++i)
    {
        sum*=10;
    }
    return sum;
}
int primes[size+1];
int main()
{

	int i,j,number,revnumber,temp,len;

	for (i=0;i<=size;++i)
		primes[i]=1;

	primes[0]=primes[1]=0;
	for (i=2;i<=1000;++i)
		if (primes[i])
			for (j=2*i;j<=size;j+=i)
				primes[j]=0;
	while (scanf("%d",&number)==1)
	{
		if (!primes[number])
		{
			printf("%d is not prime.\n",number);
			continue;
		}
		revnumber=0;
		temp=number;
		for (i=0;temp!=0;++i)
			temp/=10;
		len=--i;

		temp=number;
		for (i=0;temp!=0;++i)
		{
			revnumber+=(temp%10)*power(len-i);
			temp/=10;
		}

		if (primes[revnumber] && number!=revnumber)
			printf("%d is emirp.\n",number);
		else
			printf("%d is prime.\n",number);

	}
	return (0);
}

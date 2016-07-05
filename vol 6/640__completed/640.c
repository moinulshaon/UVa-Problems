#include <stdio.h>


char self[1001000];
int main()
{
	register i,temp;
	int sumOfDigit;

	for (i=1;i<=1000000;++i)
		self[i]=1;
	for (i=1;i<=1000000;++i)
	{
		temp=i;
		sumOfDigit=0;
		while (temp)
		{
			sumOfDigit+=temp%10;
			temp/=10;
		}
		self[i+sumOfDigit]=0;
	}
	for (i=1;i<=1000000;++i)
		if (self[i])
			printf("%d\n",i);
	return 0;
}
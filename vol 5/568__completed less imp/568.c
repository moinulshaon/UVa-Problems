#include <stdio.h>


int result[10001];
int main()
{
	int i=1,temp,input,digit;

	result[0]=1;
	for (temp=1;temp<=10000;++temp)
	{
		i=i*temp;
		while (i%10==0)
			i/=10;
		i%=100000;
		result[temp]=i;

	}

	while (scanf("%d",&input)==1)
	{
		while (result[input]%10==0)
			result[input]/=10;
		digit=result[input]%10;
		printf("%5d -> %d\n",input,digit);
	}
	return 0;
}
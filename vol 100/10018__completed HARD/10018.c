#include <stdio.h>
#include <string.h>
unsigned long long int power(int x,int y)
{
	unsigned long long int num=1;
	for (;y>0;--y)
		num*=x;
	return (num);
}

int palindrome(unsigned long long int number)
{
	unsigned long long int temp;
	int j,k=0;
	temp=number;
	while (temp!=0)
	{
		temp/=10;
		++k;
	}
	
	for (j=0;j<k/2;++j)
	{
		if (number%power(10,j+1)/power(10,j)!=number%power(10,k-j)/power(10,k-j-1))
			return (0);
	}
	return (1);

}
unsigned long long int reverse(unsigned long long int number)
{
	unsigned long long int number2=0,temp;
	int k=0;
	temp=number;
	while (temp!=0)
	{
		temp/=10;
		++k;
	}
	for (;k>=0;--k)
	{
		number2+=(number%10)*power(10,k-1);
		number/=10;
	}
	return (number2);

}


int main()
{
	unsigned long long int number,number2;
	int i,steps,n;

	scanf("%d",&n);
	for (i=0;i<n;++i)
	{
		steps=0;
		scanf("%llu",&number);
		
		while (!palindrome(number))
		{
			number2=reverse(number);
			number+=number2;
			++steps;
		}
		printf("%d %llu\n",steps,number);
	}
	return (0);
}
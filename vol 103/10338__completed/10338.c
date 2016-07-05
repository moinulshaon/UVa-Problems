#include <stdio.h>
#include <string.h>

unsigned long long factorial(unsigned long long number)
{
	if (number==2)
		return (2);
	else
		return number*factorial(number-1);
}

int main()
{
	unsigned long long number;
	char arr[21],letter[26];
	int n,len,i,j;

	scanf("%d",&n);

	for (j=1;j<=n;++j)
	{
		scanf("%s",arr);
		for (i=0;i<26;++i)
			letter[i]=0;

		len=strlen(arr);

		for (i=0;i<len;++i)
			letter[arr[i]-'A']+=1;
		number=factorial(len);
		for (i=0;i<26;++i)
		{
			if (letter[i]>1)
				number/=factorial(letter[i]);
		}

		printf("Data set %d: %llu\n",j,number);
	}
	return (0);
}
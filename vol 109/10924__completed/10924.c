#include <stdio.h>

int main()
{
	int isprime[1600],i,j,number;

	char word[30];
	for (i=0;i<1600;++i)
		isprime[i]=1;

	isprime[0]=0;
	isprime[1]=1;
	for (i=2;i<=40;++i)
		if (isprime[i])
			for (j=i*2;j<1600;j+=i)
				isprime[j]=0;

	while (scanf("%s",word)==1)
	{
		number=0;
		for (i=0;word[i]!='\0';++i)
		{
			if (word[i]>='a')
				number+=word[i]-'a'+1;
			else
				number+=word[i]-'A'+27;
		}
		if (isprime[number])
			printf("It is a prime word.\n");
		else
			printf("It is not a prime word.\n");
	}
	return (0);
}
#include <stdio.h>

int CheatCheck(int number[11])
{
	int i;
	for (i=1;i<11;++i)
		if (number[i]==1)
			return (0);			
	return (1);
}

int main()
{
	int number[11],num,i,cheat=0;
	char guess[11];
	number[0]=0;

	for (i=1;i<11;++i)
		number[i]=1;
	while(1)
	{
		scanf("%d",&num);
		if (num==0)
			break;
		getchar();
		gets(guess);
		if (guess[4]=='t')
		{

			if (!cheat && number[num])
				printf("Stan may be honest\n");
			else 
				printf("Stan is dishonest\n");

			for (i=1;i<11;++i)
				number[i]=1;
			
			cheat=0;
			continue;
		}
		else if (!cheat && guess[4]=='h')
		{
			for (i=num;i<11;++i)
				number[i]=0;
		}
		else if (!cheat && guess[4]=='l')
		{
			for (i=num;i>0;--i)
				number[i]=0;
		}
		if (!cheat)
			cheat=CheatCheck(number);
	}
	return (0);
}
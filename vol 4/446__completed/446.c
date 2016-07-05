#include <stdio.h>

int main()
{
	int number1,number2,test,temp,i;
	char sign;

	scanf("%d",&test);

	while (test--)
	{
		scanf("%x %c %x",&number1,&sign,&number2);
			
		temp=1<<12;
		i=13;
		while(i--)
		{
			printf("%c",(temp & number1)?'1':'0');
			temp>>=1;
		}
		printf(" %c ",sign);
		temp=1<<12;
		i=13;
		while(i--)
		{
			printf("%c",(temp & number2)?'1':'0');
			temp>>=1;
		}
		if (sign=='+')
			printf(" = %d\n",number1+number2);
		else
			printf(" = %d\n",number1-number2);
	}
	return 0;
}
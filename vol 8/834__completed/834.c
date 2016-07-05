#include <stdio.h>

int main()
{

	unsigned long long int number1,number2,temp;
	int flag;

	while (scanf("%llu %llu",&number1,&number2)!=EOF)
	{
		flag=0;
		printf("[%llu;",number1/number2);

		while (1)
		{
			
			temp=number2;
			number2=number1%number2;
			number1=temp;
			if (number2==0)
			{
				printf("]\n");
				break;
			}
			if (flag)
				printf(",");

			
			printf("%llu",number1/number2);
			flag=1;
			
		}
	}
	return (0);
}
#include <stdio.h>

int main()
{
	long number1,number2;
	int test;

	scanf("%d",&test);

	while (test--)
	{
		scanf("%ld %ld",&number1,&number2);

		if (number1>number2)
			printf(">\n");
		else if (number1<number2)
			printf("<\n");
		else
			printf("=\n");
	}
	return (0);

}
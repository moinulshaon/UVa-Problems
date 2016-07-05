#include <stdio.h>


int main()
{

	long input,a;
	int test,var,temp;

	scanf("%d",&test);

	while (test--)
	{
		scanf("%ld",&input);

		if (!input)
		{
			printf("3\n\n");
			continue;
		}
		if (input<0)
			input=-input;
		
		for (a=0;(temp=a*(a+1)/2)<input;++a)
			;
		if (a%2)
			var=2;
		else
			var=1;

		if ((temp-input)%2==0)
			printf("%d\n",a);
		else
			printf("%d\n",a+var);

		if (test)
			printf("\n");


	}
	return 0;
}



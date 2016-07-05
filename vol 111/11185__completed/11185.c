#include <stdio.h>

int main()
{
	long number10,i;
	char number3[1000];

	while (1)
	{
		scanf("%ld",&number10);

		if (number10<0)
			break;
		for (i=0;;++i)
		{
			number3[i]=number10%3+'0';
			number10/=3;
			if (number10<=0)
				break;
		}

		for(;i>=0;--i)
			printf("%c",number3[i]);
		printf("\n");

	}
	return (0);

}
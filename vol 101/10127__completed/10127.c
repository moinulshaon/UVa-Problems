#include <stdio.h>

int main()
{
	int input,one,number;

	while (scanf("%d",&input)!=EOF)
	{
		one=number=1;
		while (number)
		{
			if (number<input)
			{
				number=number*10+1;
				++one;
			}

			number=number%input;
		}
		printf("%d\n",one);
	}
	return (0);
}
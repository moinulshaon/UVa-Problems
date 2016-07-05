#include <stdio.h>

int main()
{
	char word[35];
	int i;

	while (scanf("%s",word)==1)
	{
		for (i=0;word[i]!='\0';++i)
		{
			if (word[i]>='W')
				printf("9");
			else if (word[i]>='T')
				printf("8");
			else if (word[i]>='P')
				printf("7");
			else if (word[i]>='M')
				printf("6");
			else if (word[i]>='J')
				printf("5");
			else if (word[i]>='G')
				printf("4");
			else if (word[i]>='D')
				printf("3");
			else if (word[i]>='A')
				printf("2");
			else 
				printf("%c",word[i]);
		}

		printf("\n");
	}

	return (0);
}
#include <stdio.h>

int main()
{
	char c;
	while ((c=getchar())!=EOF)
	{
		if (c=='\n')
		{
			printf("%c",c);
			continue;
		}
		printf("%c",c-7);

	}
	return (0);
}
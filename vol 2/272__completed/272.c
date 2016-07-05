#include <stdio.h>

int main()
{
	char c;
	int count=0;
	while ((c=getchar())!=EOF)
	{
		if (c=='"')
		{
			if (count%2==0)
			{
				printf("``");
				++count;
			}
			else
			{
				printf("''");
				++count;
			}
		}
		else 
			printf("%c",c);
	}
	return (0);
}
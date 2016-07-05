#include <stdio.h>

int main()
{
	char c;
	int limit,i;

	while ((c=getchar())!=EOF)
	{
		limit=0;
		
		if (c=='!'||c=='\n')
		{
			printf("\n");
			continue;
		}
		else if (c>='0' && c<='9')
			limit=c-'0';
		
		while (1)
		{	
			c=getchar();
			if (c>='0' && c<='9')
			{
				limit+=c-'0';
				continue;
			}
			else
				break;
		}
		for (i=0;i<limit;++i)
		{
			if (c=='b')
			{
				printf(" ");
				continue;
			}
			printf("%c",c);
		}
	}
	return (0);
}
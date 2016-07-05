#include <stdio.h>


int main()
{
	char c[10000];
	int i,flag;
	while (1)
	{
		flag=0;
		for (i=0;;++i)
		{
			c[i]=getchar();
			if (c[i]==' ')
				break;
			else if (c[i]=='\n')
			{
				flag=1;
				break;
			}
			else if (c[i]==EOF)
				break;
		}
		if (c[i]==EOF)
			break;
		--i;
		while (i>=0)
		{
			printf("%c",c[i]);
			--i;
		}
		if (flag==1)
			printf("\n");
		else
			printf(" ");


	}
	return (0);
}
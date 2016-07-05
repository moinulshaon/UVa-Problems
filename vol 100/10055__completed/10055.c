#include <stdio.h>

int main()
{
	unsigned long int x,y;
	while (scanf("%lu %lu",&x,&y)!=EOF)
	{
		if (y>x)
			printf("%lu\n",y-x);
		else 
			printf("%lu\n",x-y);
	}
	return (0);
}
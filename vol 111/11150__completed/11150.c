#include <stdio.h>

int main()
{
	int bottle,result;
	while (scanf("%d",&bottle)==1)
	{
		result=bottle;
		while (bottle>=3)
		{
			result+=bottle/3;
			bottle=bottle%3+bottle/3;
		}
		if (bottle==2)
			++result;
		printf("%d\n",result);
	}
	return (0);
}
#include <stdio.h>

int main()
{
	int bottle,result;
	while (1)
	{
		scanf("%d",&bottle);
		if (!bottle)return 0;
		
		result=0;
		while (bottle>=3)
		{
			result+=bottle/3;
			bottle=bottle%3+bottle/3;
		}
		if (bottle==2)
			++result;
		printf("%d\n",result);
	}

}
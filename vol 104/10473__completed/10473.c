#include <stdio.h>

int main()
{
	int number,flag;

	while (1)
	{
		flag=0;
		flag=scanf(" 0x%x",&number);
		if (flag!=1)
			scanf("%d",&number);
		if (number<0)
			return (0);
		if (flag)
			printf("%d\n",number);
		else
			printf("0x%X\n",number);
	}
}
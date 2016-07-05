#include <stdio.h>
#include <stdlib.h>
int main()
{
	int num1,num2,result,count=0;
	char sign,temp;

	while (scanf("%d%c%d=",&num1,&sign,&num2)==3)
	{
		if (scanf("?%c",&temp))
			if (temp=='\n')
				continue;
		scanf("%d",&result);
		getchar();
		if (sign=='+')
		{
			if (num1+num2==result)
				++count;
		}
		else if (num1-num2==result)
			++count;
	}
	printf("%d\n",count);
	return 0;

}
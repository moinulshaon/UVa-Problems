#include <stdio.h>

int main()
{
	unsigned long long x,y,flag,count;
	while (1)
	{
		count=0;
		flag=0;
		scanf("%llu %llu",&x,&y);
		if (x==0 && y==0)
			break;
		while (x!=0 || y!=0)
		{
			if (x%10+y%10+flag>9)
			{
				++count;
				flag=1;
			}
			else
				flag=0;
			x/=10;
			y/=10;
		}
		if (count==0)
			printf("No carry operation.\n");
		else if (count==1)
			printf("1 carry operation.\n");
		else 
			printf("%llu carry operations.\n",count);
	}
	return (0);
}
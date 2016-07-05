#include <stdio.h>

int f(int number)
{
	int result=0,temp;
	while (number!=0)
	{
		temp=number%10;
		result+=temp*temp;
		number/=10;
	}
	return result;
}


int main()
{
	int number,i,j,temp[100000],test,flag,now,breakCondition;

	scanf("%d",&test);
	for (i=1;i<=test;++i)
	{
		scanf("%d",&number);
		temp[0]=f(number);
		now=0;
		flag=breakCondition=0;
		while (1)
		{
			for (j=0;j<now;++j)
			{
				if (temp[j]==temp[now])
					breakCondition=1;
			}
			if (breakCondition)
				break;
			if (temp[now]==1)
			{
				flag=1;
				break;
			}
			temp[now+1]=f(temp[now]);
			++now;
		}
		if (flag)
			printf("Case #%d: %d is a Happy number.\n",i,number);
		else
			printf("Case #%d: %d is an Unhappy number.\n",i,number);
	}
	return 0;
}
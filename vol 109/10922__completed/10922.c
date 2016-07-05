#include <stdio.h>
#include <string.h>

int f(int number)
{
	int result=0;
	while (number!=0)
	{
		result+=number%10;
		number/=10;
	}
	return result;
}

int main()
{
	char number[1100];
	int i,temp,degree;
	
	while (scanf("%s",number))
	{
		if (strcmp(number,"0")==0)
			return 0;
		temp=0;
		for (i=0;number[i]!='\0';++i)
			temp+=number[i]-'0';
		if (temp%9)
		{
			printf("%s is not a multiple of 9.\n",number);
		}
		else 
		{
			degree=1;
			while (temp>9)
			{
				temp=f(temp);
				++degree;
			}
			printf("%s is a multiple of 9 and has 9-degree %d.\n",number,degree);
		}
	}
}
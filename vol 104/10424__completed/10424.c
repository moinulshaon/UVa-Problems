#include <stdio.h>
#include <ctype.h>

int main()
{
	char name1[30],name2[30];
	int value1,value2,i,temp;
	double result;

	while(gets(name1))
	{
		gets(name2);
		value1=0;

		for (i=0;i<name1[i]!='\0';++i)
		{
			if (isalpha(name1[i]))
				value1+=tolower(name1[i])-'a'+1;
		}
		while (value1>9)
		{
			temp=0;
			while (value1!=0)
			{
				temp+=value1%10;
				value1/=10;
			}
			value1=temp;
		}

		value2=0;
		for (i=0;i<name2[i]!='\0';++i)
		{
			if (isalpha(name2[i]))
				value2+=tolower(name2[i])-'a'+1;
		}
		while (value2>9)
		{
			temp=0;
			while (value2!=0)
			{
				temp+=value2%10;
				value2/=10;
			}
			value2=temp;
		}
		result=(double)value1/value2;
		if (value1<=value2)
			printf("%.2lf %%\n",result*100);
		else 
			printf("%.2lf %%\n",1/result*100);

	}
	return 0;
}
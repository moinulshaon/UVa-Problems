#include <stdio.h>
#include <string.h>

int main()
{
	char number[1005];
	int i,result,len,flag;

	while (1)
	{
		scanf("%s",number);
		if (strcmp(number,"0")==0)
			break;
		len=strlen(number);

		flag=result=0;
		for (i=0;i<len;++i)
		{
			if (!flag && number[i]=='0')
				continue;
			else
				++flag;
			if (flag%2)
				result+=number[i]-'0';
			else
				result-=number[i]-'0';
		}
		if (result%11==0)
			printf("%s is a multiple of 11.\n",number);
		else
			printf("%s is not a multiple of 11.\n",number);
	}
	return (0);
}
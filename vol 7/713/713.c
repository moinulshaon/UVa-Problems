#include <stdio.h>
#include <string.h>

int take (char number[])
{
	int i=0,flag;

	for (i=0;;)
	{
		scanf("% c",&number[i]);
		printf("%c",number[i]);
		if (number[i]==' '||number[i]=='\n')
		{
			number[i]='\0';
			return 0;
		}
		++i;
	}
}


int main()
{
	char number1[205],number2[205],result[205];

	int n,i,len1,len2,lenmax,lenmin,lenr;

	scanf("%d",&n);

	while (n--)
	{
		for (i=0;i<205;++i)
			result[i]=number1[i]=number2[i]='\0';
		take(number1);
		take(number2);
		printf("%s %s\n",number1,number2);
		
		len1=strlen(number1);
		len2=strlen(number2);
		lenmin=(len1<len2)?len1:len2;
		lenmax=(len1>len2)?len1:len2;
		for (i=0;i<lenmin;++i)
		{
			result[i]+=number1[i]+number2[i]-'0';
			if (result[i]>'9')
			{
				result[i]-=10;
				result[i+1]+=1;
			}
		}
		printf("%s\n",result);
		if (lenmax!=lenmin)
			for (i=lenmin;i<lenmax;++i)
				result[i]+=number1[i]+number2[i];
		lenr=strlen(result);
		if (lenr>len1 && lenr>len2)
			result[lenr-1]+='0';

		printf("%s\n",result);

	}
}
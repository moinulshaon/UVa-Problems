#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
	char digit[32];
	unsigned int number,i,len;

	while (1)
	{
		number=0;
		scanf("%s",digit);
		if (strcmp(digit,"0")==0)
			break;
		len=strlen(digit);

		for (i=0;i<len;++i)
		{
			if (digit[i]=='0')
				continue;
			number+=(unsigned)(digit[i]-'0')*(pow(2,len-i)-1);
		}

		printf("%u\n",number);
	}
	return (0);
}
#include <stdio.h>
#include <string.h>

int main()
{
	char arr[101];
	int i,c;

	while (gets(arr))
	{
		if (strcmp(arr,"0")==0)
			return 0;

		i=0;
		c=arr[i]-'0';

		while (arr[++i])
			c=(c*10+(arr[i]-'0'))%17;
		if (c)
			printf("0\n");
		else
			printf("1\n");
	}
	return 0;
}
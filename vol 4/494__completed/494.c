#include <stdio.h>

int main()
{
	int count=0,flag=1;
	char c;
	while ((c=getchar())!=EOF)
	{
		
		
		if (c=='\n')
		{
			printf("%d\n",count);
			flag=1;
			count=0;
		}
		else if (!((c>='a'&&c<='z')||(c>='A' && c<='Z')))
		{
			flag=1;
			continue;
		}
		else if (((c>='a'&&c<='z')||(c>='A' && c<='Z')) && flag==1)
		{
			++count;
			flag=0;
		}
		


	}
	return (0);
}
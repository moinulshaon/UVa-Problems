#include <stdio.h>
#include <string.h>
#define maxchar 100000
int main()
{
	char string1[maxchar],string2[maxchar];
	int i,j,len1,len2,flag;
	
	while(scanf("%s %s",string1,string2)==2)
	{
		flag=0;
		j=0;
		len1=strlen(string1);
		len2=strlen(string2);

		for (i=0;i<len1;++i)
		{
			for (;j<len2;)
			{
				if (string1[i]==string2[j])
				{
					++flag;
					++j;
					break;
				}
				++j;
			}
		}
		if (flag==len1)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
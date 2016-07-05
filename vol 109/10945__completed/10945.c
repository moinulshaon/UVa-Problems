#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char word[50001];

	int i,j,len,boolean;

	while (1)
	{
		gets(word);
		if (strcmp(word,"DONE")==0)
			break;
		len=strlen(word);
		i=0;
		j=len;

		boolean=1;
		while (i<len)
		{
			if (word[i]==' ' || word[i]=='.' || word[i]==',' || word[i]=='!' || word[i]=='?')
			{
				++i;
				continue;
			}
			if (word[j-1]==' ' || word[j-1]=='.' || word[j-1]==',' || word[j-1]=='!' || word[j-1]=='?')
			{
				--j;
				continue;
			}
			if (toupper(word[i])!=toupper(word[j-1]))
			{
				boolean=0;
				break;
			}
			++i;
			--j;
		}

		if (boolean)
			printf("You won't be eaten!\n");
		else
			printf("Uh oh..\n");

	}
	return (0);
}
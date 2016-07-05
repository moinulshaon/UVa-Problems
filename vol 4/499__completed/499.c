#include <stdio.h>
#include <ctype.h>

int upper[26];
int lower[26];
int main()
{
	register i;
	int max;
	char c;
	

	while ((c=getchar())!=EOF)
	{
		do
		{
			if (isalpha(c))
			{
				if (islower(c))
					++lower[c-'a'];
				else
					++upper[c-'A'];
			}
		}
		while ((c=getchar())!='\n' && c!=EOF);

		max=0;
		for (i=0;i<26;++i)
			if (upper[i]>max)
				max=upper[i];

		for (i=0;i<26;++i)
			if (lower[i]>max)
				max=lower[i];
		for (i=0;i<26;++i)
			if (upper[i]==max)
				printf("%c",i+'A');
		for (i=0;i<26;++i)
			if (lower[i]==max)
				printf("%c",i+'a');
		printf(" %d\n",max);
		for (i=0;i<26;++i)
		{
			lower[i]=0;
			upper[i]=0;
		}

	}
	return 0;

}
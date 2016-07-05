#include <stdio.h>
#include <ctype.h>
int main()
{
	long int letter[26]={0};
	long int i,time,largest=0;
	char c;

	scanf("%d",&time);

	for (i=0;i<=time;)
	{
		c=toupper(getchar());
		if (c=='\n')
		{
			++i;
			continue;
		}
		if (c<'A'||c>'Z')
			continue;
		++letter[c-'A'];
		if (letter[c-'A']>largest)
			++largest;
	}

	while(largest>=1)
	{
		for (i=0;i<26;++i)
		{
			if (letter[i]==largest)
				printf("%c %d\n",i+'A',largest);
		}
		--largest;
	}
	return (0);

}
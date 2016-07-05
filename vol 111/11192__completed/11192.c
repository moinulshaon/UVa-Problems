#include <stdio.h>
#include <string.h>

int reverse(char *c,int len)
{
	int i;
	for (i=0;i<len;++i)
	{
		--c;
		printf("%c",*c);
	}
	return (0);
}


int main()
{
	int group,i,len;
	char line [105];

	while (1)
	{
		scanf("%d",&group);
		if (group==0)
			break;
		scanf("%s",line);
		len=strlen(line)/group;
		for (i=1;i<=group;++i)
			reverse(&line[i*len],len);
		printf("\n");
	}
	return (0);


}
#include <stdio.h>
#include <math.h>

int main()
{
	int line,paste,i;

	for (i=1;;++i)
	{
		scanf("%d",&line);
		if (line<0)
			break;
		paste=0;

		while (1)
		{
			if (pow(2,paste)>=line)
				break;
			++paste;
		}

		printf("Case %d: %d\n",i,paste);
	}
	return (0);
}
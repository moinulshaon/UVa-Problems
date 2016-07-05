#include <stdio.h>

int main()
{
	int test,a,k;

	char c;


	scanf("%d",&test);
	getchar();
	for (k=1;k<=test;++k)
	{
		printf("Case %d: ",k);
		while ((c=getchar())!='\n')
		{
			scanf("%d",&a);

			while (a--)
				printf("%c",c);
		}
		printf("\n");
		
	}
	return 0;
}
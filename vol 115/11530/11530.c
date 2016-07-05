#include <stdio.h>

int main()
{
	int test,count,i=1;
	char c;


	scanf("%d",&test);
	getchar();
	for (;i<=test;++i)
	{
		count=0;
		while ((c=getchar())!='\n')
		{
			if (c>='w')
				count+=c-'w'+1;
			else if (c>='t')
				count+=c-'t'+1;
			else if (c>='p')
				count+=c-'p'+1;
			else if (c>='m')
				count+=c-'m'+1;
			else if (c>='j')
				count+=c-'j'+1;
			else if (c>='g')
				count+=c-'g'+1;
			else if (c>='d')
				count+=c-'d'+1;
			else if (c>='a')
				count+=c-'a'+1;
			else if (c>=' ')
				count+=1;
		}
		printf("Case #%d: %d\n",i,count);
	}
	return (0);
}
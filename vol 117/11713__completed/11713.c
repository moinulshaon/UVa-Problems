#include <stdio.h>
#include <string.h>

int main()
{
	register i;
	char name1[25],name2[25];
	int test,yes;
	
	scanf("%d",&test);
	getchar();

	while (test--)
	{
		gets(name1);
		gets(name2);

		yes=1;
		for (i=0;name1[i];++i)
		{
			if (name1[i]=='a' || name1[i]=='e' || name1[i]=='i' || name1[i]=='o' ||name1[i]=='u')
				continue;
			else if (name1[i]!=name2[i])
			{
				yes=0;
				break;
			}
		}
		if (yes && name2[i]=='\0')
			printf("Yes\n");
		else
			printf("No\n");
			
	}
	return 0;
}
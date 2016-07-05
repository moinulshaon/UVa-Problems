#include <stdio.h>
#include <string.h>
#define size 201

int main()
{
	char s1[size],s2[size],s3[size],s4[size],s5[size],c;
	int test;

	freopen("input.txt","r",stdin);

	scanf("%d",&test);
	getchar();

	while (test--)
	{
		s1[0]=s2[0]=s3[0]=s4[0]=s5[0]='\0';
		scanf("%[^<]",s1);
		getchar();
		scanf("%[^>]",s2);
		getchar();
		scanf("%[^<]",s3);
		getchar();
		scanf("%[^>]",s4);
		getchar();
		scanf("%[^\n]",s5);
		getchar();

		printf("%s%s%s%s%s\n",s1,s2,s3,s4,s5);

		while ((c=getchar())!='.')
			putchar(c);
		
		getchar();
		getchar();

		printf("%s%s%s%s",s4,s3,s2,s5);
	}
	printf("\n");
	return 0;
}
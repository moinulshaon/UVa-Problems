#include <stdio.h>
#include <ctype.h>
int main()
{
	register i;
	int arr[26],test,max;
	char line[210];


	scanf("%d",&test);
	getchar();
	while (test--)
	{
		gets(line);
		for (i=0;i<26;++i)
			arr[i]=0;
		max=0;
		for (i=0;line[i];++i)
			if (isalpha(line[i]))
				++arr[tolower(line[i])-'a'];
		for (i=0;i<26;++i)
			if (arr[i]>max)
				max=arr[i];
		for (i=0;i<26;++i)
			if (arr[i]==max)
				printf("%c",i+'a');
		printf("\n");
	}
	return 0;
}
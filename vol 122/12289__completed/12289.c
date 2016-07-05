#include <stdio.h>
int main()
{
	char arr[10];
	int test;

	scanf("%d",&test);
	getchar();
	while (test--)
	{
		gets(arr);
		if ( (arr[0]=='o')+(arr[1]=='n')+(arr[2]=='e') >=2)
			printf("1\n");
		else if ((arr[0]=='t')+(arr[1]=='w')+(arr[2]=='o') >=2)
			printf("2\n");
		else
			printf("3\n");
	}
	return 0;
}
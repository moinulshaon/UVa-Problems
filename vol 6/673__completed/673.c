#include <stdio.h>

char c,arr[130],flag[130];
int count;

void DFS(int i)
{
	if (arr[i]=='\0' || c=='n')
		return ;
	else if (arr[i]==' ')
		DFS(i+1); 

	else if (arr[i]=='(')
	{
		flag[count++]='(';
		DFS(i+1);
	}
	else if (arr[i]=='[')
	{
		flag[count++]='[';
		DFS(i+1);
	}

	else if (arr[i]==')' && flag[count-1]=='(')
	{
		--count;
		DFS(i+1);
	}

	else if (arr[i]==']' && flag[count-1]=='[')
	{
		--count;
		DFS(i+1);
	}
	else 
		c='n';

}


int main()
{
	int test;

	scanf("%d",&test);
	getchar();

	while (test--)
	{
		c='y';
		count=0;
		gets(arr);

		DFS(0);

		if (c=='y' && count==0)
			printf("Yes\n");
		else
			printf("No\n");

	}
	return 0;


}
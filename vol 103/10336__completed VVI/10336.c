#include <stdio.h>

char arr[100][100];
char alp[26];
char ch;


void connected(int a,int b)
{
	arr[a][b]=0;
	if (arr[a][b+1]==ch)
		connected(a,b+1);
	if (arr[a][b-1]==ch)
		connected(a,b-1);
	if (arr[a+1][b]==ch)
		connected(a+1,b);
	if (arr[a-1][b]==ch)
		connected(a-1,b);
	
}

int main()
{
	int test,i,j,k,max;
	int r,c;


	scanf("%d",&test);
	getchar();

	for (k=1;k<=test;++k)
	{

		for (i=0;i<26;++i)
			alp[i]=0;
		max=0;

		scanf("%d %d",&r,&c);
		getchar();

		for (i=1;i<=r;++i)
		{
			for (j=1;j<=c;++j)
				scanf("%c",&arr[i][j]);
			getchar();
		}

		for (i=1;i<=r;++i)
		{
			for (j=1;j<=c;++j)
			{
				if (arr[i][j])
				{
					ch=arr[i][j];
					++alp[arr[i][j]-'a'];
					connected(i,j);
				}
			}
		}

		for (i=0;i<26;++i)
			if (alp[i]>max)
				max=alp[i];



		printf("World #%d\n",k);
		while (max)
		{
			for (i=0;i<26;++i)
			{
				if (alp[i]==max)
					printf("%c: %d\n",i+'a',alp[i]);
					
			}
			--max;
		}


	}
	return 0;

}
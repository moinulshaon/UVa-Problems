#include <stdio.h>
#define size 101
char arr[size][size];
char vis[size];
int vertex,count;

void DFS(int i)
{
	int k;
	for (k=1;k<=vertex;++k)
		if (arr[i][k] && !vis[k])
		{
			vis[k]=1;
			++count;
			DFS(k);
		}
}


int main()
{

	int row,temp,i,j,test,input;



	while (1)
	{
		scanf("%d",&vertex);
		if (!vertex)
			return 0;

		for (i=0;i<=vertex;++i)
			for (j=0;j<=vertex;++j)
				arr[i][j]=0;
		

		while (1)
		{
			scanf("%d",&row);
			if (!row)
				break;


			while (1)
			{
				scanf("%d",&temp);
				if (!temp)
					break;
				arr[row][temp]=1;
			}
		}


		scanf("%d",&test);
		for (i=0;i<test;++i)
		{
			scanf("%d",&input);
			count=0;
			for (j=0;j<=vertex;++j)
				vis[j]=0;
			DFS(input);
			printf("%d",vertex-count);
			for (j=1;j<=vertex;++j)
				if (!vis[j])
					printf(" %d",j);
			printf("\n");


		}

		

	}

	
}
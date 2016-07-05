#include <stdio.h>


char arr1[105][105];
char arr2[105][105];
int main()
{
	register i,j;
	int k,row,column;


	for (k=0;;++k)
	{
		scanf("%d %d",&row,&column);
		getchar();
		if (!row && !column)
			return 0;
		if (k)
			printf("\n");
		for (i=0;i<=row+1;++i)
			for (j=0;j<=column+1;++j)
				arr2[i][j]=0;

		for (i=1;i<=row;++i)
		{
			for (j=1;j<=column;++j)
				scanf("%c",&arr1[i][j]);
			getchar();
		}
		for (i=1;i<=row;++i)
		{
			for (j=1;j<=column;++j)
			{
				if (arr1[i][j]=='*')
				{
					arr2[i-1][j-1]+=1;
					arr2[i-1][j]+=1;
					arr2[i-1][j+1]+=1;
					arr2[i][j-1]+=1;
					arr2[i][j+1]+=1;
					arr2[i+1][j-1]+=1;
					arr2[i+1][j]+=1;
					arr2[i+1][j+1]+=1;
				}
			}
		}
		printf("Field #%d:\n",k+1);
		for (i=1;i<=row;++i)
		{
			for (j=1;j<=column;++j)
			{
				if (arr1[i][j]=='*')
					printf("*");
				else
					printf("%d",arr2[i][j]);
			}
			printf("\n");
		}
	}
}
#include <stdio.h>
#define size 55


char arr[size][size];

int result;

void process(int i,int j)
{
	arr[i][j]='#';

	if (arr[i][j+1]=='T' || arr[i+1][j]=='T' || arr[i][j-1]=='T' || arr[i-1][j]=='T')
		return ;

	if (arr[i][j+1]!='#')
	{
		if (arr[i][j+1]=='G')
			++result;
		process(i,j+1);
	}

	if (arr[i+1][j]!='#')
	{
		if (arr[i+1][j]=='G')
			++result;
		process(i+1,j);
	}

	if (arr[i][j-1]!='#')
	{
		if (arr[i][j-1]=='G')
			++result;
		process(i,j-1);
	}
	if (arr[i-1][j]!='#')
	{
		if (arr[i-1][j]=='G')
			++result;
		process(i-1,j);
	}
}


int main()
{
	int m,n,i,j,prow,pcolumn;;


	while (scanf("%d %d",&n,&m)==2)
	{
		getchar();

		for (i=1;i<=m;++i)
		{
			for (j=1;j<=n;++j)
			{
				scanf("%c",&arr[i][j]);
				if (arr[i][j]=='P')
				{
					prow=i;
					pcolumn=j;
				}
			}
			getchar();
		}

		/*for (i=1;i<=m;++i)
		{
			for (j=1;j<=n;++j)
			{
				printf("%c",arr[i][j]);
			}
			printf("\n");
		}*/

		result=0;

		process(prow,pcolumn);

		printf("%d\n",result);

	}
	return 0;

}
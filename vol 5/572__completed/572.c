#include <stdio.h>
#include <string.h>

#define maxm 110

char arr[maxm][maxm];

int process(int i,int j)
{
	int result=1;
	
	arr[i][j]='0';

	if (arr[i][j+1]=='@')
		result+=process(i,j+1);
	

	
	if (arr[i+1][j+1]=='@')
		result+=process(i+1,j+1);
	

	if (arr[i+1][j]=='@')
		result+=process(i+1,j);
	
	
	if (arr[i+1][j-1]=='@')
		result+=process(i+1,j-1);
	

	if (arr[i][j-1]=='@')
		result+=process(i,j-1);
	

	if (arr[i-1][j-1]=='@')
		result+=process(i-1,j-1);
	
	
	if (arr[i-1][j]=='@')
		result+=process(i-1,j);
	
	if (arr[i-1][j+1]=='@')
		result+=process(i-1,j+1);
	
	
	return result;
	
}

int main()
{
	int i,j,result,m,n;


	
	while (1)
	{

		scanf("%d %d",&m,&n);
		getchar();
		if (!m)
			return 0;
		for (i=1;i<=m;++i)
		{
			for (j=1;j<=n;++j)
				scanf("%c",&arr[i][j]);
			getchar();
		}
		result=0;

		for (i=1;i<=m;++i)
		{
			for (j=1;j<=n;++j)
			{
				if (arr[i][j]=='@')
				{

					process(i,j);

					++result;
					
					
				}
			}
			
		}
		

		printf("%d\n",result);

	}
	return 0;

}
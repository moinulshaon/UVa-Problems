#include <stdio.h>
#define size 210

char arr[size][size];
char white;

int board;


void process(int i,int j)
{

	if (j==board)
	{
		white=1;
		return ;
	}

	arr[i][j]='b';

	
	if (white)
		return ;

	if (!white && arr[i-1][j-1]=='w')
		process(i-1,j-1);
	if (!white && arr[i-1][j]=='w')
		process(i-1,j);
	if (!white && arr[i][j-1]=='w')
		process(i,j-1);
	if (!white && arr[i][j+1]=='w')
		process(i,j+1);
	if (!white && arr[i+1][j]=='w')
		process(i+1,j);
	if (!white && arr[i+1][j+1]=='w')
		process(i+1,j+1);
	return ;


}




int main()
{

	int i,k;

	freopen("input.txt","r",stdin);

	for (k=1;scanf("%d",&board)==1;++k)
	{
		

		if (!board)
			return 0;

		

		for (i=1;i<=board;++i)
		{
		
			scanf("%s",&arr[i][1]);
	
		}


		white=0;

		for (i=1;i<=board+1;++i)
		{
			arr[i][board+1]=0;
			arr[board+1][i]=0;
		}

	
		

		for (i=1;i<=board && !white;++i)
		{
		
			if (arr[i][1]=='w')
				process(i,1);



		}	

		
		
		if (white)
			printf("%d W\n",k);
		else
			printf("%d B\n",k);

		

	}
	return 0;
	
}


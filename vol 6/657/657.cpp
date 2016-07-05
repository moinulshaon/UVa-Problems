#include <stdio.h>
#include <algorithm>
#define size 55

int result[5000],num,row,col;

char arr[size][size];

using namespace std;

void process(int i,int j);

void DFS(int i,int j)
{
	if ( i<0 || j<0 || i>=row || j>=col )return ;

	arr[i][j]='*';

	if (arr[i][j+1]=='X')
		DFS(i,j+1);
	if (arr[i][j-1]=='X')
		DFS(i,j-1);
	if (arr[i+1][j]=='X')
		DFS(i+1,j);
	if (arr[i-1][j]=='X')
		DFS(i-1,j);

/*	if (arr[i][j+1]=='*')
		process(i,j+1);
	
	if (arr[i][j-1]=='*')
		process(i,j-1);
	
	if (arr[i-1][j]=='*')
		process(i-1,j);
	
	if (arr[i+1][j]=='*')
		process(i+1,j);*/


}



void process(int i,int j)
{
	if ( i<0 || j<0 || i>=row || j>=col )return ;
	
	
	if (arr[i][j]=='X')
	{
		++result[num];
		DFS(i,j);
	}

	arr[i][j]='.';


	if (arr[i][j+1]=='*')
		process(i,j+1);
	
	if (arr[i][j-1]=='*')
		process(i,j-1);
	
	if (arr[i-1][j]=='*')
		process(i-1,j);
	
	if (arr[i+1][j]=='*')
		process(i+1,j);


	
		

}


int main()
{
	int i,j,k;


	freopen("input.txt","r",stdin);


	for (k=0;scanf("%d %d",&col,&row)==2;++k)
	{
		
		getchar();


		if (!row && !col)
			return 0;



		num=0;
		

		for (i=0;i<row;++i)
			scanf("%s",arr[i]);

		for (i=0;i<5000;++i)
			result[i]=0;
		

		for (i=0;i<row;++i)
		{
			for (j=0;j<col;++j)
			{
				
				if (arr[i][j]!='.')
				{
					process(i,j);
					++num;
				}
				/*else if (arr[i][j]=='X')
				{
					++result[num];
					DFS(i,j);
					++num;
				}*/
			}
		}


		sort(result,result+num);

		printf("Throw %d\n",k+1);
		if (num)
			printf("%d",result[0]);
		for (i=1;i<num;++i)
			printf(" %d",result[i]);
		printf("\n\n");


	}
	return 0;


	
	
}
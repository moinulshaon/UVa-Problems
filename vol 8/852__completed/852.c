#include <stdio.h>


char arr[10][10];
char vis[10][10],flag;

int postr[4]={0,1,0,-1};
int postc[4]={1,0,-1,0};
int count;


void DFS(int i,int j)
{
	int k;
	if (i<0 || j<0 || i>8 || j>8 || vis[i][j])return ;

	vis[i][j]=1;

	
	for (k=0;k<5;++k)
	{
		if (!vis[i+postr[k]][j+postc[k]] && arr[i+postr[k]][j+postc[k]]=='.')
		{
			++count;
			DFS(i+postr[k],j+postc[k]);
		}
		if (flag==0 && arr[i+postr[k]][j+postc[k]]!='.')
		{
			flag=arr[i+postr[k]][j+postc[k]];
		}
		else if (flag=='X' && arr[i+postr[k]][j+postc[k]]=='O')
		{
			flag=1;
		}
		else if (flag=='O' && arr[i+postr[k]][j+postc[k]]=='X')
		{
			flag=1;
		}
	}

}



int main()
{

	int test,i,j,black,white;


	freopen("input.txt","r",stdin);

	scanf("%d",&test);

	getchar();

	while (test--)
	{
		for (i=0;i<9;++i)
			gets(arr[i]);

		for (i=0;i<9;++i)
			for (j=0;j<9;++j)
				vis[i][j]=0;

		black=white=0;
		for (i=0;i<9;++i)
		{
			for (j=0;j<9;++j)
			{
				count=flag=0;
				if (arr[i][j]=='.' && !vis[i][j])
				{
					++count;
					DFS(i,j);
					
				}
				if (flag=='X')
					black+=count;
				else if (flag=='O')
					white+=count;

			}
		}

		for (i=0;i<9;++i)
		{
			for (j=0;j<9;++j)
			{
				if (arr[i][j]=='X')
					++black;
				else if (arr[i][j]=='O')
					++white;
			}

		}

		printf("Black %d White %d\n",black,white);

		
	}
	return 0;


	
}
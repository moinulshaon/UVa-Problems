#include <stdio.h>

int main()
{
	int i,j,x,tower1[101],tower2[101],matrix[102][102],n1,n2;

	for (x=1;;++x)
	{
		scanf("%d %d",&n1,&n2);
		if (n1==0 && n2==0)
			break;
		for (i=0;i<n1;++i)
		{
			scanf("%d",&tower1[i]);
			matrix[i+1][0]=0;
		}

		for (i=0;i<n2;++i)
		{
			scanf("%d",&tower2[i]);
			matrix[0][i+1]=0;
		}
		matrix[0][0]=0;

		for (i=1;i<=n1;++i)
		{
			for (j=1;j<=n2;++j)
			{
				if (tower1[i-1]!=tower2[j-1])
					matrix[i][j]=(matrix[i-1][j]>matrix[i][j-1])?matrix[i-1][j]:matrix[i][j-1];
				else
					matrix[i][j]=matrix[i-1][j-1]+1;
			}
		}

		printf("Twin Towers #%d\nNumber of Tiles : %d\n\n",x,matrix[n1][n2]);

	}
	return (0);
}
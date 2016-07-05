#include <stdio.h>

int main()
{
	int corruptx,corrupty,sum1,sum2,mat[100][100],n,i,j,breakcon;

	while (1)
	{
		scanf("%d",&n);
		if (n==0)
			break;
		corruptx=corrupty=-1;
		breakcon=0;
		for (i=0;i<n;++i)
			for (j=0;j<n;++j)
				scanf("%d",&mat[i][j]);
		for (i=0;i<n;++i)
		{
			sum1=sum2=0;
			for (j=0;j<n;++j)
			{
				sum1+=mat[i][j];
				sum2+=mat[j][i];
			}
			if (sum1%2!=0)
			{
				if (corruptx!=-1)
				{
					breakcon=1;
					break;
				}
				corruptx=i;
			}
			if (sum2%2!=0)
			{
				if (corrupty!=-1)
				{
					breakcon=1;
					break;
				}
				corrupty=i;
			}
		}

		if (breakcon)
			printf("Corrupt\n");
		else if (corruptx!=-1 && corrupty!=-1)
			printf("Change bit (%d,%d)\n",corruptx+1,corrupty+1);
		else
			printf("OK\n");
	}
	return (0);
	
}
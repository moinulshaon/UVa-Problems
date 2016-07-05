#include <stdio.h>

int main()
{
	int B[3],G[3],C[3],i,k,j,brown=0,green=0,clear=0,sum,mini=99999;
	while (scanf("%d %d %d %d %d %d %d %d %d",&B[0],&G[0],&C[0],&B[1],&G[1],
		&C[1],&B[2],&G[2],&C[2])==9)
	{
		for (i=0;i<3;++i)
		{	
			for (k=0;k<3;++k)
			{	
				for (j=0;j<3;++j)
				{
					sum=B[i]+C[k]+G[j];
					
					if (sum<mini && i!=j && j!=k && k!=i)
					{
						mini=sum;
						brown=i;
						clear=k;
						green=j;
					}
					printf("%d %d %d %d\n",mini,brown,clear,green);
				}
			}
		}
		
	}
	return 0;

}
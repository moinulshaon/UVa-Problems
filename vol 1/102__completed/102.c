#include <stdio.h>
#include <math.h>
int main()
{
	int can1[3],can2[3],can3[3],a[3],b[3],c[3],i,j,k,B,G,C,temp;
	while (scanf("%d %d %d %d %d %d %d %d %d",&can1[0],&can1[1],&can1[2],&can2[0],&can2[1],
		&can2[2],&can3[0],&can3[1],&can3[2])==9)
	{
		unsigned int sum=0,smallest=pow(2,31);
		for (i=0;i<3;++i)
		{
			a[i]=can2[i]+can3[i];
			b[i]=can1[i]+can3[i];
			c[i]=can1[i]+can2[i];
		}
		temp=a[1];
		a[1]=b[0];
		b[0]=temp;
		temp=a[2];
		a[2]=c[0];
		c[0]=temp;
		temp=b[2];
		b[2]=c[1];
		c[1]=temp;

		
		for (i=0;i<3;++i)
		{
			for(j=0;j<3;++j)
			{	
				for(k=0;k<3;++k)
				{
					sum=a[i]+c[j]+b[k];
					if (smallest>sum && i!=j && j!=k && k!=i)
					{
						smallest=sum;
						B=i+1;
						C=j+1;
						G=k+1;
					}
					
				}
			}
		}
		if (B==1)
		{
			if (G==2)
				printf("BGC");
			else
				printf("BCG");
			
		}
		else if (G==1)
		{
			if (B==2)
				printf("GBC");
			else
				printf("GCB");
			
		}
		else if (C==1)
		{
			if (B==2)
				printf("CBG");
			else 
				printf("CGB");
		}
		printf(" %d\n",smallest);
	}
	return 0;
}
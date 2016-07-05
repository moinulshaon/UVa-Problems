#include <stdio.h>
#define min(a,b) ((a)<(b))?(a):(b)
#define INF 1000000


int d[101][101];


int main()
{
	int m,test,i,j,k,n,cases,a,b,max,temp;



	scanf("%d",&test);

	for (m=1;m<=test;++m)
	{

		

		scanf("%d %d",&n,&cases);


		for (i=0;i<n;++i)
			for (j=0;j<n;++j)
				d[i][j]=INF;

		for (i=0;i<n;++i)
			d[i][i]=0;

		while (cases--)
		{
			scanf("%d %d",&a,&b);
			d[a][b]=d[b][a]=1;
		}

		
        for ( k = 0; k < n; k++ ) 
            for ( i = 0; i < n; i++ ) 
                for ( j = 0; j < n; j++ )
					d [i] [j] = min (d [i] [j],  d [i] [k]+ d [k] [j]); 
		
        

		scanf("%d %d",&a,&b);

		max=0;
		for (i=0;i<n;++i)
		{
			temp=d[a][i]+d[i][b];
			if (temp>max)
				max=temp;
			
		}


		printf("Case %d: %d\n",m,max);



	}
	return 0;
	
}
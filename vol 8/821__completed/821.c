#include <stdio.h>
#include <math.h>
#define min(a,b) ((a)<(b))?(a):(b)
#define size 101
#define INF 1000000

int d[size][size];
int fallen[size];


int main ()
{
	
    int cases = 0;
	int i,j,k,count,a,b;
	
	double sum;

   

    while (1)
    {
		scanf("%d %d",&a,&b);
		if (!a && !b)return 0;
		
		for (i=0;i<size;++i)
			fallen[i]=0;
		for (i=0;i<size;++i)
			for(j=0;j<size;++j)
				d[i][j]=INF;
		
		d[a][b]=1;
		fallen[a]=fallen[b]=1;
		
		sum=count=0;
		
		while (1)
		{
			scanf("%d %d",&a,&b);
			if (!a && !b) break;
			d[a][b]=1;	
			fallen[a]=fallen[b]=1;
		}
		for ( k = 0; k < size; k++ ) {
            for ( i = 0; i < size; i++ ) {
                for ( j = 0; j < size; j++ )
                    d [i] [j] = min (d [i] [j],d [i] [k]+ d [k] [j]);
            }
        }
        
        for(i=0;i<size;++i)
        	d[i][i]=0;
        
        for (i=0;i<size;++i)
			for(j=0;j<size;++j)
				if (d[i][j]!=INF)sum+=d[i][j];
				
		for (i=0;i<size;++i)
			if (fallen[i])
				++count;
		count=count*(count-1);
				
		printf("Case %d: average length between pages = %.3lf clicks\n",++cases,sum/count);
		
        
			
	}

}



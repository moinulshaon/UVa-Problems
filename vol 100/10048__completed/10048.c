#include <stdio.h>
#include <math.h>
#define INF 2147480000
#define min(a,b) ((a)<(b))?(a):(b)
#define max(a,b) ((a)>(b))?(a):(b)


int d[101][101];


int main ()
{
    
	int i,j,k,c,s,q,m,f,g,dec;

	freopen("input.txt","r",stdin);
   

    for ( m=1 ;;++m )
	{
		scanf("%d %d %d",&c,&s,&q);
        

		

		if (!c && !s && !q)return 0;


		if (m!=1)printf("\n");

		for (i=1;i<=c;++i)
			for (j=1;j<=c;++j)
				d[i][j]=INF;

		while (s--)
		{
			scanf("%d %d %d",&f,&g,&dec);
			d[f][g]=d[g][f]=dec;
		}

		for (i=1;i<=c;++i)
			d[i][i]=0;





        for ( k = 1; k <= c; k++ ) 
            for ( i = 1; i <= c; i++ ) 
                for ( j = 1; j <= c; j++ )
                    d [i] [j] = min (d [i] [j], max (d [i] [k], d [k] [j]));
            
        

		printf("Case #%d\n",m);
		while (q--)
		{
			scanf("%d %d",&f,&g);
			if (d[f][g]<INF)
				printf("%d\n",d[f][g]);
			else
				printf("no path\n");
			
		}


    }

    return 0;

}

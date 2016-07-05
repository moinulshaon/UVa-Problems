#include <stdio.h>
#include <math.h>
#define min(a,b) ((a)<(b))?(a):(b)
#define max(a,b) ((a)>(b))?(a):(b)



int main ()
{
    int city,test;
    int cases = 0;
	int i,j,k,a,b,c;


    while (1 )
	{
        int x [200 + 10]={0};
        int y [200 + 10]={0};
		int d[200+10][200 + 10]={0};

		scanf("%d %d",&city,&test);

		if (!city && !test)return 0;


		for (i=0;i<city;++i)
			for (j=0;j<city;++j)
				d[i][j]=0;

        for ( i = 0; i < test; i++ )
		{
			scanf("%d %d %d",&a,&b,&c);
			d[a-1][b-1]=d[b-1][a-1]=c;
		}



        for ( k = 0; k < city; k++ ) {
            for ( i = 0; i < city; i++ ) {
                for ( j = 0; j < city; j++ )
                    d [i] [j] = max (d [i][j], min( d[i][k],d[k][j] ) );
            }
        }


		scanf("%d %d %d",&a,&b,&c);

        printf ("Scenario #%d\n", ++cases);
        printf ("Minimum Number of Trips = %d\n\n",(int)ceil( (double)c  / (d[a-1][b-1]-1) ) );

    }

    return 0;

}

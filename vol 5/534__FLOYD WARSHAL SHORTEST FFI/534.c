#include <stdio.h>
#include <math.h>
#define min(a,b) ((a)<(b))?(a):(b)
#define max(a,b) ((a)>(b))?(a):(b)


int main ()
{
    int stones;
    int cases = 0;
	int i,j,k;

   

    while ( scanf ("%d", &stones) && stones )
	{
        int x [200 + 10]={0};
        int y [200 + 10]={0};
		double d[200+10][200 + 10]={0};

        for ( i = 0; i < stones; i++ )
			scanf ("%d %d", &x [i], &y [i]);




        for ( i = 0; i < stones; i++ )
		{
            for ( j = i + 1; j < stones; j++ )
                d[i][j] = d[j][i] = sqrt (pow ( x[i] - x[j], 2) + pow ( y[i] -y[j], 2));
        }



        for ( k = 0; k < stones; k++ ) {
            for ( i = 0; i < stones; i++ ) {
                for ( j = 0; j < stones; j++ )
                    d [i] [j] = min (d [i] [j], max (d [i] [k], d [k] [j]));
            }
        }

        printf ("Scenario #%d\n", ++cases);
        printf ("Frog Distance = %.3lf\n\n", d [0] [1]);

    }

    return 0;

}

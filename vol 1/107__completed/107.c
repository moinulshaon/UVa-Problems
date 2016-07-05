#include <stdio.h>
#include <math.h>


int powerOf2 (double h)
{
    int p = 0;
    while ( 1 )
	{
        int res = (1 << p) ;
        if ( res > h )
            return p - 1;
        p++;
    }
}
int main()
{
	double h,w,n,N;
	int height,notWorking;
	int i;
	

	while (1)
	{
		scanf("%lf %lf",&h,&w);

		if (h==0 && w==0)
			return 0;
		if (h==1)
		{
			printf("0 1\n");
			continue;
		}

		if ( w == 1 )
		{
            int k=0,temp = powerOf2 (h);

            while ( h >= 1 )
            {
				k += (int)h;
                h /=2;
            }
            printf ("%d %d\n", temp , k);
            continue;
        }
		for (i=1;fabs(pow(h,1/(double)i)-pow(w,1/(double)i)-1) >0.000001;++i)
			;
		n=i;
		N=(int)(pow(w,1/n)+.5);

		notWorking=(int)(1.5+N*(pow(N,n-1)-1)/(N-1));
		height=(int)(w*(pow((N+1)/N,n+1)-1)/((N+1)/N-1)+.5);
		printf("%d %d\n",notWorking,height);
		
	}
}
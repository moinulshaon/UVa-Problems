#include <stdio.h>
#include <math.h>

int p,q,r,s,t,u;

double prv;

double F()
{
	return p*exp(-prv)+q*sin(prv)+r*cos(prv)+s*tan(prv)+t*prv*prv+u;
}

double F1()
{
	double temp=cos(prv);
	return -p*exp(-prv)+q*cos(prv)-r*sin(prv)+s/(temp*temp)+2*t*prv;
}

int main()
{
	double now,temp,x,y;


	while (scanf("%d %d %d %d %d %d",&p,&q,&r,&s,&t,&u)==6)
	{

		prv=0;
		x=F();
		prv=1;
		y=F();
		if (x > 0 && y > 0) printf("No solution\n");
		else if (x < 0 && y < 0) printf("No solution\n");
		else if ( x<.00001 && x>-.00001 ) printf("0.0000\n");
		else if ( y<.00001 && y>-.00001) printf("1.0000\n");
		else
		{
			now=temp=.5;
			while (temp>.0001)
			{
				prv=now;
				now=prv-F()/F1();
				temp=fabs(prv-now);
			
			}

	
			
			printf("%.4lf\n",now);
		}

	}
	return 0;
	
}
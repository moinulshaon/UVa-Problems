#include <cstdio>
#include <cmath>

int main()
{
    int  a,b,v,A,s,m,n;
    double vx,vy,degree,temp,pi=acos(-1);

    while (1)
    {
        scanf("%d %d %d %d %d",&a,&b,&v,&A,&s);
        if (!a && !b && !v && !A && !s) return 0;

        degree=double(A)*pi/180;

        vx=v*cos(degree);
        vy=v*sin(degree);


        temp=vy*s/2;
        /*if (temp >= double(b)/2)
        {
            ++n;
            temp-=double(b)/2;

        }
        if (temp<0)
            temp=0;*/

printf("%lf\n",temp);
        n=ceil((temp-.000001)/b);

        temp=vx*s/2;
        /*if (temp >= double(a)/2)
        {
            ++m;
            temp-=double(a)/2;

        }

        if (temp<0)
            temp=0;*/

printf("%lf\n",temp);
        m=ceil((temp-.000001)/a);

        printf("%d %d\n",m,n);


    }

}

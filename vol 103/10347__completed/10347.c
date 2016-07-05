#include <stdio.h>
#include <math.h>

int main()
{
    double a[3],result,t,p,r,s,u,v,temp;

    while (scanf("%lf %lf %lf",&a[0],&a[1],&a[2])==3)
    {
        t=pow(a[0],2);
        p=pow(a[1],2);
        r=pow(a[2],2);

        s=pow(a[0],4);
        u=pow(a[1],4);
        v=pow(a[2],4);


        temp=2*((t*p)+(t*r)+(p*r))-(s+u+v);

        if (temp<=0)
            result=-1;
        else
            result=sqrt(temp)/3;
        printf("%.3lf\n",result);
    }
    return 0;
}

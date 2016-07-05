#include<stdio.h>
#define sz 10001
struct kk {
        int x;
        int y;
}cube[sz];
int main()
{
    int i,j,k,p;
    for(i=1; i<=60; i++)
    {
        for(j=i+1; j<=60; j++)
        {
            p=(j*j*j)-(i*i*i);
            if (p<sz)
            {
                if(cube[p].x==0 && cube[p].y==0)
                {
                    cube[p].x=j;
                    cube[p].y=i;
                }
                else
                {
                    if(cube[p].y>i)
                    {
                        cube[p].x=j;
                        cube[p].y=i;
                    }
                }
            }
        }
    }
    int n;
    while(scanf("%d",&n)==1 && n!=0)
    {
         if(cube[n].x==0 && cube[n].y==0) printf("No solution\n");
         else printf("%d %d\n",cube[n].x,cube[n].y);
    }
    return 0;
}

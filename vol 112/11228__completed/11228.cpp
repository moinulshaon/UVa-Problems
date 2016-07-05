#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

struct node {
    int start;
    int end;
    double distance;
} a [1000*1000+10];

struct vertex {
    int x;
    int y;
} v [1000 + 10];

int parent[1000+10];
int size[1000+10];

bool cmp (node p, node q)
{
    if ( p.distance > q.distance )
        return false;
    return true;
}

int find(int x)
{
    if (parent[x]==x)
        return x;
    else
        return parent[x]=find(parent[x]);
}



int main ()
{

    freopen("input.txt","r",stdin);

    int test;
    scanf("%d",&test);
    for (int m=1;m<=test;++m)
    {
        int n,r;
        scanf("%d %d",&n,&r);
        for (int i=0;i<n;++i)
        {
            parent[i]=i;
            size[i]=1;
        }

        for (int i=0;i<n;++i)
            scanf("%d %d",&v[i].x,&v[i].y);

        int totaledge=0;

        for (int i=0;i<n;++i)
            for (int j=i+1;j<n;++j)
            {
                a[totaledge].start=i;
                a[totaledge].end=j;
                a[totaledge].distance=sqrt(pow((v[i].x-v[j].x),2)+pow((v[i].y-v[j].y),2));
                totaledge++;
            }
        sort(a,a+totaledge,cmp);

        int city=1,c=1;
        double rail=0,road=0;

        for ( int i = 0; i < totaledge && c <n; i++ ) {

            int tx=find(a[i].start),ty=find(a[i].end);

            if ( tx != ty )
            {
                if (size[tx]>size[ty])swap(tx,ty);
                size[ty]+=size[tx];
                parent[tx]=ty;

                c++;
                if (a[i].distance>r)
                {
                    ++city;
                    rail+=a[i].distance;
                }
                else
                    road+=a[i].distance;
            }
        }

        printf("Case #%d: %d %d %d\n",m,city,int(road+.5),int(rail+.5));

    }

    return 0;
}

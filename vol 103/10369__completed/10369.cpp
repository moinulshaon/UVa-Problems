#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

struct node {
    int start;
    int end;
    double distance;
} a [500*500+10];

struct vertex {
    int x;
    int y;
} v [500 + 10];

int parent[500+10];
int size[500+10];

bool cmp (node p, node q)
{
    if ( p.distance < q.distance )
        return true;
    return false;
}

int find(int x)
{
    if (parent[x]==x)
        return x;
    else
        return parent[x]=find(parent[x]);
}

vector <double> vec;

int main ()
{

    freopen("input.txt","r",stdin);

    int test;
    scanf("%d",&test);
    while (test--)
    {
        int n,r;
        vec.clear();
        scanf("%d %d",&r,&n);
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

        int c=1;

        for ( int i = 0; i < totaledge && c <n; i++ ) {

            int tx=find(a[i].start),ty=find(a[i].end);

            if ( tx != ty )
            {
                if (size[tx]>size[ty])swap(tx,ty);
                size[ty]+=size[tx];
                parent[tx]=ty;
                c--;
                vec.push_back(a[i].distance);
            }
        }

        printf("%.2lf\n",vec[vec.size()-r]);

    }

    return 0;
}

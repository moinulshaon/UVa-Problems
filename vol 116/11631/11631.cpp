#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

struct node {
    int start;
    int end;
    int distance;
} a [200000+10];

int parent[200000+10];
int size[200000+10];

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



int main ()
{

    freopen("input.txt","r",stdin);

    int m,n;
    while (scanf("%d %d",&m,&n)==2)
    {
        if (!m && !n)return 0;

        int cost=0;

        for (int i=0;i<n;++i)
        {
            scanf ("%d %d %d", &a [i].start, &a [i].end, &a [i].distance);
            cost+=a [i].distance;

            parent[i]=i;
            size[i]=1;
        }

        sort(a,a+n,cmp);

        int c=m-1;
        int result=0;

        for ( int i = 0; i < n && c ; i++ ) {

            int p=find(a[i].start),q=find(a[i].end);

            if ( p != q )
            {
                if (size[p]>size[q])swap(p,q);
                size[q]+=size[p];
                parent[p]=q;
                c--;
                result+=a[i].distance;
            }
        }

        printf("%d\n",cost-result);

    }

    return 0;
}

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

struct lists {
    int start;
    int end;
    int distance;
} a [25000 + 10];

int parent [1000 + 10];
int size[1000+10];
int vertex;
int edges;

bool cmp (lists p, lists q)
{
    if ( p.distance < q.distance ) return true;
    return false;
}

int parentOf (int n)
{
    if ( n == parent [n] ) return n;
    return parent [n] = parentOf (parent [n]);
}

int main ()
{

    freopen("input.txt","r",stdin);



    while ( true )
    {
        scanf("%d %d",&vertex,&edges);

        if (!vertex && !edges)return 0;

        for (int i=0;i< vertex; ++i )
        {
            parent [i] = i;
            size[i]=1;
        }


        int x,y,z,length_of_a=0;
        for ( int i = 0; i < edges; i++ )
        {
            scanf("%d %d %d",&x,&y,&z);
            a [length_of_a].start = x;
            a [length_of_a].end = y;
            a [length_of_a].distance = z;
            length_of_a++;
        }


        sort (a, a + length_of_a, cmp);

        int outputCost = 0,totalairport=0;
        vector <int> v;

        for ( int i = 0; i < length_of_a ; i++ ) {
            int p = parentOf (a [i].start);
            int q = parentOf (a [i].end);
            if ( p != q ) {
                if (size[p]>size[q])swap(p,q);
                size[q]+=size[p];
                parent [p] = q;
            }
            else
                v.push_back(a[i].distance);
        }
        if ( v.size() )
        {
            printf("%d",v[0]);
            for (int i=1;i<v.size();++i)
                printf(" %d",v[i]);
            printf("\n");
        }
        else
            printf("forest\n");

    }

	return 0;
}

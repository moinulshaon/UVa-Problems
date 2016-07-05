#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

struct lists {
    int start;
    int end;
    int distance;
} a [100000+ 10];

int parent [10000 + 10];
int size[10000+10];
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
    int test;
    scanf("%d",&test);

    for  (int m=1;m<=test;++m )
    {

        int costperairport;

        scanf("%d %d %d",&vertex,&edges,&costperairport);


        for (int i=0;i< vertex; ++i )
        {
            parent [i] = i;
            size[i]=1;
        }


        int x,y,z,length_of_a=0;
        for ( int i = 0; i < edges; i++ )
        {
            scanf("%d %d %d",&x,&y,&z);
            a [length_of_a].start = x-1;
            a [length_of_a].end = y-1;
            a [length_of_a].distance = z;
            length_of_a++;
        }


        sort (a, a + length_of_a, cmp);

        int outputCost = 0,totalairport=0;
        int selectedEdges = vertex - 1;

        for ( int i = 0; i < length_of_a && selectedEdges; i++ ) {
            int p = parentOf (a [i].start);
            int q = parentOf (a [i].end);

            if ( p != q ) {
                if (size[p]>size[q])swap(p,q);
                size[q]+=size[p];
                parent [p] = q;
                selectedEdges--;
                if (a[i].distance>=costperairport)
                {
                    outputCost+=costperairport;
                    ++totalairport;

                }
                else
                    outputCost += a [i].distance;
            }
        }

        if ( selectedEdges )
        {
            outputCost+=costperairport*selectedEdges;
            totalairport+=selectedEdges;
        }
        outputCost+=costperairport;
        ++totalairport;
        printf ("Case #%d: %d %d\n",m,outputCost,totalairport);
    }

	return 0;
}

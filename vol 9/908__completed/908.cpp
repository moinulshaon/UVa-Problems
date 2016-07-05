#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define limit 1000000


using namespace std;

struct lists {
    int start;
    int end;
    int distance;
} a [limit+ 100];

int parent [limit + 100];
int size[limit+100];
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

    bool flag=false;
    while  (scanf("%d",&vertex)==1)
    {

        if (flag)
            printf("\n");
        flag=true;

        for (int i=1;i<=vertex; ++i )
        {
            parent [i] = i;
            size[i]=1;
        }

        int x,y,z,result1=0;

        for (int i=0;i<vertex-1;++i)
        {
            scanf("%d %d %d",&x,&y,&z);
            result1+=z;
        }



        int length_of_a=0;
        scanf("%d",&edges);
        for ( int i = 0; i < edges; i++ )
        {
            scanf("%d %d %d",&x,&y,&z);
            a [length_of_a].start = x;
            a [length_of_a].end = y;
            a [length_of_a].distance = z;
            length_of_a++;
        }
        scanf("%d",&edges);
        for ( int i = 0; i < edges; i++ )
        {
            scanf("%d %d %d",&x,&y,&z);
            a [length_of_a].start = x;
            a [length_of_a].end = y;
            a [length_of_a].distance = z;
            length_of_a++;
        }


        sort (a, a + length_of_a, cmp);

        int outputCost = 0;
        int selectedEdges = vertex - 1;

        for ( int i = 0; i < length_of_a && selectedEdges; i++ ) {
            int p = parentOf (a [i].start);
            int q = parentOf (a [i].end);

            if ( p != q ) {
                if (size[p]>size[q])swap(p,q);
                size[q]+=size[p];
                parent [p] = q;
                selectedEdges--;
                outputCost+=a[i].distance;

            }
        }

        printf ("%d\n%d\n",result1,outputCost);
    }

	return 0;
}

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>

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

    freopen("in.txt","r",stdin);
    int test;
    scanf("%d",&test);

    for  (int m=1;m<=test;++m )
    {
        if ( m!=1 )printf("\n");

        scanf("%d %d %d",&vertex,&edges);


        for (int i=0;i< vertex; ++i )
        {
            parent [i] = i;
            size[i]=1;
        }

        map<string,int> mp;
        string aa,bb;

        int x=0,z,length_of_a=0;
        for ( int i = 0; i < edges; i++ )
        {
            cin>>aa>>bb>>z;

            if ( mp.find( aa )==mp.end() ){
                mp[aa]=x++;
            }
            if ( mp.find( bb )==mp.end() ){
                mp[bb]=x++;
            }

            a [length_of_a].start = mp[aa];
            a [length_of_a].end = mp[bb];
            a [length_of_a].distance = z;
            length_of_a++;
        }


        sort (a, a + length_of_a, cmp);

        int ans=0;
        int selectedEdges = vertex - 1;

        for ( int i = 0; i < length_of_a && selectedEdges; i++ ) {
            int p = parentOf (a [i].start);
            int q = parentOf (a [i].end);

            if ( p != q ) {
                if (size[p]>size[q])swap(p,q);
                size[q]+=size[p];
                parent [p] = q;
                selectedEdges--;
                ans+= a[i].distance;
            }
        }

        printf("%d\n",ans);
    }

	return 0;
}

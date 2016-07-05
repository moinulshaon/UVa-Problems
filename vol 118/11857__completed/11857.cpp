#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <iostream>
#include <queue>
#include <climits>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

typedef pair<int,int> pint;
typedef map<int,int> mint;

struct lists {
    int start;
    int end;
    int distance;
} a [1000000+ 10];

int parent [100000 + 10];
int size[100000+10];
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

int main(){

    while ( scanf("%d %d",&vertex,&edges) && (vertex+edges) ){

        for (int i=0;i< vertex; ++i ){
            parent [i] = i;
            size[i]=1;
        }

        int x,y,z,length_of_a=0;
        for ( int i = 0; i < edges; i++ ){
            scanf("%d %d %d",&x,&y,&z);
            a [length_of_a].start = x;
            a [length_of_a].end = y;
            a [length_of_a].distance = z;
            length_of_a++;
        }

        sort (a, a + length_of_a, cmp);

        int selectedEdges = vertex - 1;
        int ans= -1 ;
        for ( int i = 0; i < length_of_a && selectedEdges; i++ ) {
            int p = parentOf (a [i].start);
            int q = parentOf (a [i].end);

            if ( p != q ) {
                if (size[p]>size[q])swap(p,q);
                size[q]+=size[p];
                parent [p] = q;
                selectedEdges--;
                ans=max( ans, a[i].distance );
            }
        }

        if ( selectedEdges ){
            printf("IMPOSSIBLE\n");
        }else{
            printf("%d\n",ans);
        }

    }


    return 0;
}

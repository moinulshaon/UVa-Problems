#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>

using namespace std;

struct lists {
    int start;
    int end;
    int distance;
} a [100000+ 10],save[100000+ 10];

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
int length_of_a;
vector<int> medge;

int mst(){


    sort (a, a + length_of_a, cmp);
    for (int i=0;i<vertex; ++i ){
        parent [i] = i;
        size[i]=1;
    }
    int selectedEdges = vertex - 1;
    int sum=0;
    for ( int i = 0; i < length_of_a && selectedEdges; i++ ) {
        int p = parentOf (a [i].start);
        int q = parentOf (a [i].end);

        if ( p != q ) {
            if (size[p]>size[q])swap(p,q);
            size[q]+=size[p];
            parent [p] = q;
            selectedEdges--;

            medge.push_back( i );

            sum+= a[i].distance;
        }
    }
    return sum;
}

int mst2(){


    sort (a, a + length_of_a, cmp);
    for (int i=0;i<vertex; ++i ){
        parent [i] = i;
        size[i]=1;
    }
    int selectedEdges = vertex - 1;
    int sum=0;
    for ( int i = 0; i < length_of_a && selectedEdges; i++ ) {
        int p = parentOf (a [i].start);
        int q = parentOf (a [i].end);

        if ( p != q ) {
            if (size[p]>size[q])swap(p,q);
            size[q]+=size[p];
            parent [p] = q;
            selectedEdges--;
            sum+= a[i].distance;
        }
    }
    return sum;
}

int main (){

    freopen("in.txt","r",stdin);
    int test;
    scanf("%d",&test);

    for  (int m=1;m<=test;++m ){


        scanf("%d %d",&vertex,&edges);

        int x,y,z;
        length_of_a=0;
        for ( int i = 0; i < edges; i++ ){
            scanf("%d %d %d",&x,&y,&z);
            a [length_of_a].start = x-1;
            a [length_of_a].end = y-1;
            a [length_of_a].distance = z;
            length_of_a++;
        }


        medge.clear();

        int s1=mst(),s2=(1<<29),tmp;

        memcpy( save,a,sizeof(lists)*length_of_a );

        for (int i=0;i<medge.size();++i){

            tmp=a[ medge[i] ].distance;
            a[ medge[i] ].distance=(1<<29);

            s2=min( s2,mst2() );

            memcpy( a,save,sizeof(lists)*length_of_a );
        }
        printf("%d %d\n",s1,s2);
    }

	return 0;
}

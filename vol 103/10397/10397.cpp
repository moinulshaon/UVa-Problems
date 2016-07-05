#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

struct lists {
    int start;
    int end;
    double distance;
} a [600000];

int parent [1000];
int size[1000];

int vertex;
int edges;


struct mathv{
    int x,y;
}location[1000];
double distance2DPointAndPoint(mathv& v1, mathv& v2){
    return sqrt((v2.x - v1.x) * (v2.x - v1.x)+ (v2.y - v1.y) * (v2.y - v1.y));
}




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

    while  ( scanf("%d",&vertex)==1 )
    {
        for (int i=0;i<vertex;++i){
            scanf("%d %d",&location[i].x,&location[i].y);
        }

        for (int i=0;i< vertex; ++i ){
            parent [i] = i;
            size[i]=1;
        }


        int length_of_a=0;
        for (int i=0;i<vertex;++i){
            for (int j=i+1;j<vertex;++j){
                a [length_of_a].start = i;
                a [length_of_a].end = j;
                a [length_of_a].distance = distance2DPointAndPoint( location[i],location[j] );
                length_of_a++;
            }
        }


        sort (a, a + length_of_a, cmp);


        int selectedEdges = vertex - 1;
        int alreadyConnected,x,y;

        scanf("%d",&alreadyConnected);
        for ( int i = 0; i < alreadyConnected ; i++ ){
            scanf("%d %d",&x,&y);
            int p = parentOf (x-1);
            int q = parentOf (y-1);

            if ( p != q ) {
                if (size[p]>size[q])swap(p,q);
                size[q]+=size[p];
                parent [p] = q;
                selectedEdges--;
            }
        }

        double result=0;

        for ( int i = 0; i < length_of_a && selectedEdges; i++ ) {
            int p = parentOf (a [i].start);
            int q = parentOf (a [i].end);

            if ( p != q ) {
                if (size[p]>size[q])swap(p,q);
                size[q]+=size[p];
                parent [p] = q;
                selectedEdges--;
                result+=a[i].distance;
            }
        }
        printf("%.2lf\n",result);

    }

	return 0;
}

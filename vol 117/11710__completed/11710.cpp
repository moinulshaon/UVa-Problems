#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <cmath>

using namespace std;

struct lists {
    int start;
    int end;
    int distance;
} a [79800 + 10];

int parent [400 + 10];
int size[400+10];
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
    while ( scanf ("%d %d", &vertex, &edges) ) {
        if ( vertex == 0 && edges == 0 ) break;

        map < string, int > cityIndex;

        for (int i=0;i< 410; ++i )
        {
            parent [i] = i;
            size[i]=1;
        }


        for ( int i = 0; i < vertex; i++ ) {
            string s;
            cin >> s;
            cityIndex [s] = i + 1;
        }

        int length_of_a = 0;

        for ( int i = 0; i < edges; i++ ) {
            string s, t;
            int c;
            cin >> s >> t >> c;
            a [length_of_a].start = cityIndex [s];
            a [length_of_a].end = cityIndex [t];
            a [length_of_a].distance = c;
            length_of_a++;
        }

        string source;
        cin >> source;

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
                outputCost += a [i].distance;
            }
        }

        if ( selectedEdges ) printf ("Impossible\n");
        else printf ("%d\n", outputCost);
    }

	return 0;
}

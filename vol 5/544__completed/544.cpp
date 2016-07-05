#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

#define INF 100000000

struct lists {
    int start;
    int end;
    int distance;
} a [20000];

int parent [300];
int size[300];


vector<int> outarrow[300];
vector<int> weightOfEdge[300];

int vertex;
int edges;

bool cmp (lists p, lists q)
{
    if ( p.distance > q.distance ) return true;
    return false;
}

int parentOf (int n)
{
    if ( n == parent [n] ) return n;
    return parent [n] = parentOf (parent [n]);
}


int result;
bool vis[300];
int finishNode;

void DFS( int n ,int weight){
    if ( vis[n]  || result!=-1 )return ;

    if ( n==finishNode ){
        result=weight;
    }
    vis[n]=true;

    for (int i=0;i<outarrow[n].size();++i){
        DFS( outarrow[n][i] ,min( weight , weightOfEdge[n][i] )  );
    }
}


int main ()
{

    freopen("in.txt","r",stdin);

    for  (int kk=1;true;++kk ){

        scanf("%d %d",&vertex,&edges);

        if ( !vertex && !edges )return 0;

        for (int i=0;i< vertex; ++i ){
            parent [i] = i;
            size[i]=1;
            outarrow[i].clear();
            weightOfEdge[i].clear();
        }


        int x,length_of_a=0,numberOfCity=0;
        string s1,s2;
        map<string,int> myp;
        for ( int i = 0; i < edges; i++ ){
            cin>>s1>>s2>>x;

            if (myp.find(s1)==myp.end()){
                myp[s1]=numberOfCity++;
            }
            if (myp.find(s2)==myp.end()){
                myp[s2]=numberOfCity++;
            }

            a [length_of_a].start = myp[s1];
            a [length_of_a].end = myp[s2];
            a [length_of_a].distance = x;
            length_of_a++;
        }


        sort (a, a + length_of_a, cmp);

        int selectedEdges = vertex - 1;

        for ( int i = 0; i < length_of_a && selectedEdges; i++ ) {
            int p = parentOf (a [i].start);
            int q = parentOf (a [i].end);

            if ( p != q ) {
                if (size[p]>size[q])swap(p,q);
                size[q]+=size[p];
                parent [p] = q;
                selectedEdges--;

                outarrow[ a[i].start ].push_back( a[i].end );
                weightOfEdge[ a[i].start ].push_back( a[i].distance );

                outarrow[ a[i].end ].push_back( a[i].start );
                weightOfEdge[ a[i].end ].push_back( a[i].distance );
            }
        }

        result=-1;
        memset(vis,false,sizeof(vis) );

        cin>>s1>>s2;

        if (myp.find(s1)==myp.end()){
            myp[s1]=numberOfCity++;
        }
        if (myp.find(s2)==myp.end()){
            myp[s2]=numberOfCity++;
        }


        finishNode=myp[s2];

        DFS( myp[s1] ,INF );
        if ( result== -1 )result=0;

        printf("Scenario #%d\n",kk);
        printf("%d tons\n\n",result);
    }
}

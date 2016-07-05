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
} a [11000+ 10];

int parent [200 + 10];
int size[ 200+10 ];
int vertex;
int edges;

bool cmp (const lists& p,const lists& q)
{
    if ( p.distance < q.distance ) return true;
    return false;
}

int parentOf (int n)
{
    if ( n == parent [n] ) return n;
    return parent [n] = parentOf (parent [n]);
}

vector<int> out[200+10];

char vis[210];
bool check(){
    int f;

    NEG(vis);
    queue<int> q;
    q.push( 1 );
    vis[ 1 ]= 0;
    bool ok=true;
    while ( !q.empty() && ok ){
        f=q.front();q.pop();
        for (int i=0;i<out[f].size();++i){
            if ( vis[ out[f][i] ] == -1 ){
                vis[ out[f][i] ] = !vis[f];
                q.push( out[f][i] );
            }else if ( vis[ out[f][i] ] == vis[f] ){
                ok=false;
                break;
            }
        }
    }
    return ok;
}

int main(){

    FRO

    while ( scanf("%d",&vertex)==1 && vertex ){
        scanf("%d",&edges);
        for (int i=0;i<=vertex;++i){
            out[i].clear();
        }

        int u,v,w;
        int cnt = 0;
        for (int i=0;i<edges;++i){
            scanf("%d %d %d",&u,&v,&w);
            out[u].PB( v );
            out[v].PB( u );

            a[cnt].start=u;
            a[cnt].end=v;
            a[cnt].distance=w;
            cnt++;
        }

        if ( !check( ) ){
            printf("Invalid data, Idiot!\n");
            continue;
        }

        for (int i=0;i<= vertex; ++i ){
            parent[i] = i;
            size[i]=1;
        }

        sort( a,a+cnt,cmp );

        int ans = 0;
        int left= vertex-1;
        int p,q;
        for (int i=0;i<cnt ;++i ){
            p = parentOf (a [i].start);
            q = parentOf (a [i].end);

            if ( p != q || a[i].distance<0 ) {
                if (size[p]>size[q])swap(p,q);
                size[q]+=size[p];
                parent [p] = q;
                left--;
                ans+= a[i].distance;
            }
        }

        if ( left<=0 )printf("%d\n",ans);
        else printf("Invalid data, Idiot!\n");
    }


    return 0;
}

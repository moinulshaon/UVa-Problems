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
#define MAX 1000
#define NIL 0
#define INF (1<<28)

vector <int> G[MAX];
int n, match[MAX], dist[MAX];
// n: number of nodes on left side, nodes are numbered 1 to n
// m: number of nodes on right side, nodes are numbered n+1 to n+m
// G = NIL[0] ? G1[G[1---n]] ? G2[G[n+1---n+m]]

bool bfs() {
    int i, u, v, len;
    queue< int > Q;
    for(i=1; i<=n; i++) {
        if(match[i]==NIL) {
            dist[i] = 0;
            Q.push(i);
        }
        else dist[i] = INF;
    }
    dist[NIL] = INF;
    while(!Q.empty()) {
        u = Q.front(); Q.pop();
        if(u!=NIL) {
            len = G[u].size();
            for(i=0; i<len; i++) {
                v = G[u][i];
                if(dist[match[v]]==INF) {
                    dist[match[v]] = dist[u] + 1;
                    Q.push(match[v]);
                }
            }
        }
    }
    return (dist[NIL]!=INF);
}

bool dfs(int u) {
    int i, v, len;
    if(u!=NIL) {
        len = G[u].size();
        for(i=0; i<len; i++) {
            v = G[u][i];
            if(dist[match[v]]==dist[u]+1) {
                if(dfs(match[v])) {
                    match[v] = u;
                    match[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}

int hopcroft_karp() {
    int matching = 0, i;
    memset(match,0,sizeof(match));
    // match[] is assumed NIL for all vertex in G
    while(bfs())
        for(i=1; i<=n; i++)
            if(match[i]==NIL && dfs(i))
                matching++;
    return matching;
}

struct mathv{
    mathv(){x=0;y=0;}
    mathv(int a,int b){x=a;y=b;}
    int x,y;
    int str;
    mathv operator + (mathv & p){
        mathv tmp( x+p.x,y+p.y );
        return tmp;
    }
    mathv operator - (mathv & p){
        mathv tmp( x-p.x,y-p.y );
        return tmp;
    }
}point[310],le[310],ri[310];

int dot2D(mathv v1, mathv v2){
    return v1.x * v2.x + v1.y * v2.y;
}
int cross2D(mathv v1, mathv v2){
    return v1.x * v2.y - v1.y * v2.x;
}

int distance2DPointAndPoint(mathv v1, mathv v2){
    return (v2.x - v1.x) * (v2.x - v1.x)+ (v2.y - v1.y) * (v2.y - v1.y);
}

int R;

int main(){

    FRO

    int total;
    for (int kk=1; scanf("%d",&total) == 1 && total ;++kk ){

        for (int i=1;i<=total;++i){
            scanf("%d %d %d",&point[i].x,&point[i].y,&point[i].str);
        }
        int a,b;
        scanf("%d %d %d",&a,&b,&R);

        int c1=1,c2=1;
        for ( int i=1;i<=total;++i ){
            if ( point[i].str > 0 ){
                if ( cross2D( point[b]-point[a], point[i]-point[a] )>=0 ){
                    le[c1++]=point[i];
                }else{
                    ri[c2++]=point[i];
                }
                //cout<<point[i].str<<endl;
            }
        }

        //cout<<c1<<" "<<c2<<endl;

        if ( c1>c2 ){
            for (int i=0;i<=c1;++i){
                swap( le[i],ri[i] );
            }
            swap( c1,c2 );
        }

        for (int i=0;i<MAX;++i){
            G[i].clear();
        }

        n = c1-1;
        for (int i=1;i<c1;++i){
            for (int j=1;j<c2;++j){
                if ( le[i].str>ri[j].str && distance2DPointAndPoint( le[i],ri[j] ) <= R*R   ){
                    G[ i ].PB( n+j );
                }
            }
        }

        printf("Case %d: %d\n",kk,hopcroft_karp());
    }


    return 0;
}

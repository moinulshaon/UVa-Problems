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

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define MAX 301
#define NIL 0
#define INF (1<<28)

vector <int> G[MAX];
int n,m, match[MAX], dist[MAX];
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


int save[MAX][MAX];

void buildgraph(int val,int node){
    n=node;
    for (int i=0;i<=(node<<1)+1;++i){
        G[i].clear();
    }

    for (int i=1;i<=node;++i){
        for (int j=i+1;j<=node;++j){
            if ( save[i][j]>=val ){
                G[i].PB(n+j);
                G[j].PB(n+i);
            }
        }
    }
}

int main(){
    FRO
    int left,right;
    int kase;
    scanf("%d",&kase);

    for(int kk=1; kase-- ;++kk){

        scanf("%d",&left);
        left=1<<left;
        right=left;


        int low=(1<<29);
        int high=0;
        for (int i=1;i<=left;++i){
            for (int j=i+1;j<=right;++j){
                scanf("%d",&save[i][j]);
                save[j][i]=save[i][j];
                low=min(low,save[i][j]);
                high=max(high,save[i][j]);
                //printf("shaon %d %d\n",i,j);
            }
        }

        int ans,mid;
        while( low<=high ){
            mid=(low+high)/2;
            buildgraph(mid,left);

            printf("%d %d %d\n",left,hopcroft_karp(),mid);
            if ( hopcroft_karp()>=left ){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }

        }
        printf("Case %d: %d\n",kk,ans);
    }

    return 0;
}

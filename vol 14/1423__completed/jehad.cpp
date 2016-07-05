#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<math.h>

#define pb push_back
#define INF (1<<29)
using namespace std;


vector<int>edge[100];
vector<int>cost[100];

/// si - sj <=2
/// si <= 2 + sj

/// 0 ->si 0->sj sj-->si ,2

char fao[1000];
int dist[1000];

int V,n;

void bellu(int S)
{
    dist[S] = 0 ;
    for(int i = 1 ; i <= V-1 ; i++) {
        for(int j=0;j<=n+1;j++) {
            for(int k=0;k<edge[j].size();k++) {
                int nx = edge[j][k];
                if(dist[j] + cost[j][k] < dist[nx] &&dist[j]!=INF)  dist[nx] = dist[j] + cost[j][k] ;
            }
        }

    }
}

int main()
{
    freopen("in.txt","r",stdin);
    int tst;
    scanf("%d",&tst);
    while(tst--) {
        scanf("%d",&n);
        scanf("%s",&fao);
        int cnt = 0 ;
        for(int i=0;i<=n+1;i++) edge[i].clear(),cost[i].clear();
        for(int i=0;i<=n+1;i++) dist[i] = INF;
        for(int i=0;i<=n;i++) edge[n+1].pb(i),cost[n+1].pb(0);
        V = n + 2 ;

        /// s[j] - s[i-1] >=1
        /// s[i-1]<=-1 + s[j]

        /// s[j] - s[i-1] < 0
        /// s[j] - s[i-1] <= -1
        /// s[j] <= -1 + s[i-1]

        /// s[j] - s[i-1] = 0
        /// s[j] - s[i-1] >=0
        /// s[i-1] - s[j] >=0


        for(int i=1;i<=n;i++) {
            for(int j=i;j<=n;j++) {
                if(fao[cnt]=='+') {
                    edge[j].pb(i-1);
                    cost[j].pb(-1);
                }
                else if(fao[cnt]=='-') {
                    edge[i-1].pb(j);
                    cost[i-1].pb(-1);
                }
                else {
                    edge[j].pb(i-1); cost[j].pb(0);
                    edge[i-1].pb(j); cost[i-1].pb(0);
                }
                cnt++;
            }
        }

        bellu(n+1);
        for(int i=1;i<=n;i++) {
            if(i!=1) printf(" ");
            printf("%d",dist[i]-dist[i-1]);
        }
        printf("\n");
    }

    return 0;
}

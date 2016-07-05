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

#define X first
#define Y second

#define MP make_pair

#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)


typedef pair<int,int> pint;
typedef map<int,int> mint;

#define INF (1<<28)
#define SIZE 5110

int source,sink,nodes,row,col,par[SIZE],flow,cnt;
vector<int>adj[SIZE];

struct edges{
    int u,v,cap,rev_ind;

    edges(int _u=0,int _v=0,int _cap=0,int _rev_ind=0){
        u=_u;v=_v;cap=_cap;rev_ind=_rev_ind;
    }
};

edges E[1000000];

void addedge(int u,int v,int cap){
    //cout<<u<<" "<<v<<" "<<cap<<endl;
    E[cnt]=edges(u,v,cap,cnt+1);
    E[cnt+1]=edges(v,u,0,cnt);
    adj[u].PB(cnt);
    adj[v].PB(cnt+1);
    cnt+=2;
}

bool AugmentPath(){
    int i,u,ind,v,cap;
    queue<int>Q;

    NEG(par);
    Q.push(source);
    par[source]=-2;

    while(!Q.empty()){
        u=Q.front();
        Q.pop();

        for(int i=0;i<adj[u].size();++i){
            ind=adj[u][i];
            v=E[ind].v;
            cap=E[ind].cap;
            if(par[v]==-1 && cap>0){
                par[v]=ind;
                if(v!=sink)
                    Q.push(v);
            }
        }
    }
    return par[sink]!=-1;

}

void Update_Graph(int v){
    int ind=par[v];

    if(ind>=0){
        flow=min(flow,E[ind].cap);
        Update_Graph(E[ind].u);
        E[ind].cap-=flow;
        ind=E[ind].rev_ind;
        E[ind].cap+=flow;
    }
}

int MaxFlow(){
    int ans=0,i,u,ind;

    while(AugmentPath()){
        for(int i=0;i<adj[sink].size();++i){
            ind=E[adj[sink][i]].rev_ind;
            u=E[ind].u;
            if(par[u]>=0){
                par[sink]=ind;
                flow=INF;
                Update_Graph(sink);
                ans+=flow;
            }
        }
    }
    return ans;
}

struct ee{
    int u,v,w,d;
}save[SIZE*SIZE];

int carry;
int func( int x,int d ){
    return (x-1)*(carry+1)+d+1;
}

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int n,m,k;
        scanf("%d %d %d",&n,&m,&k);
        for (int i=0;i<m;++i){
            scanf("%d %d %d %d",&save[i].u,&save[i].v,&save[i].d,&save[i].w);
        }

        int low =1,high=100;
        int ans = -1;
        while ( low<=high ){
            carry=(low+high)/2;

            cnt=0;
            for (int i=0;i<= n*(carry+1)+1;++i ){
                adj[i].clear();
            }

            source=0,sink=n*(carry+1)+1;
            for (int i=0;i<=carry;++i){
                addedge( 0,func(1,i),INF );
            }
            for (int i=0;i<=carry;++i){
                addedge( func(n,i),sink,INF );
            }

            for (int i=1;i<=n;++i){
                for (int j=0;j<carry;++j){
                    addedge( func(i,j),func(i,j+1),INF );
                }
            }

            for (int i=0;i<m;++i){
                for (int j=0;j<=carry;++j){
                    if ( j+save[i].d <=carry )
                    addedge( func( save[i].u,j ) , func( save[i].v,j+save[i].d ) ,save[i].w );
                }
            }
            //cout<<MaxFlow()<<endl;

            if ( MaxFlow()>=k ){
                ans = carry;
                high=carry-1;
            }else{
                low=carry+1;
            }

        }
        printf("Case %d: %d\n",kk,ans);

    }

    return 0;
}

#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>


using namespace std;

int in[20000100];
int out[20000100];
int time;
int sum[301000];
bool vis[20000100];
int n;
int stk[301000];
int top;
void dfsStack(){
    top=0;
    stk[++top]=0;
    memset(vis,false,sizeof(vis));
    while ( top ){
        int tt=stk[top];
        if ( vis[tt] ){
            out[tt]=time++;
            --top;
            continue;
        }
        in[tt]=time++;
        if (tt<n){
            if ( tt!=0 ){
                for (int i=sum[tt-1]+1;i<=sum[tt];++i){
                    stk[++top]=i;
                }
            }else{
                for (int i=1;i<=sum[0];++i){
                    stk[++top]=i;
                }
            }
        }
        vis[tt]=true;
    }
}


int main(){
    freopen("in.txt","r",stdin);
    int kase,tmp,m,a,b;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        if( kk!=1 )printf("\n");
        printf("Case %d:\n",kk);
        scanf("%d",&n);
        for (int i=0;i<n;++i){
            scanf("%d",&sum[i]);
            if (i)sum[i]+=sum[i-1];
        }
        time=0;
        dfsStack();
        scanf("%d",&m);
        while (m--){
            scanf("%d %d",&a,&b);
            if ( in[a]<in[b] && out[a]>out[b] ){
                printf("Yes\n");
            }else{
                printf("No\n");
            }
        }
    }
    return 0;

}

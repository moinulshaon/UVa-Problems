#include<bits/stdc++.h>
using namespace std;

#define SIZE 305

int coin[SIZE];
int dp[SIZE];


int main(){

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int n,m;
        scanf("%d %d",&n,&m);
        for (int i=0;i<n;++i){
            scanf("%d",&coin[i]);
        }
        sort( coin,coin+n );
        reverse( coin,coin+n );

        for (int i=0;i<=m;++i)dp[i] = 0;
        dp[0] = 1;
        for (int i=0;i<n;++i){
            for (int j=coin[i];j<=m;++j){
                if ( dp[ j-coin[i] ] > 0 ){
                    if ( dp[j] == 0 )
                        dp[j] = dp[ j-coin[i] ]+1;
                    else
                        dp[j] = min( dp[j] , dp[ j-coin[i] ]+1 );
                }
            }
        }

        printf("Case %d: ",kk);
        if ( dp[m] == 0 ){
            printf("impossible\n");
        }else{
            vector<int> ans;
            while(m>0){
                for (int i=0;i<n;++i){
                    if ( m-coin[i]>=0 && dp[ m-coin[i] ]+1 == dp[m] ){
                        ans.push_back( coin[i] );
                        m -= coin[i];
                        break;
                    }
                }
            }

            printf("[%d]",int(ans.size()) );
            for (int&x:ans){
                printf(" %d",x);
            }printf("\n");
        }

    }

    return 0;
}

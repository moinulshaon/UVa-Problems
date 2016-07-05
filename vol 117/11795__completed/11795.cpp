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


int n,rob;
LL dp[1<<17];

int Set(int N,int pos){
    return N=N | (1<<pos);
}
int Reset(int N,int pos){
    return N= N & ~(1<<pos);
}
bool Check(int N,int pos){
    return (bool)(N & (1<<pos));
}

char mat[20][20];


LL func( int state ){

    //cout<<state<<endl;

    if ( state ==(1<<n)-1 ){
        return 1;
    }

    if ( dp[state] != -1 )return dp[state];

    LL ans = 0;
    for (int i=1;i<n;++i){
        if ( Check( state,i ) == 0  ){
            bool ok=false;
            for (int j=0;j<n && !ok ;++j){
                if ( mat[j][i-1] == '1' && Check( state,j ) == 1 ){
                    ok=true;
                }
            }
            if ( ok ){
                ans += func( Set( state,i ) );
            }
        }
    }
    return dp[state]  = ans ;
}


int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d",&rob);
        n= rob+1;
        for (int i=0;i<n;++i){
            scanf("%s",mat[i]);
        }

        NEG(dp);

        printf("Case %d: %lld\n",kk,func( Set(0,0) ) );

    }


    return 0;
}

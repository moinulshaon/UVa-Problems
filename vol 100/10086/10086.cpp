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

int dp[305][305];

int cc1[305],cc2[305];
bool border[305];
int func( int now,int h1 ){


    if ( now == 0 ){
        //cout<<now<<h1<<endl;
        return 0;
    }

    if ( dp[now][h1] != -1 )return dp[now][h1];

    //cout<<now<<' '<<h1<<endl;

    int sum=(1<<29);
    if ( h1>0 ){
        sum=min( sum,cc1[now]+func( now-1,h1-1 ) );
    }
    if ( now-h1>0 ){
        sum=min( sum,cc2[now]+func( now-1,h1 ) );
    }
    return dp[now][h1]=sum;
}

vector<int> ans;
int cnt;

void prnt(int now,int h1){
    if ( now==0 ){
        ans.PB( cnt );
        return ;
    }

    if ( border[now] ){
        //cout<<cc1[now]<<' '<<cc2[now]<<endl;
        ans.PB( cnt );
        cnt=0;
    }

    if (h1>0 && dp[now][h1] == cc1[now]+func( now-1,h1-1 ) ){
        cnt++;
        prnt( now-1,h1-1 );
    }else{
        prnt( now-1,h1 );
    }
}

int main(){
    FRO

    int t1,t2;
    while ( scanf("%d %d",&t1,&t2)==2 && (t1+t2) ){
/*
        for (int i=0;i<(t1+t2);++i){
            for (int j=0;j<t1;++j){
                dp[i][j]= -1;
            }
        }
*/
        NEG(dp);

        int tmp;
        scanf("%d",&tmp);
        int total=1;
        CLR(border);

        while ( tmp-- ){
            int x;
            scanf("%d",&x);
            for (int i=0;i<x;++i){
                scanf("%d",&cc1[total+i]);
            }
            for (int i=0;i<x;++i){
                scanf("%d",&cc2[total+i]);
            }

            total+= x;
            border[total-1]=true;
        }

        /*
        for (int i=1;i<=t1+t2;++i){
            printf("%d %d\n",cc1[i],cc2[i]);
        }
        */


        //cout<<t1<<' '<<t2<<' '<<total<<endl;
        printf("%d\n",func(t1+t2,t1));

        ans.clear();
        cnt=0;
        prnt(t1+t2,t1);

        for (int i=1;i<ans.size();++i){
            if ( i!=1 )printf(" ");
            printf("%d",ans[i]);
        }printf("\n\n");

    }


    return 0;
}

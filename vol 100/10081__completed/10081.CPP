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

double dp[105][10][10];
bool vis[105][10][10]={0};
int k;

double func( int left,int prv ){

    if ( left == 0 )return 1;

    if ( vis[left][prv][k] )return dp[left][prv][k];

    vis[left][prv][k]=true;

    double &ret = dp[left][prv][k];

    ret =func(left-1,prv);
    if ( prv+1<=k ){
        ret += func(left-1,prv+1);
    }
    if ( prv-1>=0 ){
        ret += func(left-1,prv-1);
    }

    return ret;
}

int main(){



    int n;

    while( scanf("%d %d",&k,&n)==2 ){

        double cnt = 0;
        for (int i=0;i<=k;++i){
            cnt += func( n-1,i );
        }
        //cout<<cnt<<endl;
        printf("%.5lf\n",cnt/pow(k+1,n)*100);
    }


    return 0;
}

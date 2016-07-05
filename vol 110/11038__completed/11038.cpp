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

LL pp[11];


LL dp[11][2];

LL shaon( int left ,int on ){

    if ( left ==0 ){
        return 0;
    }

    LL &ret=dp[left][on];

    if ( ret != -1 )return ret;

    ret = 0;
    for (int i=0;i<10;++i){
        if ( on ){
            ret+= (i==0)*pp[left-1]+shaon( left-1,1 );
        }else{
            if ( i==0 )
                ret+= shaon( left-1,0 );
            else
                ret+= shaon(left-1,1);
        }

    }
    return ret;
}

LL func( LL x ){

    if ( x<0 )return 0;

    char str[15];
    sprintf(str,"%lld",x);;
    int len=strlen(str);

    LL ans = 0;
    for (int i=0;i<len;++i){
        int left = len-i;

        int lim = str[i]-'0';
        for (int j=0;j<lim;++j){
            if ( i==0 && j==0 )
                ans+= shaon( left-1,0 );
            else
                ans+= (j==0)*pp[left-1] + shaon( left-1,1 );
        }

    }
    LL cum;
    for (int i=len-2;i>=0;--i){
        if ( str[i] == '0' ){
            sscanf(&str[i+1],"%lld",&cum);
            ans +=  cum;
        }
    }
    for ( int i=0;i<len;++i ){
        if ( str[i] == '0' ){
            ans++;
        }
    }
    return ans+(x>0);
}

int main(){

    //FRO

    NEG(dp);

    pp[0]=1;
    for (int i=1;i<11;++i){
        pp[i] = pp[i-1]*10;
    }

    //cout<<func(109);





    while (true){
        LL a,b;
        scanf("%lld %lld",&a,&b);
        if ( a<0 )break;
        //cout<<a<<" "<<b<<endl;
        printf("%lld\n",func(b)-func(a-1));
    }


    return 0;
}

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

char arr[20];

LL dp[20][20];
int dim ;

int ff(char c){
    if ( c>='1' && c<='9' ){
        return c-'1';
    }else{
        return c-'A'+9;
    }
}

LL func(int col,int prv){

    if ( arr[col] == '\0' )return 1;

    if ( dp[col][prv] != -1 )return dp[col][prv];

    if (  arr[col]!='?' ){
        if ( abs( prv-ff(arr[col]) ) < 2 ){
            return 0;
        }
        return dp[col][prv] = func(col+1, ff(arr[col]) );
    }else{
        LL ans=0;
        for (int i=0;i<dim;++i){
            if ( abs( prv-i ) > 1 ){
                ans+= func( col+1,i );
            }
        }
        return dp[col][prv] = ans;
    }
}

int main(){

    FRO

    while ( scanf("%s",arr)==1 ){

        dim=strlen(arr);

        NEG(dp);

        printf("%lld\n",func(0,19));
    }


    return 0;
}

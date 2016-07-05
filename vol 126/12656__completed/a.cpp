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

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

typedef pair<int,int> pint;
typedef map<int,int> mint;

#define SIZE 1010

char arr[SIZE];

int miss;
char ans[SIZE];
int cnt[SIZE];
int len;

int dp[SIZE][SIZE];

int func( int le,int ri ){

    if ( dp[le][ri] != -1 )return dp[le][ri];

    if ( ri<le )return 0;
    else  return dp[le][ri] = ( ans[le]!=ans[ri] ) + func( le+1,ri-1 );
}

int main(){
    FRO

    for (int kk=1;scanf("%d",&miss)==1;++kk){
        gets(arr);
        gets(arr);

        int tmp=strlen(arr);
        len=0;

        int shaon=0;
        for (int i=0;i<tmp;++i){
            if ( isalpha( arr[i] ) ){
                ans[len]=tolower( arr[i] );
                cnt[ len++ ] = shaon;
            }
            shaon++;
        }

        NEG(dp);

        int x= -1;
        shaon= 100000;
        for ( int i=0;i< len ;++i ){
            for (int j=i;j<len;++j){
                if ( func( i,j )<=miss ){
                    if ( cnt[j]-cnt[i]+1 > x ){
                        x=cnt[j]-cnt[i]+1;
                        shaon=cnt[i];
                    }else if ( cnt[j]-cnt[i]+1 == x ){
                        shaon=min( shaon,cnt[i] );
                    }
                }
            }
        }
        printf("Case %d: %d %d\n",kk,x,shaon+1);

    }


    return 0;
}

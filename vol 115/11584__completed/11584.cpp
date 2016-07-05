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

#define SIZE 1005

char dp[SIZE][SIZE];

char arr[SIZE];

bool func(int le,int ri){

    if ( le>=ri )return true;

    if ( dp[le][ri] != -1 )return dp[le][ri];

    return dp[le][ri]= ( arr[le] == arr[ri] ) && func( le+1,ri-1 );
}

int ans[SIZE];

int len ;
int shaon(int totake){

    //cout<<totake<<endl;

    if ( totake>=len )return 0;

    int &ret= ans[totake];

    if ( ret != -1 )return ret;

    ret = (1<<29);
    for (int i=totake;i<len;++i){
        if ( func( totake,i ) ){
            ret= min( ret , 1 + shaon( i+1 ) );
            //cout<<totake<<" "<<i<<endl;
        }
    }
    return ret;
}

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    while ( kase-- ){
        scanf("%s",arr);
        len=strlen(arr);

        NEG( dp );
        NEG( ans );

        printf("%d\n",shaon(0));

    }


    return 0;
}

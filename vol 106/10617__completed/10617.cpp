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

#define SIZE 65

char arr[SIZE];

LL ff[SIZE][SIZE];

LL func( int a,int b ){
    if ( a==b )return 1;
    else if ( a>b )return 0;

    LL &ret = ff[a][b];

    if ( ret != -1 )return ret;

    ret= func( a,b-1 ) + 1 ;

    for (int i=a;i<b;++i){
        if ( arr[i]==arr[b] ){
            ret+= 1+func( i+1,b-1 );
        }
    }
    return ret;
}

int main(){

    //FRO

    int kase;
    scanf("%d",&kase);

    while ( kase--){
        scanf("%s",arr);
        NEG(ff);


        //cout<<arr<<endl;

        printf("%lld\n",func( 0,strlen(arr)-1 ));
    }


    return 0;
}

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

#define SIZE 85

int dp[SIZE][SIZE];
char arr[SIZE];

bool same[SIZE][SIZE];

int func( int x,int y ){

    if ( x>y )return 0;

    int &ret=dp[x][y];
    if ( ret!= -1 )return ret;

    ret = y-x+1;

    for (int i=x;i<=y;++i){
        int le = i-x+1;
        int cnt = 0;
        for (int j=x;j<=y;++j){
            //cout<<arr[j]<<" "<<arr[ cnt%le ] <<endl;
            if ( arr[j] == arr[ x + cnt%le ]  ){
                cnt++;
            }else{
                break;
            }
        }
        cnt/= le;
        //if ( x==0 && y == 12 )
        //cout<<x<<" "<<y<<" "<<i<<" "<< x+cnt*le<<" "<<func( x,i ) <<" "<< func( x+cnt*le,y )<<endl;
        ret= min( ret, func( x,i ) + func( x+cnt*le,y ) );
    }
    return ret;
}


int len;

int main(){

    FRO

    while ( scanf("%s",arr)==1 ){
        if ( arr[0] == '*' && arr[1]=='\0' )break;

        len=strlen( arr );

        //cout<<arr<<endl;
        NEG(dp);
        printf("%d\n",func( 0,len-1 ));
    }


    return 0;
}

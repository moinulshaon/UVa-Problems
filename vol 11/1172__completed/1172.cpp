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

int le,ri;
int osle[1100],osri[1100];
int luvle[1100],luvri[1100];
map<string,int> mp;


#define X first
#define Y second
#define MP make_pair

pint dp[1005][1005];

pint func( int a,int b ){

    if ( a == le || b== ri )return MP(0,0);
    if ( dp[a][b].X != -1 )return dp[a][b];


    pint ans = func( a,b+1 );
    pint tt = func( a+1,b );
    if (  tt.X>ans.X ){
        ans= tt;
    }else if ( tt.X== ans.X ){
        ans.Y= min( ans.Y,tt.Y );
    }
    if ( osle[a] == osri[b] ){
        tt=func( a+1,b+1 );
        tt.X += luvle[a];
        tt.X += luvri[b];
        tt.Y++;

        if (  tt.X>ans.X ){
            ans= tt;
        }else if ( tt.X== ans.X ){
            ans.Y= min( ans.Y,tt.Y );
        }
    }
    return dp[a][b]= ans;
}

int main(){

    FRO

    ios_base::sync_with_stdio( false );

    int kase;
    cin>>kase;

    while ( kase-- ){

        mp.clear();
        int tmp = 0;

        string ss;

        cin>>le;
        for (int i=0;i<le;++i){
            cin>>ss;
            cin>>ss;
            if ( mp.find( ss ) == mp.end() ){
                mp[ ss ] = tmp++;
            }
            osle[ i ] = mp[ ss ];
            cin>>luvle[i];
        }

        cin>>ri;
        for (int i=0;i<ri;++i){
            cin>>ss;
            cin>>ss;
            if ( mp.find( ss ) == mp.end() ){
                mp[ ss ] = tmp++;
            }
            osri[ i ] = mp[ ss ];
            cin>>luvri[i];
        }

        NEG(dp);
        pint ans = func( 0,0 );

        cout<<ans.X<<" "<<ans.Y<<endl;

    }


    return 0;
}

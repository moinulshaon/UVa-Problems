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


#define SIZE 210

vector<int>out[SIZE];

pint dp[SIZE][2];

pint func( int totake,int can ){

    pint &ret = dp[totake][can];
    if ( ret.X != -1 )return ret;

    ret = MP( 0,1 );

    pint sum = MP(0,1);
    for (int i=0;i<out[totake].size();++i){
        int y = out[totake][i];
        pint tmp = func(y,1);
        sum.X += tmp.X;
        sum.Y *= tmp.Y;
    }
    if ( sum.X > ret.X ){
        ret = sum;
    }else if ( sum.X == ret.X && sum.X != 0 ){
        ret.Y += sum.Y;
    }

    if ( can ){
        sum = MP(1,1);
        for (int i=0;i<out[totake].size();++i){
            int y = out[totake][i];
            pint tmp = func(y,0);
            sum.X += tmp.X;
            sum.Y *= tmp.Y;
        }
        if ( sum.X > ret.X ){
            ret = sum;
        }else if ( sum.X == ret.X && sum.X != 0 ){
            ret.Y += sum.Y;
        }
    }

    //cout<<totake<<" "<<can<<" "<<ret.X<<" "<<ret.Y<<endl;

    return ret;
}


pair<string,string> arr[SIZE];
map<string,int> mp;

int main(){

    FRO

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while ( cin>>n && n ){

        int cnt = 0;

        mp.clear();

        string u,v;
        cin>>u;
        mp[ u ] = cnt++;

        for (int i =1;i<n;++i){
            cin>>arr[i].X>>arr[i].Y;
            if ( mp.find( arr[i].X ) == mp.end() ){
                mp[ arr[i].X ] = cnt++;
            }
            if ( mp.find( arr[i].Y ) == mp.end() ){
                mp[ arr[i].Y ] = cnt++;
            }
        }

        for (int i =0;i<=cnt;++i){
            out[i].clear();
        }

        for (int i =1;i<n;++i){
            out[ mp[ arr[i].Y ] ].PB( mp[ arr[i].X ] );
            //cout<<mp[ arr[i].Y ]<<" "<<mp[ arr[i].X ]<<endl;
        }

        for (int i=0;i<=cnt;++i){
            dp[i][0].X = dp[i][0].Y= -1;
            dp[i][1].X = dp[i][1].Y= -1;
        }

        pint ans = func(0,1);

        cout<<ans.X<<" "<<( (ans.Y==1)?"Yes\n":"No\n" );
        //cout<<ans.X<<" "<<ans.Y<<endl;
    }


    return 0;
}

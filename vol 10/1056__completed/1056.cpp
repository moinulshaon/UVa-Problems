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


int n,ee;

map<string,int> mp;

int d[55][55];

int main(){


    int kk =1;
    while ( cin>>n>>ee && (n+ee) ){
        mp.clear();
        int x = 0;

        for (int i=0;i<n;++i){
            for (int j=0;j<n;++j){
                d[i][j] = (1<<27);
            }
        }

        string a,b;
        while ( ee-- ){
            cin>>a>>b;
            if ( mp.find(a)==mp.end() ){
                mp[a] = x++;
            }
            if ( mp.find(b)==mp.end() ){
                mp[b] = x++;
            }
            int u=mp[a],v=mp[b];
            d[ u ][ v ] = d[ v ][ u ] = 1 ;

        }


        for (int i=0;i<n;++i){
            d[i][i] = 0;
        }

        for (int k = 0; k < n; k++ ) {
            for (int  i = 0; i < n; i++ ) {
                for (int  j = 0; j < n; j++ ){
                    d [i] [j] = min (d [i] [j],  d [i] [k]+ d [k] [j]);
                }
            }
        }

        int mx = 0;
        for (int i=0;i<n;++i){
            for (int j=0;j<n;++j){
                mx=max( mx, d[i][j] );
            }
        }

        printf("Network %d: ",kk++);
        if ( mx> (1<<26) ){
            printf("DISCONNECTED\n");
        }else{
            printf("%d\n",mx);
        }

        printf("\n");
    }


    return 0;
}

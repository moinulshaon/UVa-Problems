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

#define SIZE 30

int cnt[SIZE][SIZE];
int ini[SIZE];
int fin[SIZE];

bool cmp( const pint&a,const pint&b ){
    if ( a.Y != b.Y )return a.Y<b.Y;
    else return a.X<b.X;
}

int main(){

    FRO

    int n;

    while ( scanf("%d",&n)==1 && n ){

        CLR(cnt);
        int tmp;
        for (int i=0;i<n;++i){
            int u,w,origin;
            scanf("%d %d",&origin,&tmp);

            while ( tmp-- ){
                scanf("%d %d",&u,&w);
                cnt[origin][u] += w;
            }
        }
        vector<pint> ans;
        while ( scanf("%d",&tmp)==1 && tmp ){
            int xx;
            for (int i=0;i<n;++i){
                scanf("%d",&xx);
                ini[xx] = i+1;
            }
            for (int i=0;i<n;++i){
                scanf("%d",&xx);
                fin[xx] = i+1;
            }

            int val = 0;

            for (int i=1;i<=n;++i){
                for (int j=1;j<=n;++j){
                    val+= cnt[i][j]*( abs( ini[i]-fin[j] )+1 );
                }
            }
            ans.PB( MP( tmp,val ) );
        }

        sort( ans.begin(),ans.end(),cmp );
        printf("Configuration Load\n");
        for (int i=0;i<ans.size();++i){
            printf("%5d         %d\n",ans[i].X,ans[i].Y);
        }

    }


    return 0;
}

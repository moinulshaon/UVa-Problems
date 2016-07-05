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
#define FRO freopen("p0.in","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

#define X first
#define Y second

#define MP make_pair

#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)


typedef pair<int,int> pint;
typedef map<int,int> mint;

bool cmp(const pint &a,const pint &b){
    return a.Y<b.Y;
}

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        mint mpx,mpy;

        vector<pint> vec;
        vector<int> revx,revy;

        int low ,high;
        scanf("%d %d",&low,&high);
        int n;
        scanf("%d",&n);
        vec.resize(n);
        int x=0,y=0;
        for (int i=0;i<n;++i){
            scanf("%d %d",&vec[i].X,&vec[i].Y);
            mpx[ vec[i].X ];
            mpy[ vec[i].Y ];
        }

        vec.PB( MP(0,0) );
        vec.PB( MP(low,0) );
        vec.PB( MP(0,high) );
        vec.PB( MP(low,high) );

        mpx[ 0 ];
        mpx[ low ];
        mpy[ 0 ];
        mpy[ high ];

        n+=4;

        snuke(mpx,itr){
            itr->second = x++;
            revx.PB( itr->first );
        }
        snuke(mpy,itr){
            itr->second = y++;
            revy.PB( itr->first );
        }

        for (int i=0;i<n;++i){
            vec[i].X = mpx[ vec[i].X ];
            vec[i].Y = mpy[ vec[i].Y ];
        }

        sort( vec.begin(),vec.end(),cmp );

        int ans = 0;
        for (int i=0;i<x;++i){
            for (int j=i+1;j<x;++j){
                vector<int> val;
                val.PB( 0 );
                for (int k=0;k<n;++k){
                    if ( vec[k].X> i && vec[k].X<j ){
                        val.PB( revy[ vec[k].Y ] );
                    }
                }
                val.PB( high );

                int mx = 0;
                for (int k=1;k<val.size();++k){
                    mx = max( mx, val[k]-val[k-1] );
                }

                //cout<<revx[i]<<" "<<revx[j]<<" "<<mx<<endl;

                ans = max( ans , mx * (revx[j]-revx[i]) );
            }
        }
        printf("Case %d: %d\n",kk,ans);

    }


    return 0;
}

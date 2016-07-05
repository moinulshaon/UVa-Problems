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

LL arr[1100];


struct node{
    int taken;
    LL max;
    bool operator < (const node & p)const{
        if (taken!= p.taken )taken<p.taken;
        else return max<p.max;
    }
}tt,xx;

int vis[1100];

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    while ( kase-- ){
        int n;
        scanf("%d",&n);

        for (int i=0;i<n;++i){
            scanf("%lld",&arr[i]);
        }

        priority_queue< node > q;
        tt.taken = 1 ;
        tt.max = arr[n-1];


        CLR(vis);

        int ans=0 ;

        q.push( tt );

        while ( !q.empty() ){
            tt= q.top();q.pop();
            if ( tt.taken>ans ){
                ans = tt.taken;
            }

            //cout<<tt.taken<<' '<<tt.max<<endl;

            if ( vis[ tt.taken ] > tt.max ){
                continue;
            }
            vis[ tt.taken ] = tt.max;

            for (int i=0;i<n;++i){
                if ( arr[i]<tt.max ){
                    xx.taken=tt.taken+1;
                    xx.max = min( arr[i+1]-arr[i], min( arr[i],tt.max-arr[i] ) );

                    if ( vis[ xx.taken ] < xx.max ){
                        q.push( xx );
                    }
                }else{
                    break;
                }
            }
        }


        printf("%d\n",ans);

    }


    return 0;
}

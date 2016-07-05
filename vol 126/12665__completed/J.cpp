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


const LL LIM=2000100000LL;
vector< pair<LL,LL> >  perfect;


int main(){
    FRO

    for (LL i=1;i*i*i<=LIM ;++i){
        perfect.PB( make_pair( i,i*i*i ) );
        //cout<<perfect[i-1].first<<' '<<perfect[i-1].second<<endl;
    }
    LL x,y;

    for (int kk=1;cin>>x>>y;++kk){

        LL cnt=0;
        for (int i=0;i<perfect.size();++i){
            for (int j=i;j<perfect.size();++j){
                if ( x<=perfect[i].first && y>=perfect[i].first
                    && x<=perfect[j].first && y>=perfect[j].first
                    && (perfect[i].second+perfect[j].second)%10==3
                    && x<=(perfect[i].second+perfect[j].second-3)/10
                    && y>=(perfect[i].second+perfect[j].second-3)/10 ){
                    cnt+=( i==j )?1:2 ;
                    //printf("%lld %lld\n",perfect[i].first,perfect[j].first);
                }
            }
        }
        printf("Case %d: %lld\n",kk,cnt);
    }

    return 0;
}

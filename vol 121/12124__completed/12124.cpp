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

#define SIZE 1100

map<string,int> mp;
vector<pint> item[SIZE];
int cat;

int shaon( int x,int mn ){
    int cost=(1<<30);
    for (int i=0;i<item[x].size();++i){
        if ( item[x][i].second>=mn ){
            cost = min( cost , item[x][i].first );
        }
    }
    return cost;
}

bool check( int quality,int have ){

    for (int i=0;i<cat;++i){
        int save= shaon( i,quality );
        if ( save == (1<<30) )return false;
        have -= save;
    }
    return have>=0;
}

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    while ( kase-- ){
        string sa,sb;
        int p,q;

        mp.clear();
        int n,taka;
        scanf("%d %d",&n,&taka);

        for (int i=0;i<=n;++i){
            item[i].clear();
        }

        cat= 0;

        while ( n-- ){
            cin>>sa>>sb>>p>>q;
            if ( mp.find( sa )==mp.end() )mp[ sa ]=cat++;
            item[ mp[sa] ].PB( make_pair(p,q) );
        }

        int low = 0,high=(1<<30);
        int ans = -1;

        while ( low<=high ){
            int mid = (low+high)/2;
            if ( check( mid,taka ) ){
                ans = mid;
                low = mid+1;
            }else{
                high= mid-1;
            }
        }

        printf("%d\n",ans);
    }


    return 0;
}

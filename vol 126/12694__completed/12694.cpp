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

#define MP make_pair
#define X first
#define Y second

bool cmp( const pint&a,const pint&b ){
    return a.Y<b.Y;
}

pint tt[25];

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    while ( kase-- ){
        int n;

        int u,v;

        n=0;
        while ( scanf("%d %d",&u,&v) == 2 && (u+v) ){
            tt[n++]=MP( u,v );
        }

        sort( tt,tt+n ,cmp );

        int prv= -100;

        int ans = 0;
        for (int i=0;i<n;++i){
            if ( tt[i].first >=prv ){
                ans++;
                prv = tt[i].second;
            }
        }
        printf("%d\n",ans);

    }

    return 0;
}

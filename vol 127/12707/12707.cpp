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

#define SIZE 20100

pint p[SIZE];

bool cmp( const pint&a,const pint&b ){
    return a.second-a.first>b.second-b.first
}

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        int n;
        scanf("%d",&n);

        for (int i=0;i<n;++i){
            scanf("%d %d",&p[i].first,&p[i].second);
        }

        sort( p,p+n ,cmp );

        int le=(1<<29),ri= -100;

        int u,v;
        int ans = 0;
        for (int i=0;i<n;++i){
            scanf("%d %d",&u,&v);
            if ( u>le && v<ri ){
                //donothing
            }else{
                ++ans;
                le=min(  )
            }
        }

    }


    return 0;
}

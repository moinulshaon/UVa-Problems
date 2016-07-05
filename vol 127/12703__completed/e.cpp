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

vector<int> p;

bool prime[50];

mint mp0,mp1,tmp;

void func0( int x ){

    for (int i=0;p[i]*p[i]<= x; ++i){
        while ( x%p[i] == 0 ){
            mp0[ p[i] ]++;
            x/=p[i];
        }
    }
    if ( x!=1 ){
        mp0[x]++;
    }
}

void func1( int x ){

    for (int i=0;p[i]*p[i]<= x; ++i){
        while ( x%p[i] == 0 ){
            mp1[ p[i] ]++;
            x/=p[i];
        }
    }
    if ( x!=1 ){
        mp1[x]++;
    }
}

int main(){

    for (int i=2;i<10;++i){
        if ( !prime[i] ){
            for (int j=i+i;j<50;j+=i ){
                prime[j] =true;
            }
        }
    }
    for (int i=2;i<50;++i){
        if ( !prime[i] ){
            p.PB( i );
        }
    }

    int kase;
    scanf("%d",&kase);

    while ( kase-- ){

        int a,b,n;

        scanf("%d %d %d",&n,&a,&b);

        mp0.clear();
        mp1.clear();

        func0( a );
        func1( b );

        for (int i=2;i<=n;++i){
            tmp.clear();

            for ( mint::iterator it= mp0.begin() ;it != mp0.end();++it){
                tmp[ it->first ] += it->second;
            }

            for ( mint::iterator it= mp1.begin() ;it != mp1.end();++it){
                tmp[ it->first ] += it->second;
            }


            mp0=mp1;
            mp1=tmp;
        }

        for ( mint::iterator it= mp1.begin() ;it != mp1.end();++it){
            printf("%d %d\n",it->first,it->second);
        }
        printf("\n");

    }

    return 0;
}

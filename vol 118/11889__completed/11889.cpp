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

#define SIZE 3200

bool prime[SIZE];
vector<int> p;

map<int,int> mp;

void func( int x,char flag ){

    int cnt;
    for (int i=0;p[i]*p[i]<=x;++i){
        if ( x%p[i] == 0 ){
            cnt = 0;
            while ( x%p[i] == 0 ){
                x/=p[i];
                cnt++;
            }
            if ( flag ){
                mp[ p[i] ] = cnt;
            }else{
                if ( cnt== mp[ p[i] ] ){
                    mp[ p[i] ] = 0;
                }
            }
        }
    }

    if ( x!= 1 ){
        if ( flag ){
            mp[ x ] += 1;
        }else{
            if ( mp[x] == 1 ){
                mp[x] = 0;
            }
        }
    }

}

int main(){

    FRO

    for (int i=2;i<=60;++i){
        if ( !prime[i] ){
            for (int j=i+i;j<SIZE;j+=i){
                prime[j] = true;
            }
        }
    }

    for (int i=2;i<SIZE;++i){
        if ( !prime[i] ){
            p.PB( i );
        }
    }

    int kase;
    scanf("%d",&kase);

    while ( kase-- ){
        int a,c;
        scanf("%d %d",&a,&c);
        if ( c%a != 0 ){
            printf("NO SOLUTION\n");
        }else{
            mp.clear();

            func( c,1 );
            func( a,0 );

            int ans = 1;
            for (  mint::iterator it= mp.begin();it != mp.end(); ++it ){
                while ( it->second > 0 ){
                    ans*=it->first;
                    it->second--;
                }
            }

            printf("%d\n",ans);

        }
    }

    return 0;
}

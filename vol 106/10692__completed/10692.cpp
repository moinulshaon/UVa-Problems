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

#define SIZE 11000

bool prime[SIZE];
int phi[SIZE];


int BigMod ( int a, int p, int m ){
    int res = 1;
    int x = a;

    while ( p ){
        if ( p & 1 ){
            res = ( res * x ) % m;
        }
        x = ( x * x ) % m;
        p = p >> 1;
    }
    return res % m;
}


int func( int cnt,int mod ){



    int tmp;
    scanf("%d",&tmp);

    if ( cnt==1 )return tmp%mod;


    return BigMod( tmp,phi[mod] +  func( cnt-1,phi[mod] )%phi[mod] , mod );

}

int main(){

    FRO

    for (int i=2;i<SIZE;++i){
        prime[i]=true;
        phi[i]=i;
    }
    phi[1]=1;
    for (int i=2;i<SIZE;++i)
        if (prime[i]){
            phi[i]=i-1;
            for (int j=i*2;j<SIZE;j+=i){
                prime[j]=false;
                phi[j]=phi[j]/i*(i-1);
            }
        }


    int mod ;

    for (int kk=1; scanf("%d",&mod) == 1 ;++kk ){
        int cnt;
        scanf("%d",&cnt);


        printf("Case #%d: %d\n",kk,func( cnt,mod )%mod );

    }

    return 0;
}

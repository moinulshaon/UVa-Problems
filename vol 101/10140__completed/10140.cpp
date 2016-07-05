
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

#define SIZE 1000100

bool segment[SIZE];
vector<LL> v;
vector<LL> p;
bool prime[50000];

void segmented_sieve(LL a, LL b){

    v.clear();
    if ( b>=2 && a<=2 ){
        v.PB( 2 );
    }

    if(a<3) a = 3;
    if(a%2==0) a++;
    CLR(segment);
    for(int i=0; p[i]*p[i] <= b; i++) {
        LL j = p[i] * ( (a+p[i]-1) / p[i] );
        if(j%2==0) j += p[i];
        for(LL k=p[i]<<1; j<=b; j+=k){
            if(j!=p[i]) {
                segment[j-a]=true;
            }
        }
    }
    for(int i=0; i<=b-a; i+=2){
        if(!segment[i]){
            v.PB( i+a );
        }
    }

    if ( v.size()<2 ){
        printf("There are no adjacent primes.\n");
        return ;
    }

    LL mx= -(1<<29),mn=(1<<29);
    int ss1,ss2;
    for (int i=1;i<v.size();++i){
        if ( mx<v[i]-v[i-1] ){
            mx= v[i]-v[i-1];
            ss1= i;
        }
        if ( mn > v[i]-v[i-1] ){
            mn= v[i]-v[i-1];
            ss2= i;
        }
    }
    printf("%lld,%lld are closest, %lld,%lld are most distant.\n",v[ss2-1],v[ss2],v[ss1-1],v[ss1]);

    return ;
}


int main(){


    FRO

    prime[1]=prime[1]=true;
    for (int i=2;i<=225;++i){
        if ( !prime[i] ){
            for (int j=i+i;j<50000;j+=i){
                prime[j] =true;
            }
        }
    }

    for (int i=2;i<50000;++i){
        if ( !prime[i] ){
            p.PB( i );
        }
    }

    LL a,b;
    while ( scanf("%lld %lld",&a,&b) == 2 ){
        segmented_sieve( a,b );
    }


    return 0;
}

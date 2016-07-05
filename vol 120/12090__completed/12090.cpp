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


int Set(int N,int pos){
    return N=N | (1<<pos);
}
int Reset(int N,int pos){
    return N= N & ~(1<<pos);
}
bool Check(int N,int pos){
    return (bool)(N & (1<<pos));
}

#define N 3200000


int status[(N/32)+2];
vector<LL> pp;
void sieve()
{
     int i, j, sqrtN;
     sqrtN = int( sqrt( N ) );
     for( i = 3; i <= sqrtN; i += 2 )
     {
         if( Check(status[i>>5],i&31)==0)
         {
             for( j = i*i; j <= N; j += (i<<1) )
             {
                 status[j>>5]=Set(status[j>>5],j & 31)   ;
             }
         }
     }


    pp.PB(2);
     for(i=3;i<=N;i+=2)
         if( Check(status[i>>5],i&31)==0)
            pp.PB(i);
}

vector< pair<LL,int> > fac;

void func( LL x ){

    for (int i=0;pp[i]*pp[i]<=x;++i){
        if ( x%pp[i] == 0 ){
            int cnt=0;
            while ( x%pp[i]==0 ){
                x/=pp[i];
                cnt++;
            }
            fac.PB( make_pair(pp[i],cnt) );
        }
    }

    if ( x!=1 ){
        fac.PB( make_pair(x,1) );
    }

}

int main(){

    sieve();
    LL n;

    while ( scanf("%lld",&n)==1 ){
        if ( n==0 )break;
        fac.clear();
        func(n);

        vector<LL> div;
        div.PB(1);
        int ss=fac.size();

        //printf("ss %d\n",ss);

        for (int i=0;i<ss;++i){
            vector<LL> save;
            for (int j=0;j<div.size();++j){
                LL tmp=1;
                LL x;

                for (int k=1;k<=fac[i].second;++k){
                    tmp*= fac[i].first;
                    x= div[j]*tmp;
                    save.PB(x);
                }
            }
            //printf("inserting %d\n",save.size());
            div.insert( div.end(),save.begin(),save.end() );
        }
        //printf("sz %d\n",div.size());

        int ans=0;
        for (int i=1;i<div.size();++i){
            LL tt=n;
            //printf("%lld %lld\n",tt,div[i]);
            while ( tt%div[i] == 0 ){
                tt/=div[i];
                ans++;
            }
        }

        printf("%lld %d\n",n,ans);
    }


    return 0;
}

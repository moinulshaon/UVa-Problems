#include <cstdio>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

const int mod=1000000007;
vector<int> p;
typedef long long LL;

LL square(LL k){
    return k * k;
}

LL BigMod(LL a, LL n, LL p)
{
    if(n == 1)  return a % p;
    else if(n % 2 == 0)  return square(BigMod(a, n/2, p)) % p;
    else return ((square(BigMod(a, n/2, p))%p)*(a % p)) % p;
}


LL plusing( int x,map<int,int>& mp ,LL ans){

    for (int i=0;i<p.size() && p[i]*p[i]<=x && x;++i){
        int cnt=0;
        while( x%p[i] == 0 ){
            x/=p[i];
            cnt++;
        }
        if ( cnt ){
            ans= ( ans*BigMod( mp[ p[i] ] + 1 ,mod-2 ,mod ) )%mod;
            mp[ p[i] ]+=cnt;
            ans= ( ans*( mp[ p[i] ] + 1 ) )%mod;
        }
    }
    if ( x!=1  ){
        ans= ( ans*BigMod( mp[ x ] + 1 ,mod-2 ,mod ) )%mod;
        mp[ x ]++;
        ans= ( ans*( mp[ x ] + 1 ) )%mod;
    }
    return ans;
}

LL minusing( int x,map<int,int>& mp ,LL ans){

    for (int i=0;i<p.size() && p[i]*p[i]<=x && x;++i){
        int cnt=0;
        while( x%p[i] == 0 ){
            x/=p[i];
            cnt++;
        }
        if ( cnt ){
            ans= ( ans*BigMod( mp[ p[i] ] + 1 ,mod-2 ,mod ) )%mod;
            mp[ p[i] ] -=cnt;
            ans= ( ans*( mp[ p[i] ] + 1 ) )%mod;
        }
    }
    if ( x !=1 ){
        ans= ( ans*BigMod( mp[ x ] + 1 ,mod-2 ,mod ) )%mod;
        mp[ x ]--;
        ans= ( ans*( mp[ x ] + 1 ) )%mod;
    }
    return ans;
}


#define SIZE 1100
bool prime[SIZE];

template<class T>
    inline T fastIn() {
    register char c=0;
    register T a=0;
    bool neg=false;
    while ( c<33 ) c=getchar();
    while ( c>33 ) {
        if ( c=='-' ) {
            neg=true;
        } else {
            a= ( a*10 ) + ( c-'0' );
        }
        c=getchar();
    }
    return neg?-a:a;
}


int main(){
    freopen("in.txt","r",stdin);
    for (int i=2;i<=33;++i){
        if ( !prime[i] ){
            for ( int j=2*i;j<SIZE;j+=i ){
                prime[j]=true;
            }
        }
    }

    for (int i=2;i<SIZE;++i){
        if ( !prime[i] ){
            p.push_back(i);
        }
    }
    int kase,x,n;
    kase=fastIn<int>();

    for (int kk=1;kase--;++kk){
        n=fastIn<int>();
        map<int,int> mp;

        LL ans=0;
        LL tmp=1;

        while(n--){
            x=fastIn<int>();
            if ( x>=0 ){
                tmp=plusing( x,mp,tmp );
                ans=( ans+  tmp )%mod;
            }
            else{
                tmp=minusing(-x,mp ,tmp );
                ans=( ans+ tmp )%mod;
            }
            //printf("%d %d %d\n",x,ans,tmp);
        }
        printf("Case %d: %lld\n",kk,ans);
    }
    return 0;
}

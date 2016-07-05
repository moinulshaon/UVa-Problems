#include <cstdio>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

const int mod=1000000007;
vector<int> p;

int plusing( int x,map<int,int>& mp ,int ans){

    for (int i=0;i<p.size() && p[i]*p[i]<=x && x;++i){
        int cnt=0;
        while( x%p[i] == 0 ){
            x/=p[i];
            cnt++;
        }
        if ( cnt ){
            if ( mp.find( p[i] ) == mp.end() ){
                cnt++;
            }
            mp[ p[i] ]+=cnt;
            ans= ( ans * cnt )%mod;
        }
    }
    if ( x!=1  ){
        int cnt=1;
        if ( mp.find( x ) == mp.end() ){
            cnt++;
        }
        mp[ x ]+=cnt;
        ans= ( ans * cnt )%mod;
    }
    return ans;
}

int minusing( int x,map<int,int>& mp ,int ans){

    for (int i=0;i<p.size() && p[i]*p[i]<=x && x;++i){
        int cnt=0;
        while( x%p[i] == 0 ){
            x/=p[i];
            cnt++;
        }
        if ( cnt ){
            mp[ p[i] ] -= cnt;
            ans= ( ans * cnt )%mod;
        }
    }
    if ( x !=1 ){
        ans= ( ans/( mp[ x ] + 1 ) )%mod;
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

        int ans=0;
        int tmp=1;

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
            printf("%d %d %d\n",x,ans,tmp);
        }
        printf("Case %d: %d\n",kk,ans);
    }
    return 0;
}

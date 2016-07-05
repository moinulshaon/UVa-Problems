#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define SIZE 1000000

bool prime[SIZE];
vector<int>p;


void div( int x,vector<int>& v){

    for (int i=0;p[i]*p[i]<=x;++i){
        while( x%p[i]==0 ){
            x/=p[i];
            v.push_back( p[i]-1 );
        }
    }
    if ( x!=1 ){
        v.push_back( x-1 );
    }
}

long long lim=1000000000000001LL;

int main(){
    freopen("input.txt","r",stdin);
    prime[0]=prime[1]=false;
    for (int i=2;i<SIZE;++i){
        prime[i]=true;
    }
    for (int i=2;i<=1000;++i){
        if ( prime[i] ){
            for (int j=2*i;j<SIZE;j+=i){
                prime[j]=false;
            }
        }
    }
    for (int i=2;i<SIZE;++i){
        if ( prime[i] ){
            p.push_back(i);
        }
    }


    int cc=1;
    int n;
    while( scanf("%d",&n)==1 && n ){
        vector<int> v;
        div(n,v);
        sort(v.begin(),v.end());

        long long ans=1;

        for(int j=0,i=v.size()-1;i>=0 && ans<lim && ans>0 ;--i,++j){
            ans*= (long long)pow(p[j] , v[i] );
        }
        printf("Case %d: ",cc++);
        if ( ans<0 || ans>lim )
            printf("Impossible\n");
        else
            printf("%lld\n",ans);
    }
    return 0;
}

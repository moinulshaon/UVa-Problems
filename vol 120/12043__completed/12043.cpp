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

#define SIZE 100100
LL sum[SIZE];
int dev[SIZE];

vector<int> pp;
bool prime[1000];

void func( int x ){

    int shaon=x,cnt,dd=1;
    LL ss=1,tmp;
    for (int i=0;pp[i]*pp[i]<=x;++i){
        if ( x%pp[i] == 0 ){
            cnt=0;
            tmp=1;
            while ( x%pp[i]==0 ){
                tmp*=pp[i];
                cnt++;
                x/=pp[i];
            }
            dd*=(cnt+1);
            ss*=( tmp*pp[i]-1 )/(pp[i]-1);
        }

    }
    //cout<<"1. "<<x<<ss<<' '<<dd<<endl;
    if(  x!= 1 ){
        dd*=2;
        ss*=(LL(x)*x-1)/( x-1 );
    }
    //cout<<"2. "<<ss<<' '<<dd<<endl;
    dev[shaon]=dd;
    sum[shaon]=ss;
}

int main(){

    for (int i=2;i<35;++i){
        if ( !prime[i] ){
            for (int j=2*i;j<1000;j+=i){
                prime[j]=true;
            }
        }
    }

    for (int i=2;i<1000;++i){
        if ( !prime[i] ){
            pp.PB( i );
        }
    }



    for (int i=1;i<SIZE;++i){
        func(i);
    }




    int kase;
    scanf("%d",&kase);

    while ( kase-- ){
        int a,b,k;
        scanf("%d %d %d",&a,&b,&k);
        LL ans1=0,ans2=0;
        bool on=false;
        for (int i=a;i<=b;i+= ( on )?k:1 ){
            if ( on || i%k==0 ){
                ans1+= dev[i];
                ans2+= sum[i];
                //printf("%d %d\n",dev[i],sum[i]);
                on=true;
            }
        }

        printf("%lld %lld\n",ans1,ans2);
    }

    return 0;
}

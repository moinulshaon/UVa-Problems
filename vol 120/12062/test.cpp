#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<math.h>
#include<string.h>
#include<map>
#include<queue>
#include<stack>
#include<utility>
#include<stdlib.h>
#include<string>
#include<set>
#define rep(i,n) for(i=1;i<=n;i++)
#define FOR(i,n) for(i=0;i<n;i++)
#define si(i) scanf("%d",&i)
#define sii(i,j) scanf("%d %d",&i,&j)
#define siii(i,j,k) scanf("%d %d %d",&i,&j,&k)
#define INF 1e9
#define lld long long int
#define clr(a) memset(a,0,sizeof(a))
#define reset(a) memset(a,-1,sizeof(a))
#define FRO freopen("input.txt","r",stdin);
#define FROut freopen("ouput.txt","w",stdout);
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define ui unsigned int
#define came "came"
using namespace std;


#define N 10000
bool prime[N];
vector<int> v;
vector<int>s;
int siz;
bool f;
double r=log10(1e15);

void sieve()
{
    int i,j;
    int sq=sqrt(N);
    memset(prime,1,sizeof(prime));
    v.push_back(2);
    prime[0]=prime[1]=0;
    for(i=4;i<N;i+=2) prime[i]=false;
    for(i=3;i<=sq;i+=2)
    {
        if(prime[i])
        {
            for(j=i*i;j<N;j+=2*i)
            {
                prime[j]=false;
            }
            v.push_back(i);
        }
    }
    for(;i<N;i+=2)
    {
        if(prime[i])
        {
            v.push_back(i);
        }
    }
}

lld memo[15][5005];

lld pwr(int b, int p)
{
    lld ret=1;
    int i;
    for(i=0;i<p && ret<=1e15;i++)
    {
        ret*=b;
    }
    return ret;
}

lld dp(int indx, int num)
{
    if(num==1)
    {
        return 1;
    }
    else if(memo[indx][num]!=-1)
    {
        return memo[indx][num];
    }
    else
    {
        int i;
        lld mult;
        lld ret=1e16,x;
        double p,q;
        for(i=2;i<=num;i++)
        {
            if(num%i==0)
            {
                mult=pwr(v[indx],i-1);
                p=log10(mult);
                x=dp(indx+1,num/i);
                q=log10(x);
                if(p+q>r)
                {
                    ret=min(ret,1e16);
                }
                else
                {
                    ret=min(ret,x*mult);
                }
            }
        }
        return memo[indx][num]=ret;
    }
}

int main()
{
    FRO
    //freopen("out.txt","w",stdout);
    sieve();
    int ca=1;
    int n;
    int sz=v.size();
    while(scanf("%d",&n)==1 && n){
        printf("Case %d: ",ca++);
        reset(memo);
        lld ans=dp(0,n);
        if(ans>1e15)
        {
            printf("Impossible\n");
        }
        else
        {
            printf("%lld\n",ans);
        }
    }
    return 0;
}

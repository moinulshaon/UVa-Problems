///     Raihan Ruhin
///     CSE, Jahangirnagar University.
///     Dhaka-Bangladesh.
///     id: raihanruhin (topcoder / codeforces / codechef / hackerrank / uva / uvalive), 3235 (lightoj)
///     mail: raihanruhin@ (yahoo / gmail / facebook)
///     blog: ruhinraihan.blogspot.com

#include<bits/stdc++.h>
using namespace std;

#define SET(a) memset(a,-1,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
#define PI acos(-1.0)

#define MOD 1000000007
#define MX 310

int divisors[MX], divisorsMultiple[MX];

void seive()
{
    for(int i=1; i<MX-5; i++) divisors[i]=0, divisorsMultiple[i]=1;
    for(int i=2; i<MX-5; i++)
    {
        if(!divisors[i])
            for(int j=i; j<MX-5; j+=i)
                divisors[j]++, divisorsMultiple[j]*=i;
    }
    return;
}

int func(int m, int n)
{
    if(n>m) swap(n,m);
    int ans=n*m;
    for(int i=2; i<=n; i++)
        if(divisorsMultiple[i]==i)
        {

            int x=n/i, y=m/i;
            int tmp=x*y;
            if(divisors[i]%2) ans-=tmp;
            else ans+=tmp;
        }
    if(!n || !m) ans=0;
    //else if(!n || !m) ans=1;
return ans;
}

int road[310][310];
void precal()
{
    for(int i=0;i<=300;i++)
            for(int j=0;j<=300;j++)
                road[i][j]=func(i, j);
return;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    int kk=1, tc;
    int n, m;
    seive();
    precal();
    while(cin>>m>>n)
    {
        if(!m || !n) return 0;
        m--;
        n--;
        int tot=0;
        for(int i=0;i<=m;i++)
            for(int j=0;j<=n;j++)
                //tot+=(func(m-i, n-j)-func((m-i)/2, (n-j)/2));
                tot+=road[m-i][n-j]-road[(m-i)/2][(n-j)/2];
        tot*=2;
        cout<<tot<<"\n";
    }

    return 0;
}

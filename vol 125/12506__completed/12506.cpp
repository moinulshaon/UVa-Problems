#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
#include<list>
#include<iterator>

using namespace std;

#define Limit 100005
#define FRO freopen("in.txt","r",stdin);
#define FRU freopen("out.txt","w",stdout);

#define SET(a) memset(a,-1,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
#define i64 long long
//#deinfe i64 __int64
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define infinity 2147483647
#define pi acos(-1.0)
#define eps 1e-9



#define foreach(i,n) for(__typeof((n).begin())i =(n).begin();i!=(n).end();i++)


template< class T > T sqr(T n) { return n*n; }
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template< class T > T Max(T a, T b) { return a>b?a:b; }
template< class T > T Min(T a, T b) { return a<b?a:b; }
template< class T > T abs(T a) { return a>0?a:-a; }

//const int row[]={-1, -1, -1,  0,  0,  1,  1,  1};  // Kings Move
//const int col[]={-1,  0,  1, -1,  1, -1,  0,  1};  // Kings Move
//const int row[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int col[]={-1,  1, -2,  2, -2,  2, -1,  1};  // Knights Move
//const int row[]={-1,0,0,1,0};
//const int col[]={0,-1,1,0,0};

int n,m,kk;
string s[1003];
int lcp[1003],lcp_r[1003];

bool cmp(string a,string b)
{
    return a<b;
}
void count_lcp()
{
    int i,j,k;
    for(i=1;i<n;i++)
    {
        j=0;
        while(s[i][j]==s[i-1][j])j++;
        lcp[i]=j;
    }
}

int main()
{
   // FRO
    int tc,t,i,j,k,a,b,c,d;
    cin>>tc;
    for(t=1;t<=tc;t++)
    {
        cin>>n;
        CLR(lcp);
        for(i=0;i<n;i++)cin>>s[i];
        sort(s,s+n,cmp);
        count_lcp();
  //      for(i=0;i<n;i++)cout<<lcp[i]<<endl;
        int ans=0;
        for(i=1;i<n;i++)ans+=Max(lcp[i],lcp[i-1])+1;
        ans+=lcp[n-1]+1;

        cout<<ans<<endl;
    }

    return 0;
}

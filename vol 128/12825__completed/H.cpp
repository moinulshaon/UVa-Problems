#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<utility>
#include<string>
#define ll long //long
#define ull unsigned ll
#define pb push_back
#define mp make_pair
#define ii pair<ll,ll>
#define vi vector<ll>
#define vvi vector<vector<ll> >
#define vvii vector<vector< ii > >
using namespace std;

ll Min(ll i,ll j){return i<j?i:j;}
ll Max(ll i,ll j){return i>j?i:j;}

string ss;
int dp[4][4][1005];
int rght[4]={1,2,3,0};
int lft[4]={3,0,1,2};
int op[4]={2,3,0,1};

int main()
{
    int n,i,j,k;
    while(cin>>ss)
    {
        n=ss.size();
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++) dp[i][j][n]=0;
        }
        for(i=n-1;i>=0;i--)
        {
            for(j=0;j<4;j++)
            {
                for(k=0;k<4;k++)
                {
                    if(ss[i]=='L' ) dp[k][j][i]=dp[k][lft[j]][i+1];
                    if(ss[i]=='R' ) dp[k][j][i]=dp[k][rght[j]][i+1];
                    else if(ss[i]=='F')
                    {
                        if(j==k) dp[k][j][i]=1+dp[k][j][i+1];
                        else if(j==op[k]) dp[k][j][i]=dp[k][j][i+1]-1;
                        else dp[k][j][i]=dp[k][j][i+1];
                    }
                    else
                    {
                        int a=max(dp[k][lft[j]][i+1],dp[k][j][i]=dp[k][rght[j]][i+1]),b;
                        if(j==k) b=1+dp[k][j][i+1];
                        else if(j==op[k]) b=dp[k][j][i+1]-1;
                        else b=dp[k][j][i+1];
                        dp[k][j][i]=max(a,b);
                    }
                }
            }
        }
        printf("Case %d: %d %d %d %d",-dp[0][2][0],dp[2][2][0],-dp[3][2][0],dp[1][2][0]);
    }
    return 0;
}

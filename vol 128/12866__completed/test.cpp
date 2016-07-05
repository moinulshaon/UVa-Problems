#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int P,num[66];
ll dp[66][2][66];
int vt, vis[66][2][66];
ll rec(int pos, bool eq, int one)
{
    if (one == 0) return 1;
    if (pos == P) return 0;
    ll &ret = dp[pos][eq][one];
    if (vis[pos][eq][one] == vt) return ret;
    vis[pos][eq][one] = vt;
    ret = 0;
    ret = rec(pos+1, eq&(num[pos]==0), one);
    if (!eq || num[pos]==1) ret += rec(pos+1, eq&(num[pos]==1), one-1);
    return ret;
}
ll cnt(ll N, int one)
{
    if (one == 0) return 1;
    if (N < 0) return 0;
    int i=0;
    while (N)
    {
        num[i++] = N%2;
        N /= 2;
    }
    reverse(num,num+i);
    P = i;
    ++vt;
    return rec(0, 1, one);
}
int main()
{

    freopen("in.txt","r",stdin);

    //printf("%llu\n", cnt(3,1));
    ll low,high,c,ans;
    int one;
    while (scanf("%llu %llu", &low, &high) != EOF)
    {
        if (low == 0 && high == 0) break;
        ans = 0;
        if (low == 0)
        {
            ++ans;
            ++low;
        }
        for (one = 0; ((1LLU<<one)-1) <= high; ++one)
        {
            c = cnt(high,one) - cnt(low-1,one);
            //printf("\t\t%llu %llu\n", cnt(high,one), - cnt(low-1,one));
            ans += c * (1LLU<<one);
        }
        printf("%llu\n", ans);
    }
    return 0;
}

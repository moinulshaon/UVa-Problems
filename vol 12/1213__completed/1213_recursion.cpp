#include <cstdio>
#include <vector>

using namespace std;

bool prime[1121];
vector <int> p;
int dp[1121][15];
int psize;

int func(int n,int k)
{
    if (dp[n][k]==-1)
    {
        int tmp=0;
        for (int i=0;i<psize && n-p[i]>=0;++i)
        {
            tmp+=func(n-p[i],k-1);
        }
        return dp[n][k]=tmp;
    }
    else
        return dp[n][k];
}

int main()
{
    for (int i=2;i<1121;++i)
        prime[i]=true;

    for (int i=0;i<=33;++i)
        if (prime[i])
            for (int j=i*2;j<1121;j+=i)
                prime[j]=false;

    for (int i=2;i<1121;++i)
        if (prime[i])
            p.push_back(i);
    psize=p.size();

    for (int i=0;i<1121;++i)
        for (int j=0;j<15;++j)
            dp[i][j]=-1;

    for (int i=0;i<1121;++i)
            dp[i][0]=1;
    /*for (int k=0;k<psize;++k)
        for (int j=1121;j>=0;--j)
            for (int i=1;i<15;++i)
                if ( j-p[k]>=0 )
                    dp[j][i]+=dp[ j-p[k] ][i-1];*/


    int n,k;
    while (true)
    {
        scanf("%d %d",&n,&k);
        if (!n && !k)return 0;

        printf("%d\n",func(n,k) );
    }

}

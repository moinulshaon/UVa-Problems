#include <cstdio>
#include <vector>

using namespace std;

bool prime[1121];

int dp[1121][15];

int main()
{
    for (int i=2;i<1121;++i)
        prime[i]=true;

    for (int i=0;i<=33;++i)
        if (prime[i])
            for (int j=i*2;j<1121;j+=i)
                prime[j]=false;
    vector <int> p;
    for (int i=2;i<1121;++i)
        if (prime[i])
            p.push_back(i);
    int psize=p.size();

    dp[0][0]=1;
    for (int k=0;k<psize;++k)
        for (int j=1121;j>=0;--j)
            for (int i=1;i<15;++i)
                if ( j-p[k]>=0 )
                    dp[j][i]+=dp[ j-p[k] ][i-1];


    int n,k;
    while (true)
    {
        scanf("%d %d",&n,&k);
        if (!n && !k)return 0;

        printf("%d\n",dp[n][k] );
    }

}

#include <cstdio>
#include <algorithm>

using namespace std;


int coin[]={1,2,4,10,20,40};
int sz[6];
int result[150];
int dp[150];

int main()
{

    freopen("in.txt","r",stdin);

    while (true)
    {
        for (int i=0;i<6;++i)
            scanf("%d",&sz[i]);
        if (!sz[0] && !sz[1] &&!sz[2] &&!sz[3] &&!sz[4] &&!sz[5] )return 0;

        for (int i=1;i<=125;++i)
            result[i]=10000000;
        result[0]=0;

        for (int i=0;i<6;++i)
        {
            for (int j=0;j<sz[i];++j)
            {
                for (int k=125;k>=0;--k)
                {
                    if (k-coin[i]>=0)
                        result[k]=min(result[k],result[k-coin[i]]+1);
                }
            }
        }

        double in;
        scanf("%lf",&in);

        int input=in*20;

        for (int i=1;i<=125;++i)
            dp[i]=1000000;
        dp[0]=0;
        for (int i=0;i<6;++i)
            for (int j=0;j<=125;++j)
                if (j-coin[i]>=0)
                    dp[j]=min(dp[j],dp[j-coin[i]]+1);

        for (int i=0;input+i<=125;++i)
        {
            //printf("%d %d\n",result[input], dp[i]);
            if (result[input]>result[input+i] + dp[i] )
                result[input]=result[input+i] + dp[i];

        }


        printf("%3d\n",result[input]);
    }
}

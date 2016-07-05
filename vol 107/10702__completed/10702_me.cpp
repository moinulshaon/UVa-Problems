
#include <cstdio>
#define maxi(a,b) ( (a)>(b) )?(a):(b)
#define sz 110
#define INF 2147483647

int main()
{
    int c,s,nDest,intermidate;
    int G[sz][sz];
    int end[sz];
    int dp[sz][1100];

    while (true)
    {

        scanf("%d %d %d %d",&c,&s,&nDest,&intermidate);
        if (!c  && !s && !nDest && !intermidate)
            return 0;
        for (int i = 1; i <=c; i++)
            for (int  j = 1; j <= c; j++)
                scanf("%d",&G[i][j]);
        for (int  i = 0; i < nDest; i++)
            scanf("%d",&end[i]);

        for (int i = 0; i <= c; ++i)
            for (int j=0;j<intermidate;++j)
                dp[i][j]=-INF;
        for (int i = 0; i < nDest; i++)
            dp[end[i]][intermidate] = 0;
        for (int i = intermidate - 1; i >= 0; i--)
            for (int j = 1; j <=c; j++)
                for (int k = 1; k <= c; k++)
                    dp[j][i] = maxi(dp[j][i], G[j][k] + dp[k][i + 1]);
        printf("%d\n",dp[s][0]);
	}
}

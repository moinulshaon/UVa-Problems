#include <cstdio>
#include <cstring>

using namespace std;

long long  number[210];
long long  dp[210][210][22];
long long total,query,r,d;

long long  func(long long totake,long long sum,long long taken)
{
    //printf("%d %d %d\n",totake,taken,sum);
    sum=sum%d;
    if (sum<0)
        sum=d+sum;

    if (dp[totake][taken][sum]!=-1)return dp[totake][taken][sum];


    if (taken==r){
        if (sum==0)
            return 1;
        else
            return 0;
    }

    if (totake==total)
        return 0;
    //printf("saon\n");
    return dp[totake][taken][sum]=func( totake+1, sum+number[totake] ,taken+1)+func( totake+1, sum ,taken);
}


int main()
{
    freopen("in.txt","r",stdin);

    for (int kase=1;true;++kase)
    {
        scanf("%lld %lld",&total,&query);
        if (!total && !query)return 0;

        for (int i=0;i<total;++i)
            scanf("%lld",&number[i]);


        printf("SET %d:\n",kase);

        for (int qq=1;query--;++qq)
        {
            printf("QUERY %d: ",qq);

            scanf("%lld %lld",&d,&r);

            for (int i=0;i<=total;++i)
                for (int j=0;j<=total;++j)
                    for (int k=0;k<d;++k)
                        dp[i][j][k]= -1;

            printf("%lld\n",func(0,0,0));
        }
    }

}

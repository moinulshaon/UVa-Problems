#include <cstdio>
#include <algorithm>
#include <cstring>
#define sz 110

using namespace std;
double arr[sz];
int n,k;
double dp[100*100][sz];
bool vis[100*100][sz];
double func(double perc,int taken)
{
        if (taken==n+1)return 0;

        if (perc>50)return arr[0]/perc;

        if ( vis[int(perc*100+1e-6)][taken]  )return dp[int(perc*100+1e-6)][taken];

        double tt1=func(perc+arr[taken],taken+1);
        double tt2=func(perc,taken+1);

        vis[int(perc*100+1e-6)][taken]=true;

        return dp[int(perc*100+1e-6)][taken]=max(tt1,tt2);
}


int main(){

    freopen("in.txt","r",stdin);

    while (true){
        scanf("%d %d",&n,&k);
        if (!n && !k)return 0;

        for (int i=0;i<n;++i)
            scanf("%lf",&arr[i]);

        swap(arr[0],arr[k-1]);
        memset(vis,false,sizeof(vis));
        printf("%.2lf\n",func(arr[0],1)*100 );
    }
    return 0;
}

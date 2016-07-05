#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

LL arr[110][110];

LL func( int a,int b,int c,int d ){
    return (a-c+1)*(b-d+1);
}

int main(){
    freopen("in.txt","r",stdin);

    int n,m,kase,area;
    LL k,sum;
    scanf("%d",&kase);
    for (int kk=1;kase--;++kk){
        memset(arr,0,sizeof(arr));
        scanf("%d %d %lld",&n,&m,&k);

        for (int i=1;i<=n;++i){
            for (int j=1;j<=m;++j){
                scanf("%lld",&arr[i][j]);
                arr[i][j]+=arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
                //printf("%5d",arr[i][j]);
            }
            //printf("\n");
        }
        //printf("%lld\n",k);
        LL ans= -1 ,taka;
        for (int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                for (int p=i;p<=n;++p){
                    for (int q=j;q<=m;++q ){
                        sum=arr[p][q]-arr[i-1][q]-arr[p][j-1]+arr[i-1][j-1];
                        //printf("%lld\n",sum);
                        if ( sum<=k ){
                            area=func(p,q,i,j);
                            //printf("%lld\n",area);
                            if ( area>ans ){
                                ans=area;
                                taka=sum;
                            }else if ( area==ans ){
                                taka=min(taka,sum);
                            }
                        }
                    }
                }
            }
        }
        if ( ans==-1 ){
            ans=0;
            taka=0;
        }
        printf("Case #%d: %lld %lld\n",kk,ans,taka);
    }
    return 0;
}

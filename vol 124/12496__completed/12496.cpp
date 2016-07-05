#include <cstdio>
#include <cstring>


using namespace std;



int arr[210][210];

int func( int a,int b,int c,int d ){
    return (a-c+1)*(b-d+1);
}

int gcd(int a,int b)
{
    int temp=a;
    while (b!=0)
    {
        temp=b;
        b=a%b;
        a=temp;
    }
    return temp;

}


int main(){
    //freopen("in.txt","r",stdin);

    int n,m,kase,area;
    int k,sum;
    scanf("%d",&kase);
    for (int kk=1;kase--;++kk){
        memset(arr,0,sizeof(arr));
        scanf("%d %d %d",&n,&m,&k);

        for (int i=1;i<=n;++i){
            for (int j=1;j<=m;++j){
                scanf("%d",&arr[i][j]);
                arr[i][j]+=arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
                //printf("%5d",arr[i][j]);
            }
            //printf("\n");
        }
        //printf("%lld\n",k);
        int area= 0 ,taka;
        for (int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){

                int pc=m+1;
                int limn=n,limm=m;


                for (int p=i;p<=limn;++p){
                    for (int q=j;q<=limm;++q ){
                        sum=arr[p][q]-arr[i-1][q]-arr[p][j-1]+arr[i-1][j-1];
                        //printf("%lld\n",sum);
                        if ( sum>=k ){
                            area+=(n-p+1)*(m-q+1);
                            //printf("%d %d %d %d %d %d\n",i,j,p,q,area,sum);
                            area-= (n-p+1)*(m-pc+1);
                            //printf("%d %d %d %d %d %d\n",i,j,p,q,area,sum);
                            pc=q;

                            limm=q-1;
                        }
                    }
                }
            }
        }

        int den=0;

        for (int i=1;i<=n;++i){
            for (int j=1;j<=m;++j){
                den+= (n-i+1)*(m-j+1);
            }
        }

        int dd=gcd(area,den);


        printf("Case %d: %d/%d\n",kk,area/dd,den/dd);
    }
    return 0;
}

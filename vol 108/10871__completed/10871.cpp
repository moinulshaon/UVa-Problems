#include <cstdio>
#include <cstring>

#define SIZE 100000001

bool prime[SIZE];

int arr[10100];
int save[10100];

int main(){



    prime[1]=prime[0]=true;
    for (int i=2;i<=1000;++i){
        if ( !prime[i] ){
            for (int j=2*i;j<SIZE;j+=i){
                prime[j]=true;
            }
        }
    }

    int n;
    int kase;
    scanf("%d",&kase);
    while( kase-- ){
        scanf("%d",&n);

        arr[0]=0;
        for (int i=1;i<=n;++i){
            scanf("%d",&arr[i]);
            save[i]=arr[i];
            arr[i]+=arr[i-1];
        }

        int ans= n+1;
        int ll,rr;
        for (int i=1;i<=n;++i){
            for (int j=i+1;j<=n && (j-i+1)<ans;++j){
                if ( !prime[ arr[j]-arr[i-1] ] ){
                    ans=j-i+1;
                    ll=i;
                    rr=j;
                }
            }
        }
        if ( ans>n ){
            printf("This sequence is anti-primed.\n");
        }else{
            printf("Shortest primed subsequence is length %d:",ans);

            while( ll<=rr ){
                printf(" %d",save[ll]);
                ll++;
            }
            printf("\n");
        }
    }
    return 0;
}


#include <cstdio>
#include <cstring>

using namespace std;

int arr[11000];

int main(){
    int n;
    while(scanf("%d",&n)==1){
        int sum=0;
        for (int i=0;i<n;++i){
            scanf("%d",&arr[i]);
            sum+=arr[i];
        }
        if ( sum%n ){
            printf("-1\n");
        }else{
            int ans=1,avr=sum/n;
            for (int i=0;i<n && arr[i]<avr;++i){
                ans+=avr-arr[i];
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}

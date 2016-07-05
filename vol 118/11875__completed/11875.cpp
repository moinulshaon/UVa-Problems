#include <cstdio>
#include <algorithm>

using namespace std;

int arr[100];

int main(){
    int kase,n;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d",&n);
        for (int i=0;i<n;++i){
            scanf("%d",&arr[i]);
        }
        sort(arr,arr+n);

        printf("Case %d: %d\n",kk,arr[n/2]);
    }
    return 0;
}

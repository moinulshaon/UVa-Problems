#include <cstdio>
#include <algorithm>

using namespace std;

int arr[110000];

#define INF 10000000

int main(){

    int n,s;

    while (scanf("%d %d",&n,&s)==2){
        for (int i=0;i<n;++i){
            scanf("%d",&arr[i]);
        }
        int left=0;
        int right=0;

        int sum=0;
        int mn=INF;
        while (right<n){

            while (right<n && ( sum+=arr[right++] ) <s )
                ;
            if ( sum>=s )
                mn=min(mn,right-left);
            while ( ( sum-=arr[left++] ) >s )
                mn=min(mn,right-left);
        }
        if (mn==INF)
            printf("0\n");
        else
            printf("%d\n",mn);
    }
    return 0;

}

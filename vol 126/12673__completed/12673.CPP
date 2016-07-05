#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <iostream>
#include <queue>
#include <climits>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

typedef pair<int,int> pint;
typedef map<int,int> mint;

#define SIZE 101000

int arr[SIZE];

int main(){

    int n,g;

    while ( scanf("%d %d",&n,&g)==2 ){
        int x,y;
        for (int i=0;i<n;++i){
            scanf("%d %d",&x,&y);
            arr[i]= y-x;
        }

        sort(arr,arr+n);

        int ans= 0;
        for (int i=0;i<n;++i){
            if ( arr[i]==0 ){
                if ( g>= 1 ){
                    g-= 1;
                    ans+= 3;
                }else{
                    ans++;
                }
            }else if (arr[i]>0){
                if ( g>= arr[i]+1 ){
                    g-= arr[i]+1;
                    ans+= 3;
                }else if ( g == arr[i] ){
                    g-= arr[i];
                    ans++;
                }
            }else{
                ans+= 3;
            }
        }

        printf("%d\n",ans);
    }


    return 0;
}

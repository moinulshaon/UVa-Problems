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

char arr[200][15];

int main(){

    FRO

    int b,n;

    while ( scanf("%d %d",&b,&n) == 2 && (b+n) ){

        for (int i=0;i<n;++i){
            scanf("%s",arr[i]);
        }

        int ans = 0;
        for (int i=0;i<n;++i){
            for (int j=0;j<n;++j){
                if ( i==j )continue;
                int cnt = 0;
                for (int k=0;k<b;++k){
                    cnt += ( arr[i][k] == arr[j][k] );
                }
                ans = max( ans, cnt+1 );
            }
        }
        printf("%d\n",ans);
    }


    return 0;
}

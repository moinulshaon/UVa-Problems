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

char arr[10000];

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int n;
        scanf("%d %s",&n,arr);

        int b=0,w=0,a=0;

        for (int i=0;i<n;++i){
            if ( arr[i] == 'B' ){
                b++;
            }else if ( arr[i] == 'W' ) {
                w++;
            }else if ( arr[i] == 'A' ) {
                a++;
            }
        }
        n-= a;

        int tie = n-w-b;

        printf("Case %d: ",kk);
        if ( n== 0 ){
            printf("ABANDONED\n");
        }else if ( b == n ){
            printf("BANGLAWASH\n");
        }else if ( w == n ){
            printf("WHITEWASH\n");
        }else if ( w==b ){
            printf("DRAW %d %d\n",w,tie);
        }else if ( b>w ){
            printf("BANGLADESH %d - %d\n",b,w);
        }else {
            printf("WWW %d - %d\n",w,b);
        }

    }


    return 0;
}

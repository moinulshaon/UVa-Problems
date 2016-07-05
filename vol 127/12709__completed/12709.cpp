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

int main(){

    FRO

    int n;
    while ( scanf("%d",&n)==1 && n ){
        int l,w,h,tmp= -(1<<29) ;

        int ans = 0;
        while ( n-- ){
            scanf("%d %d %d",&l,&w,&h);
            if ( h>tmp ){
                tmp= h ;
                ans = l*w*h;
            }else if ( h== tmp ){
                ans=max(ans,l*w*h);
            }
        }
        printf("%d\n",ans);
    }


    return 0;
}

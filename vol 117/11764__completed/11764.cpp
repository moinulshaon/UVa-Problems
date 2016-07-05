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

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int a,b,n;
        scanf("%d",&n);

        int ans1=0,ans2=0;
        for (int i=0;i<n;++i){
            scanf("%d",&a);
            if ( i ){
                if ( a>b ){
                    ans1++;
                }else if ( a<b ){
                    ans2++;
                }
            }
            b=a;
        }

        printf("Case %d: %d %d\n",kk,ans1,ans2);
    }


    return 0;
}

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

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

int t,h,loss;
int acorn[2010][2010];

int dp[2010];

int main(){
    FRO
    int a,b,kase;
    scanf("%d",&kase);

    while( kase-- ){
        scanf("%d %d %d",&t,&h,&loss);

        for (int i=0;i<=t;++i){
            for (int j=0;j<=h;++j){
                acorn[i][j]=0;
            }
        }

        for (int i=0;i<t;++i){
            scanf("%d",&a);
            while( a-- ){
                scanf("%d",&b);
                acorn[i][b]++;
            }
        }

        memset(dp,-1,sizeof(dp));

        for (int tree = 0; tree < t; tree++) // initialization
            dp[h] = max(dp[h], acorn[tree][h]);
        for (int height = h - 1; height >= 0; height--)
            for (int tree = 0; tree < t; tree++) {
                acorn[tree][height] += max(acorn[tree][height + 1],((height + loss <= h) ? dp[height + loss] : 0)); // best from tree at height + f
                dp[height] = max(dp[height], acorn[tree][height]); // update this too
            }
        printf("%d\n", dp[0]);
    }
    return 0;
}

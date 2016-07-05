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

#define X first
#define Y second

#define MP make_pair

#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)


typedef pair<int,int> pint;
typedef map<int,int> mint;

int main(){

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int n;
        scanf("%d",&n);

        int ans = 0;
        bool pos=true;
        int cnt = 0;
        char tmp[5];
        for (int i=0;i<n;++i){
            scanf("%s",tmp);
            if ( !pos )continue;
            if ( tmp[0] == 'W' ){
                cnt =0;
            }else{
                cnt++;
            }
            if ( cnt == 3 ){
                pos=false;
            }
            ans = i+1;
        }
        if ( !pos )printf("Case %d: %d\n",kk,ans);
        else printf("Case %d: Yay! Mighty Rafa persists!\n",kk);
    }


    return 0;
}

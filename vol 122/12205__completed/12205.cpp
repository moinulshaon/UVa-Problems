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

pint phone[10100];

int main(){

    FRO

    int n,q;
    while ( scanf("%d %d",&n,&q) == 2 && (n+q) ){
        int x,y;
        for (int i=0;i<n;++i){
            scanf("%d %d %d %d",&x,&y,&phone[i].first,&phone[i].second);
            phone[i].second+=phone[i].first;
        }

        while ( q-- ){
            scanf("%d %d",&x,&y);
            y+= x;
            int cnt = 0;
            for (int i=0;i<n;++i){
                if ( x<phone[i].second && y>phone[i].first ){
                    cnt++;
                }
            }
            printf("%d\n",cnt);
        }
    }

    return 0;
}

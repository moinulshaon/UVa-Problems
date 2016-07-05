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

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

typedef pair<int,int> pint;
typedef map<int,int> mint;

int main(){
    FRO

    int n;
    for (int kk=1;scanf("%d",&n)==1 && n;++kk){
        int tmp,cnt=0;

        while( n-- ){
            scanf("%d",&tmp);
            if ( tmp ){
                cnt++;
            }else{
                cnt--;
            }
        }
        printf("Case %d: %d\n",kk,cnt);
    }


    return 0;
}

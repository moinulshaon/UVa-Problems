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

int Set(int N,int pos){
    return N=N | (1<<pos);
}
int Reset(int N,int pos){
    return N= N & ~(1<<pos);
}
bool Check(int N,int pos){
    return (bool)(N & (1<<pos));
}

char arr[200][15];


int main(){

    FRO

    int b,n;

    while ( scanf("%d %d",&b,&n) == 2 && (b+n) ){

        for (int i=0;i<n;++i){
            scanf("%s",arr[i]);
        }

        int ans = n+1;

        for (int state= 0;state< (1<<b);++state ){

            int cnt = 0;
            for (int i=0;i<b;++i){
                cnt+= Check( state,i );
            }
            if ( cnt>=ans )continue;
            set<int> ss;
            for (int i=0;i<n;++i){
                int tmp = 0;
                for (int j=0;j<b;++j){
                    if ( Check( state, j ) && arr[i][j] == '1' ){
                        tmp= Set( tmp,j );
                    }
                }
                ss.insert( tmp );
            }
            if ( ss.size() == n ){
                ans = cnt;
            }
        }

        printf("%d\n",ans);
    }


    return 0;
}

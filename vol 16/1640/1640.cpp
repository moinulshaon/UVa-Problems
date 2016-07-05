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

struct tt{
    LL cnt[10];
}empty,zero;


tt dp[15];
bool vis[15];

tt shaon( int left ){

    if ( left ==0 ){
        return empty;
    }
    //cout<<"shaion "<<left<<endl;

    if ( vis[left]  )return dp[left];

    vis[left]=true;

    tt &ret = dp[left];

    for (int i=0;i<10;++i){
        ret.cnt[i]++;
        tt tmp = shaon( left-1 );
        for (int j=0;j<10;++j){
            ret.cnt[j] += tmp.cnt[j];
        }
    }
    return ret;
}

tt func( int x ){

    if ( x== 0 ){
        return zero;
    }

    char str[15];
    sprintf(str,"%d",x);;
    int len=strlen(str);

    tt ans;
    CLR(ans.cnt);

    for (int i=0;i<len;++i){
        int left = len-i;

        int lim = str[i]-'0';
        for (int j=0;j<lim;++j){
            tt tmp=shaon( left-1 );
            tmp.cnt[j]++;
            for (int k=0;k<10;++k){
                ans.cnt[k] += tmp.cnt[k];
                //cout<<tmp.cnt[k]<<endl;
            }
        }

        ans.cnt[lim]++;
    }
    return ans;
}

int main(){

    zero.cnt[0]++;

    int x,y;

    while ( scanf("%d %d",&x,&y) == 2 && (x+y) ){

        if ( x>y )swap(x,y);

        tt f= func(y);
        tt b= func(x-1);

        for (int i=0;i<10;++i){
            if ( i )printf(" ");
            printf("%d",f.cnt[i]);
        }printf("\n");

    }


    return 0;
}

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


#define LIM 92

int dp[11][LIM][LIM];
int k;

int shaon(int left,int sum,int digitsum){

    if ( left ==0 ){
        if ( sum==0 && digitsum==0 )return 1;
        else return 0;
    }

    int &ret=dp[left][sum][digitsum];

    if ( ret != -1 )return ret;

    ret = 0;
    for (int i=0;i<10;++i){
        ret+= shaon( left-1,(sum*10+i)%k,(digitsum+i)%k );
    }
    return ret;
}

int func( int x ){

    char str[15];
    sprintf(str,"%d",x);;
    int len=strlen(str);

    int ans = 0;
    int cum=0;
    int digitcum=0;
    for (int i=0;i<len;++i){
        int left = len-i;

        int lim = str[i]-'0';
        for (int j=0;j<lim;++j){
            ans+= shaon( left-1, (cum*10+j)%k ,(digitcum+j)%k  );
        }

        cum= ( cum*10+lim )%k;
        digitcum= ( digitcum+lim )%k;
    }
    return ans+shaon( 0,cum%k,digitcum%k );
}

int main(){

    int kase;
    scanf("%d",&kase);

    while (kase--){
        int a,b;
        scanf("%d %d %d",&a,&b,&k);
        if ( k>=LIM ){
            printf("0\n");
        }else{
            NEG(dp);
            printf("%d\n",func(b)-func(a-1));
        }
    }


    return 0;
}

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

typedef pair<LL,LL> pint;
typedef map<int,int> mint;

#define SIZE 255

char arr[SIZE];
int n;

pint dp[SIZE][60];

pint func( int totake,int nxt ){

    if ( totake == n )return make_pair( 0,1 );

    if ( dp[totake][nxt].first != -1 )return dp[totake][nxt];

    pint tmp= func( totake+1,nxt );

    if ( arr[totake]-'A'+1 >= nxt ){
        pint xx= func( totake+1, (arr[totake]-'A'+1)*5/4 + ( ( (arr[totake]-'A'+1)*5%4 ) != 0 )  );
        xx.first++;
        if (  xx.first>tmp.first ){
            tmp = xx;
        }else if ( xx.first == tmp.first ){
            tmp.second+= xx.second;
        }
    }
    return dp[totake][nxt] = tmp;
}

char tmp[SIZE];

int main(){

    FRO

    int kase;
    scanf("%d",&kase);
    gets(arr);

    while ( kase-- ){

        n=0;
        gets(arr);

        for (int i=0;arr[i];++i){
            if ( isalpha( arr[i] ) && isupper( arr[i] ) ){
                arr[n++]= arr[i];
            }
        }
        arr[n]= '\0';

        //printf("%s\n",arr);
        NEG(dp);
        sort( arr,arr+n );

        strcpy( tmp,arr );
        int cnt = 0;
        for (int i=0;i<n;++i){
            if ( i==0 || tmp[i] != tmp[i-1] ){
                arr[cnt++] = tmp[i];
            }
        }
        arr[cnt]= '\0';
        n= cnt;
        //printf("%s\n",arr);
        pint ans = func( 0,0 );

        printf("%lld %lld\n",ans.first,ans.second);
    }


    return 0;
}

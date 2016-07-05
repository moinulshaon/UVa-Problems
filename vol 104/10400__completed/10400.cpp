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

#define SIZE 102
#define LIM 32000
#define MID 33000

int arr[SIZE];
char dp[SIZE][2*33000];
int n,req;

char func( int totake,int val ){
    if ( totake==n ){
        return val == req;
    }

    if ( dp[totake][val+MID] !=  -1 )return dp[totake][val+MID];

    if ( arr[totake]+val>= -LIM && arr[totake]+val <= LIM && func( totake+1,val + arr[totake] ) ){
        return dp[totake][val+MID] = 1;
    }
    if ( val - arr[totake]>= -LIM && val - arr[totake] <= LIM
         && func( totake+1,val - arr[totake] ) ){
        return dp[totake][val+MID] = 2;
    }
    if ( val * arr[totake]>= -LIM && val * arr[totake] <= LIM
         && func( totake+1,val * arr[totake] ) ){
        return dp[totake][val+MID] = 3;
    }
    if (val%arr[totake] == 0 && val / arr[totake]>= -LIM && val / arr[totake] <= LIM
         && func( totake+1,val / arr[totake] ) ){
        return dp[totake][val+MID] = 4;
    }

    return dp[totake][val+MID]= 0;
}

void shaon( int totake,int val ){

    if( totake == n ){
        printf("=%d\n",req);
        return ;
    }


    char tmp=func( totake,val );
    if ( tmp== 1  ){
        if ( totake )
            printf("+");
        printf("%d",arr[totake]);
        shaon( totake+1 ,val + arr[totake] );
    }else if ( tmp== 2  ){
        if ( totake )
            printf("-");
        printf("%d",arr[totake]);
        shaon( totake+1 ,val - arr[totake] );
    }else if ( tmp== 3  ){
        if ( totake )
            printf("*");
        printf("%d",arr[totake]);
        shaon( totake+1 ,val * arr[totake] );
    }else if ( tmp== 4  ){
        if ( totake )
            printf("/");
        printf("%d",arr[totake]);
        shaon( totake+1 ,val / arr[totake] );
    }else {
        exit(5);
    }

}

int main(){
    FRO

    int kase;
    scanf("%d",&kase);

    while ( kase-- ){
        scanf("%d",&n);
        for (int i=0;i<n;++i){
            scanf("%d",&arr[i]);
        }

        NEG(dp);
        scanf("%d",&req);
        if ( func(0,0) ){
            shaon(0,0);
        }else{
            printf("NO EXPRESSION\n");
        }
    }


    return 0;
}


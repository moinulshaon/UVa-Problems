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

char str[110];

char board[110][110];

int dr[]={-1,0,1,0};
int dc[]={ 0,1,0,-1};

void func( int row,int col ){

    if ( row == 1 || col == 1 )return ;

    int dir = 1;
    int nowr = 0 , nowc = 0;
    int nxtr = 0 , nxtc = 0;

    for (int i=0;i<=row;++i)
        for (int j=0;j<=col;++j)
            board[i][j] = '\0';

    for (int i=0;str[i];++i){

        board[ nowr ][ nowc ] = str[i] ;

        if ( !str[i+1] )break;

        nxtr = nowr + dr[ dir ];
        nxtc = nowc + dc[ dir ];

        while ( nxtr >= row || nxtr <0 || nxtc>= col || nxtc<0 || board[ nxtr ][ nxtc ] != '\0' ){
            dir++;
            if ( dir==4 )dir = 0;

            nxtr = nowr + dr[ dir ];
            nxtc = nowc + dc[ dir ];
        }

        nowr=nxtr;
        nowc= nxtc;
    }

}

bool check( int row ,int col ){
    /*
    for (int i=0;i<10;++i){
        for (int j=0;j<10;++j){
            printf("%c",board[i][j]);
        }printf("\n");
    }
    */
    if ( row == 1 || col == 1 )return false;

    for (int i=0;i<col;++i){
        for (int j=1;j<row;++j){
            if ( board[j][i] != board[j-1][i] ){
                return false;
            }
        }
    }
    return true;
}

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%s",str);
        int len=strlen( str );

        int ans = (1<<29);
        for (int i=1;i*i<=len;++i){
            if ( len%i==0 ){
                func( i,len/i );
                if ( check(i,len/i) ){
                    ans = min( ans, i+len/i );
                }


                func( len/i , i );
                if ( check(len/i , i) ){
                    ans = min( ans, i+len/i );
                }
            }
        }

        if ( ans== (1<<29) )ans = -1;

        printf("Case %d: %d\n",kk,ans);

    }

    return 0;
}

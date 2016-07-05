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
#include <stack>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

typedef pair<int,int> pint;
typedef map<int,int> mint;


#define SIZE 2010


int height[SIZE];

int area[SIZE];

int row,col;
char board[SIZE][SIZE];

void calcle(){

    stack<int> stk;

    height[0]= -1;
    stk.push( 0 );
    for (int i=1;i<=col;++i){

        while ( height[ stk.top() ] >= height[i] ){
            stk.pop();
        }
        area[i] = ( i-stk.top() )* height[i];
        stk.push( i );
    }

}

void calcri(){

    stack<int> stk;

    height[col+1]= -1;
    stk.push( col+1 );
    for (int i=col;i>0;--i){

        while ( height[ stk.top() ] >= height[i] ){
            stk.pop();
        }
        area[i] += ( stk.top()-i-1 )* height[i];
        stk.push( i );
    }

}

int main(){

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d %d",&row,&col);


        int tmp,cc,xx;
        for (int i=1;i<=row;++i){
            scanf("%d %d",&tmp,&cc);
            int now = 1;
            while ( tmp-- ){
                scanf("%d",&xx);
                while(xx--){
                    board[i][now++]= cc;
                }
                cc = !cc;
            }
        }

        for (int i=0;i<= col+1; ++i){
            height[i] = 0;
        }

        int ans = 0;
        for (int i=1;i<=row;++i){

            for (int j=1;j<=col;++j){
                if ( board[i][j]  ){
                    height[j] = 0;
                }else{
                    height[j]++;
                }
            }

            calcle();
            calcri();

            for (int j=1;j<=col;++j){
                ans = max( ans , area[j] );
            }

        }

        printf("Case %d: %d\n",kk,ans);
    }


    return 0;
}

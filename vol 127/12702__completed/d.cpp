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

char board[105][105];
int row,col;

char over[12][12];
int n,m;

char ans[105][105];

int cr,cc;

void func( int x,int y ){
    //cout<<x<<' '<<y<<endl;
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            if ( i+x>=0 && i+x<row && j+y>=0 && j+y<col && over[i][j] == '1'){
                ans[i+x][j+y] = '1';
            }
        }
    }

}

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        printf("Case %d:\n",kk);

        scanf("%d %d",&row,&col);



        for (int i=0;i<row;++i){
            for (int j=0;j<col;++j){
                scanf("%1s",&board[i][j]);
                ans[i][j] = board[i][j];
                //printf("%c",board[i][j]);
            }
            //printf("\n");
        }

        scanf("%d %d",&n,&m);

        cr= floor( n/2 )+1e-6 ;
        cc= floor( m/2 )+1e-6 ;

        //cout<<cr<<' '<<cc<<endl;

        for (int i=0;i<n;++i){
            for (int j=0;j<m;++j){
                scanf("%1s",&over[i][j]);
            }
        }

        for (int i=0;i<row;++i){
            for (int j=0;j<col;++j){
                if ( board[i][j] == '1' ){
                    func(i-cr,j-cc);
                }
            }
        }

        for (int i=0;i<row;++i){
            for (int j=0;j<col;++j){
                if ( j )printf(" ");
                printf("%c",ans[i][j]);
            }
            printf("\n");
        }


    }


    return 0;
}

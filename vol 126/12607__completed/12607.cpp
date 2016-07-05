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

#define SIZE 103

int Set(int N,int pos){
    return N=N | (1<<pos);
}

char board[SIZE][SIZE];

int num[SIZE][SIZE];

bool vis[SIZE][SIZE][4][(1<<8)+3];

int row,col;
int mine;

struct tt{
    int x,y;
    int move;
    int state;
};

int bfs(){

    for (int i=0;i<row;++i){
        for (int j=0;j<col;++j){
            for (int k=0;k<4;++k){
                for (int m=0;m< (1<<mine) ;++m){
                    vis[i][j][k][m]=false;
                }
            }
        }
    }

    tt tmp,u;

    tmp.x=tmp.y = tmp.state = 0;
    tmp.move= 0;

    queue<tt> q;

    q.push( tmp );
    vis[ tmp.x ][tmp.y][ ( tmp.move+ board[ tmp.x ][ tmp.y ] )%4 ][ tmp.state ]=true;

    while ( !q.empty() ){

        tmp=q.front();q.pop();

        //printf("%d %d %d\n",tmp.x,tmp.y,tmp.move,(tmp.move+ board[ tmp.x ][ tmp.y ] )%4 );

        if ( ( tmp.move+ board[ tmp.x ][ tmp.y ] )%4 == 0  ){
            u.x=tmp.x-1;
            u.y=tmp.y;
            u.state=tmp.state;
            if ( num[u.x][u.y] ){
                u.state=Set(u.state, num[u.x][u.y] - 1 );
            }
            u.move=tmp.move+1;

            if ( u.x>=0 &&  ! vis[ u.x ][ u.y ][ ( u.move+ board[ u.x ][ u.y ] )%4 ][ u.state ] ){
                vis[ u.x ][ u.y ][ ( u.move+ board[ u.x ][ u.y ] )%4 ][ u.state ]=true;
                if ( u.x == row-1 && u.y==col-1 && u.state== (1<<mine)-1 ){
                    return u.move;
                }
                q.push(u);
            }
        }else if ( ( tmp.move+ board[ tmp.x ][ tmp.y ] )%4 == 1  ){
            u.x=tmp.x;
            u.y=tmp.y+1;
            u.state=tmp.state;
            if ( num[u.x][u.y] ){
                u.state=Set(u.state, num[u.x][u.y] - 1 );
            }
            u.move=tmp.move+1;

            if ( u.y<col &&  ! vis[ u.x ][ u.y ][ ( u.move+ board[ u.x ][ u.y ] )%4 ][ u.state ] ){
                vis[ u.x ][ u.y ][ ( u.move+ board[ u.x ][ u.y ] )%4 ][ u.state ]=true;
                if ( u.x == row-1 && u.y==col-1 && u.state== (1<<mine)-1 ){
                    return u.move;
                }
                q.push(u);
            }
        }else if ( ( tmp.move+ board[ tmp.x ][ tmp.y ] )%4 == 2  ){
            u.x=tmp.x+1;
            u.y=tmp.y;
            u.state=tmp.state;
            if ( num[u.x][u.y] ){
                u.state=Set(u.state, num[u.x][u.y] - 1 );
            }
            u.move=tmp.move+1;

            if ( u.x<row &&  ! vis[ u.x ][ u.y ][ ( u.move+ board[ u.x ][ u.y ] )%4 ][ u.state ] ){
                vis[ u.x ][ u.y ][ ( u.move+ board[ u.x ][ u.y ] )%4 ][ u.state ]=true;
                if ( u.x == row-1 && u.y==col-1 && u.state== (1<<mine)-1 ){
                    return u.move;
                }
                q.push(u);
            }
        }else if ( ( tmp.move+ board[ tmp.x ][ tmp.y ] )%4 == 3  ){
            u.x=tmp.x;
            u.y=tmp.y-1;
            u.state=tmp.state;
            if ( num[u.x][u.y] ){
                u.state=Set(u.state, num[u.x][u.y] - 1 );
            }
            u.move=tmp.move+1;

            if ( u.y>=0  &&  ! vis[ u.x ][ u.y ][ ( u.move+ board[ u.x ][ u.y ] )%4 ][ u.state ] ){
                vis[ u.x ][ u.y ][ ( u.move+ board[ u.x ][ u.y ] )%4 ][ u.state ]=true;
                if ( u.x == row-1 && u.y==col-1 && u.state== (1<<mine)-1 ){
                    return u.move;
                }
                q.push(u);
            }
        }

        if ( !vis[ tmp.x ][tmp.y][ ( tmp.move + board[ tmp.x ][ tmp.y ] +1  )%4 ][ tmp.state ] ){
            vis[ tmp.x ][tmp.y][ ( tmp.move + board[ tmp.x ][ tmp.y ] +1  )%4 ][ tmp.state ]=true;
            tmp.move++;
            q.push( tmp );
        }

    }
    return -1;
}

int main(){
    FRO

    while ( scanf("%d %d",&row,&col)==2 && (row+col) ){

        for (int i=0;i<row;++i){
            scanf("%s",board[i]);
            for (int j=0;j<col;++j){
                if ( board[i][j] =='N' ){
                    board[i][j]= 0;
                }else if ( board[i][j]=='E' ){
                    board[i][j]=1;
                }else if ( board[i][j]=='S' ){
                    board[i][j]=2;
                }else if ( board[i][j]=='W' ){
                    board[i][j]=3;
                }
            }
        }
        CLR(num);

        scanf("%d",&mine);
        int x,y;
        for (int i=1;i<=mine;++i){
            scanf("%d %d",&x,&y);
            num[x-1][y-1]= i;
        }

        printf("%d\n",bfs());

    }


    return 0;
}

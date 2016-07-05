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

#define SIZE 260

char board[SIZE][SIZE];

int row,col;

void color( int r1,int c1,int r2,int c2 ,char cc){

    for (int i=r1;i<=r2;++i){
        for (int j=c1;j<=c2;++j){
            board[i][j]=cc;
        }
    }
}

char save;
bool vis[SIZE][SIZE];

int dr[]={-1,0,1,0};
int dc[]={0,-1,0,1};
void flood( int r,int c ,char cc){

    vis[r][c]=true;
    board[r][c]=cc;

    int tr,tc;
    for (int i=0;i<4;++i){
        tr=r+dr[i];
        tc=c+dc[i];
        if ( tr>=0 && tr<row && tc>=0 && tc<col && board[tr][tc]==save && !vis[tr][tc] ){
            flood(tr,tc,cc);
        }
    }
}

int main(){
    FRO

    char ins[1000],tmp[1000];
    int x1,x2,y1,y2;

    while( scanf("%s",ins)==1 ){

        while(  ins[0]!='X' ){
            if ( ins[0]=='I' ){
                memset( board,'0',sizeof(board) );
                scanf("%d %d",&col,&row);
            }else if ( ins[0]=='C' ){
                memset( board,'0',sizeof(board) );
            }else if ( ins[0]=='L' ){
                scanf("%d %d %s",&x1,&y1,tmp);
                x1--,y1--;
                board[y1][x1]=tmp[0];
            }else if ( ins[0]=='V' ){
                scanf("%d %d %d %s",&x1,&y1,&y2,tmp);
                x1--,y1--,y2--;
                if ( y2<y1 )swap( y1,y2 );
                color( y1,x1,y2,x1 ,tmp[0]);
            }else if ( ins[0]=='H' ){
                scanf("%d %d %d %s",&x1,&x2,&y1,tmp);
                x1--,x2--,y1--;
                if ( x2<x1 )swap( x1,x2 );
                color( y1,x1,y1,x2 ,tmp[0]);
            }else if ( ins[0]=='K' ){
                scanf("%d %d %d %d %s",&x1,&y1,&x2,&y2,tmp);
                x1--,x2--,y1--,y2--;

                if ( y1>y2 )swap(y1,y2);
                if ( x1>x2 )swap(x1,x2);

                color(y1,x1,y2,x2,tmp[0]);
            }else if ( ins[0]=='F' ){
                scanf("%d %d %s",&x1,&y1,tmp);
                x1--,y1--;
                save=board[y1][x1];

                memset(vis,false,sizeof(vis));
                flood(y1,x1,tmp[0]);
            }else if ( ins[0]=='S' ){
                scanf("%s",tmp);
                printf("%s\n",tmp);
                for (int i=0;i<row;++i){
                    for (int j=0;j<col;++j){
                        printf("%c",board[i][j]);
                    }
                    printf("\n");
                }
            }else{
                gets(tmp);
            }
            scanf("%s",ins);
        }
    }
    return 0;
}

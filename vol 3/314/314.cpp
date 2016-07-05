#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

int row,col;
char mat[51][51];
bool vis[51][51][4];

struct tt{
    int r,c,dir,val;
}start,finish,tmp,an;

int BFS(){

    memset(vis,false,sizeof(vis));

    queue<tt> q;
    start.val=0;
    q.push(start);
    vis[start.r][start.c][start.dir%4]=true;

    bool found=false;
    int r,c;
    while (!q.empty()){

        tmp=q.front();q.pop();

        if ( tmp.r==finish.r && tmp.c==finish.c ){
            found=true;
            break;
        }
        if ( tmp.dir%4 ==3 ){
            for (int i=1;i<=3;++i){
                r=tmp.r+i;
                c=tmp.c;
                if ( r>=row || mat[r][c] )break;

                if ( vis[r][c][tmp.dir%4] ){
                    continue;
                }
                an.r=r;
                an.c=c;
                an.dir=tmp.dir;
                an.val=tmp.val+1;

                vis[an.r][an.c][an.dir%4]=true;

                q.push(an);

            }
        }else if ( tmp.dir%4 ==1 ){
            for (int i=1;i<=3;++i){
                r=tmp.r-i;
                c=tmp.c;
                if ( r<0 || mat[r][c] )break;

                if ( vis[r][c][tmp.dir%4] ){
                    continue;
                }
                an.r=r;
                an.c=c;
                an.dir=tmp.dir;
                an.val=tmp.val+1;

                vis[an.r][an.c][an.dir%4]=true;

                q.push(an);
            }
        }else if ( tmp.dir%4 == 0 ){
            for (int i=1;i<=3;++i){
                r=tmp.r;
                c=tmp.c+i;
                if ( c>=col || mat[r][c] )break;

                if ( vis[r][c][tmp.dir%4] ){
                    continue;
                }
                an.r=r;
                an.c=c;
                an.dir=tmp.dir;
                an.val=tmp.val+1;

                vis[an.r][an.c][an.dir%4]=true;

                q.push(an);
            }
        }else if ( tmp.dir%4 == 2 ){
            for (int i=1;i<=3;++i){
                r=tmp.r;
                c=tmp.c-i;
                if ( c<0 || mat[r][c] )break;

                if ( vis[r][c][tmp.dir%4] ){
                    continue;
                }
                an.r=r;
                an.c=c;
                an.dir=tmp.dir;
                an.val=tmp.val+1;

                vis[an.r][an.c][an.dir%4]=true;

                q.push(an);
            }
        }
        an.r=tmp.r;
        an.c=tmp.c;
        an.val=tmp.val+1;

        if ( !vis[an.r][an.c][(an.dir-1)%4] ){
            an.dir--;
            q.push(an);
            an.dir++;
        }
        if ( !vis[an.r][an.c][(an.dir+1)%4] ){
            an.dir++;
            q.push(an);
            an.dir--;
        }
    }
    if ( found )return tmp.val;
    else return -1;

}


int main(){
    freopen("in.txt","r",stdin);
    char line[10];

    while (true){
        scanf("%d %d",&row,&col);

        if ( !row && !col )return 0;

        for (int i=0;i<row;++i){
            for (int j=0;j<col;++j){
                scanf("%d",&mat[i][j]);
            }
        }
        scanf("%d %d %d %d",&start.r,&start.c,&finish.r,&finish.c);

        scanf("%s",line);

        start.dir=1000000;
        if ( line[0]=='e' ){
            start.dir+=0;
        }else if ( line[0]=='n' ){
            start.dir+=1;
        }else if ( line[0]=='w' ){
            start.dir+=2;
        }else if ( line[0]=='s' ){
            start.dir+=3;
        }

        printf("%d\n",BFS());

    }

}

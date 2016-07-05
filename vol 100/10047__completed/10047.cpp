#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

char mp[30][30];

const int startingDir=1000000;

bool vis[30][30][4][5];
struct pos{
    int r,c,step,dir,turns;
}start,end,tmp,tt;
int row,col;

int BFS(){

    queue<pos> q;
    q.push(start);
    vis[ start.r ][ start.c ][start.dir%4 ][start.step%5]=true;
    int r,c;
    while ( !q.empty() ){
        tmp=q.front();
        q.pop();

        //printf("%d %d %d %d\n",tmp.r,tmp.c,tmp.step,tmp.turns,tmp.dir%4);

        if ( tmp.c==end.c && tmp.r==end.r && tmp.step%5 == 0 ){
            //printf("%d %d",tmp.step,tmp.turns);
            return tmp.step+tmp.turns;
        }

        if ( tmp.dir%4==0 ){
            r=tmp.r-1;
            c=tmp.c;
        }else if( tmp.dir%4==1 ){
            r=tmp.r;
            c=tmp.c-1;
        }else if ( tmp.dir%4==2 ){
            r=tmp.r+1;
            c=tmp.c;
        }else{
            r=tmp.r;
            c=tmp.c+1;
        }

        if( r>=0 && r<row && c>=0 && c<col && mp[r][c]!='#' ){
            tt.r=r;
            tt.c=c;
            tt.dir=tmp.dir;
            tt.step=tmp.step+1;
            tt.turns=tmp.turns;
            vis[ tt.r ][ tt.c ][ tt.dir%4 ][tt.step%5]=true;

            q.push(tt);
        }

        if( !vis[ tmp.r ][tmp.c][ (tmp.dir+1)%4 ][tmp.step%5] ){
            tt.r=tmp.r;
            tt.c=tmp.c;
            tt.dir=tmp.dir+1;
            tt.step=tmp.step;
            tt.turns=tmp.turns+1;
            vis[ tt.r ][ tt.c ][ tt.dir%4 ][tt.step%5]=true;

            q.push(tt);
        }
        if( !vis[ tmp.r ][tmp.c][ (tmp.dir-1)%4 ][tmp.step%5] ){
            tt.r=tmp.r;
            tt.c=tmp.c;
            tt.dir=tmp.dir-1;
            tt.step=tmp.step;
            tt.turns=tmp.turns+1;
            vis[ tt.r ][ tt.c ][ tt.dir%4 ][tt.step%5]=true;

            q.push(tt);
        }

    }
    return -1;
}


int main(){

    freopen("in.txt","r",stdin);

    for (int kk=1;true;++kk){
        scanf("%d %d",&row,&col);

        if ( ! row && !col)return 0;

        if (kk!=1)printf("\n");
        printf("Case #%d\n",kk);
        start.step=0;
        start.dir=startingDir;
        start.turns=0;

        for (int i=0;i<row;++i){
            scanf("%s",mp[i]);

            for (int j=0;j<col;++j){
                if ( mp[i][j]=='S' ){
                    start.r=i;
                    start.c=j;
                }else if ( mp[i][j]=='T' ){
                    end.r=i;
                    end.c=j;
                }
            }
        }
        memset(vis,false,sizeof(vis));
        int rr=BFS();

        if(rr== -1){
            printf("destination not reachable\n");
        }else{
            printf("minimum time = %d sec\n",rr);
        }

    }

}

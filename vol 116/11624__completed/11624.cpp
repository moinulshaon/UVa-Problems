#include <cstdio>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;
#define INF 1000000000

char mp[1010][1010];
int fire[1010][1010];
struct tt{
    int r,c,val;
}tmp,joe,ff;

int row,col;

queue< tt > q;

int dc[]={-1,0,1,0};
int dr[]={0,1,0,-1};

void BFSfire(){
    int r,c;
    while ( !q.empty() ){
        tmp=q.front();
        q.pop();

        for (int i=0;i<4;++i){
            r=tmp.r+dr[i];
            c=tmp.c+dc[i];

            if ( r>=0 && c>=0 && c<col && r<row && fire[r][c]==INF && mp[r][c]!='#'){
                ff.r=r;
                ff.c=c;
                ff.val=tmp.val+1;
                fire[r][c]=ff.val;

                q.push(ff);
            }
        }

    }

}

int BFSjoe(){

    queue<tt> keu;
    keu.push(joe);

    int r,c;
    while ( !keu.empty() ){
        tmp=keu.front();
        keu.pop();

        if ( tmp.r==0 || tmp.r == row-1 || tmp.c==0 || tmp.c==col-1 ){
            return tmp.val+1;
        }

        for (int i=0;i<4;++i){
            r=tmp.r+dr[i];
            c=tmp.c+dc[i];

            if ( r>=0 && c>=0 && r<row && c<col && fire[r][c]>(tmp.val+1) && mp[r][c]!='#'){
                ff.r=r;
                ff.c=c;
                ff.val=tmp.val+1;
                mp[r][c]='#';

                keu.push(ff);
            }

        }

    }
    return -1;
}

int main(){
    freopen("in.txt","r",stdin);
    int kase;
    scanf("%d",&kase);
    queue<tt> empty;
    while (kase--){

        scanf("%d %d",&row,&col);
        q=empty;
        for (int i=0;i<row;++i){
            scanf("%s",mp[i]);
            for (int j=0;j<col;++j){
                fire[i][j]=INF;
                if ( mp[i][j]=='F' ){
                    tmp.r=i;
                    tmp.c=j;
                    tmp.val=0;
                    fire[i][j]=0;
                    q.push(tmp);
                }else if ( mp[i][j]=='J' ){
                    joe.r=i;
                    joe.c=j;
                    joe.val=0;
                }
            }
        }
        BFSfire();


        int rr=BFSjoe();
        if ( rr== -1 ){
            printf("IMPOSSIBLE\n");
        }else{
            printf("%d\n",rr);
        }
    }
    return 0;

}

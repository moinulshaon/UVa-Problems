#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char board[55][55];
int row,col;


int func(int c){
    int cnt=0;
    for (int i=0;i<row;++i){
        if ( board[i][c]=='1' ){
            int pos=(1<<29);
            for (int j=0;j<col;++j){
                if ( board[i][j]=='0' ){
                    pos=min( pos,abs(j-c) );
                }
            }
            if ( pos==(1<<29) )return -1;
            cnt+=pos;
        }
    }
    return cnt;
}

int main(){
    freopen("in.txt","r",stdin);

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d %d",&row,&col);
        for (int i=0;i<row;++i){
            scanf("%s",board[i]);
        }

        int tmp,ans= (1<<29);

        for (int i=0;i<col;++i){
            tmp=func(i);
            //printf("%d\n",tmp);
            if ( tmp!= -1 )
                ans=min(ans,tmp);
        }
        if ( ans == (1<<29) )
            ans= -1;
        printf("Case %d: %d\n",kk,ans);
    }
    return 0;
}

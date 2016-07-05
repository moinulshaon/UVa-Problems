#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;

char mat[15][15];
int n;

int dr[]={-1,0,1,0};
int dc[]={0,-1,0,1};

char check(int r,int c){

    bool al[26]={false};
    for (int i=0;i<4;++i){
        int x=r+dr[i],y=c+dc[i];
        if ( x>=0 && x<n && y>=0 && y<n ){
            al[ mat[x][y]-'A' ]=true;
        }
    }
    for (int i=0;i<26;++i){
        if ( !al[i] ){
            return i+'A';
        }
    }

}


int main(){
    freopen("in.txt","r",stdin);

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        scanf("%d",&n);
        for (int i=0;i<n;++i){
            scanf("%s",mat[i]);
        }

        for (int i=0;i<n;++i){
            for (int j=0;j<n;++j){
                if ( !isalpha(mat[i][j]) )
                    mat[i][j]=check(i,j);
            }
        }
        printf("Case %d:\n",kk);
        for (int i=0;i<n;++i){
            printf("%s\n",mat[i]);
        }
    }
    return 0;

}

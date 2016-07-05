#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>

#define sz 110

using namespace std;

int row,col;
int d[sz][sz];

int cnt;

void DFS(int a,int b){
    if (a>row || b>col || !d[a][b])return ;

    if (a==row && b==col){
        ++cnt;
        return ;
    }
    DFS( a+1,b );
    DFS( a,b+1 );

}


int main(){
    freopen("in.txt","r",stdin);

    int kase,a,b;
    string str;
    scanf("%d",&kase);

    getchar();

    while (kase--){
        cnt=0;

        memset(d,true,sizeof(d));
        getchar();

        scanf("%d %d",&row,&col);
        getchar();

        for (int i=0;i<row;++i){
            scanf("%d",&a);
            str="";
            getline(cin,str);

            stringstream sstr(str);

            while (sstr>>b){
                d[a][b]=false;
            }
        }

        DFS(1,1);

        printf("%d\n",cnt);

        if (kase)
            printf("\n");

    }
    return 0;
}

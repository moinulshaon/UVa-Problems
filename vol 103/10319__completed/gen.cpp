#include <cstdio>
#include <cstdlib>

using namespace std;

int main(){
    freopen("in.txt","w",stdout);
    int kase=6;
    printf("%d\n",kase);
    while(kase--){
        int row=rand()%10+5;
        int col=rand()%10+5;

        int query=rand()%10+5;

        printf("%d %d %d\n",row,col,query);

        for (int i=0;i<query;++i){
            int r1=rand()%row+1;
            int r2=rand()%row+1;

            int c1=rand()%col+1;
            int c2=rand()%col+1;
            printf("%d %d %d %d\n",r1,c1,r2,c2);
        }
    }

}

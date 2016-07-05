#include <cstdio>
#include <cstring>
#include <vector>

#define sz 510

using namespace std;

int nuts,bolts;
int left[sz],right[sz];
vector<int>outarrowLeft[sz];


bool DFS(int n){

    printf("%d\n",n);
    //getchar();

    for (int i=0;i<outarrowLeft[n].size();++i)
        if ( right[ outarrowLeft[n][i] ] == -1 ){
            right[ outarrowLeft[n][i] ]=n;
            left[ n ]=outarrowLeft[n][i];
            return true;
        }
    for (int i=0;i<outarrowLeft[n].size();++i){
        if ( n!=right[  outarrowLeft[n][i] ] &&  DFS( right[  outarrowLeft[n][i] ] ) ){

            right[ outarrowLeft[n][i] ]=n;
            left[ n ]=outarrowLeft[n][i];
            return true;

        }
    }
    return false;

}


int main(){

    freopen("in.txt","r",stdin);

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d %d",&nuts,&bolts);

        memset(left,-1,sizeof(left));
        memset(right,-1,sizeof(right));

        for (int i=0;i<nuts;++i)
            outarrowLeft[i].clear();


        int tmp;

        for (int i=0;i<nuts;++i)
            for (int j=0;j<bolts;++j){
                scanf("%d",&tmp);
                if (tmp){
                    outarrowLeft[i].push_back(j);

                }

            }


        int cnt=0;
        for (int i=0;i<nuts;++i){
            if ( left[i]== -1 ){
                if ( DFS(i) )
                    ++cnt;
            }
            else
                ++cnt;
        }


        //for (int i=0;i<nuts;++i)
         //   printf("%d\n",left[i]);
        printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n",kk,cnt);


    }
    return 0;

}

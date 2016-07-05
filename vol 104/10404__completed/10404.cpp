#include <cstdio>
#include <cstring>

using namespace std;

#define sz 1000010

bool arr[sz];
int val[15];

int main(){

    freopen("in.txt","r",stdin);

    int desire,n;
    while (scanf("%d",&desire)==1){

        for (int i=0;i<=desire;++i)
            arr[i]=false;

        scanf("%d",&n);

        for (int i=0;i<n;++i){
            scanf("%d",&val[i]);
            arr[ val[i] ]=true;
        }

        for (int i=1;i<=desire;++i){
            for (int j=0;j<n;++j){
                if ( i-val[j]>0 && arr[  i-val[j] ]==false ){
                    arr[i]=true;
                    break;
                }
            }
        }

        if (arr[desire])
            printf("Stan wins\n");
        else
            printf("Ollie wins\n");

    }
    return 0;
}

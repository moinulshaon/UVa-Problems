#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int n;

    int pp[31];
    pp[0]=1;
    for (int i=1;i<31;++i){
        pp[i]=pp[i-1]*2;
        //printf("%d\n",pp[i]);
    }

    while ( scanf("%d",&n)==1 ){
        for (int i=30;i>=0;--i){
            if ( pp[i] & n ){
                printf("%d\n",i+1);
                break;
            }
        }
    }
    return 0;
}

#include <cstdio>

using namespace std;

int main(){
    int n,a;

    while (scanf("%d",&n)==1 && n){

        int r=0;

        while (n--){
            scanf("%d",&a);
            r^=a;
        }
        if (r)
            printf("Yes\n");
        else
            printf("No\n");

    }
    return 0;
}

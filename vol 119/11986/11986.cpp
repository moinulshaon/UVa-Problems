#include <cstdio>
#include <cmath>

using namespace std;

int main(){
    int kase,n;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d",&n);
        if (n)
            printf("Case %d: %d\n",kk,int(log2(n))+1 );
        else
            printf("Case %d: 0\n",kk );
    }
    return 0;
}

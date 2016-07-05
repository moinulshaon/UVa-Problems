#include <cstdio>
#include <cmath>

using namespace std;

int main(){
    int r,n;
    for (int kk=1;true;++kk){
        scanf("%d %d",&r,&n);
        if (!r && !n)return 0;

        int result=ceil(double(r)/n)-1;
        if (result>26){
            printf("Case %d: impossible\n",kk);
        }
        else{
            printf("Case %d: %d\n",kk,result);
        }
    }
}

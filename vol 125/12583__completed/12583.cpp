#include <cstdio>

using namespace std;

int main(){
    int kase,len,k;
    scanf("%d",&kase);

    char line[1000];

    for (int kk=1;kase--;++kk){

        scanf("%d %d %s",&len,&k,line);

        int cnt=0;
        for (int i=0;i<len;++i){
            for (int j=0;j<k;++j){
                if ( i-j-1>=0 && line[i]==line[ i-j-1 ] ){
                    cnt++;
                    break;
                }
            }
        }
        printf("Case %d: %d\n",kk,cnt);

    }
    return 0;
}

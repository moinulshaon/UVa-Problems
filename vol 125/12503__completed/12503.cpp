#include <cstdio>
#include <cstring>

using namespace std;

char in[110];
char str[20];

int main(){
    int kase;
    scanf("%d",&kase);

    while(kase--){
        int n,x;
        scanf("%d",&n);

        int ans=0;
        for (int i=0;i<n;++i){
            scanf("%s",str);
            if ( str[0]=='L' ){
                --ans;
                in[i]='L';
            }else if ( str[0]=='R' ){
                ++ans;
                in[i]='R';
            }else{
                scanf("%s %d",str,&x);
                in[i]=in[x-1];
                if ( in[i]=='L' ){
                    --ans;
                }else{
                    ++ans;
                }

            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

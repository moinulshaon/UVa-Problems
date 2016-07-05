#include <cstdio>
#include <cstring>

using namespace std;

int cnt[300];

int main(){
    int v,e,a,b;
    while ( scanf("%d %d",&v,&e)==2 ){

        memset(cnt,0,sizeof(cnt));
        while ( e-- ){
            scanf("%d %d",&a,&b);
            cnt[a]++;
            cnt[b]++;
        }
        bool pos=true;
        for (int i=0;i<v;++i){
            if ( cnt[i]%2 || cnt[i]==0 ){
                pos=false;
                break;
            }
        }
        if ( pos )printf("Possible\n");
        else printf("Not Possible\n");
    }
    return 0;

}

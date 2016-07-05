#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct tt{
    int dis,gar;

    bool operator <(const tt&b)const{
        return dis<b.dis;
    }

}point[1100];

int main(){
    int kase;
    scanf("%d",&kase);

    while (kase--){

        int limit,stop;

        scanf("%d %d",&limit,&stop);
        for (int i=0;i<stop;++i){
            scanf("%d %d",&point[i].dis,&point[i].gar);
        }
        //sort( point,point+stop );

        int ans=0,now=0;

        for (int i=0;i<stop;++i){

            if ( now+point[i].gar< limit ){
                now+=point[i].gar;
            }else if ( now+point[i].gar==limit ){
                now=0;
                ans+=2*point[i].dis;
            }else{
                ans+=2*point[i].dis;
                now=point[i].gar;
            }
        }
        ans+=2*point[stop-1].dis;
        if ( now==0 )ans -=2*point[stop-1].dis;
        printf("%d\n",ans);
    }
    return 0;
}

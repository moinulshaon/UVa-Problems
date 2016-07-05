#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

int one[30];

int main(){
    int n;
    while(scanf("%d",&n)==1){
        map<int,int> mp;
        int tmp;
        for (int i=0; i<n;++i){
            scanf("%d",&tmp);
            mp[ tmp ] = i+1;
        }

        for (int i=0;i<n;++i){
            scanf("%d",&one[i]);
            one[i]  = mp[ one[i] ];
        }

        int ans = 0;
        for (int i=0;i<n;++i){
            for (int j=0;j<i;++j){
                if ( one[j]>one[i] )ans++;
            }
        }
        printf("%d\n",ans);

    }
    return 0;
}

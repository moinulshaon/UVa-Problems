#include <cstdio>
#include <algorithm>

using namespace std;

struct tt{
    int id,len;
    double freq;
}songs[1<<16+2];

bool cmp(const tt&a,const tt&b){
    return a.len*b.freq<b.len*a.freq;
}

int main(){
    int n;

    freopen("in.txt","r",stdin);

    while (scanf("%d",&n)==1){
        for (int i=0;i<n;++i){
            scanf("%d %d %lf",&songs[i].id,&songs[i].len,&songs[i].freq);
        }
        sort(songs,songs+n,cmp);
        scanf("%d",&n);
        printf("%d\n",songs[n-1].id);
    }
    return 0;
}

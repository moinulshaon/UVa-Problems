#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct tt{
    int a,c,g,t;
    int mx,ham;
}pos[1100];

char dna[55][1100];
int n,len;


void func(int x){
    pos[x].mx=max( pos[x].a,max( pos[x].c,max(pos[x].g,pos[x].t) )  );
    pos[x].ham=pos[x].a+pos[x].c+pos[x].g+pos[x].t-pos[x].mx;
    if ( pos[x].a==pos[x].mx ){
        printf("A");
    }else if ( pos[x].c==pos[x].mx  ){
        printf("C");
    }else if ( pos[x].g==pos[x].mx  ){
        printf("G");
    }else if ( pos[x].t==pos[x].mx  ){
        printf("T");
    }
}

int main(){
    freopen("in.txt","r",stdin);

    int kase;
    scanf("%d",&kase);

    while (kase--){
        scanf("%d %d",&n,&len);
        for (int i=0;i<n;++i){
            scanf("%s",dna[i]);
        }
        memset(pos,0,sizeof(pos));
        for (int i=0;i<len;++i){
            for (int j=0;j<n;++j){
                if ( dna[j][i]=='A' ){
                    pos[i].a++;
                }else if ( dna[j][i]=='C' ){
                    pos[i].c++;
                }else if ( dna[j][i]=='G' ){
                    pos[i].g++;
                }else if ( dna[j][i]=='T' ){
                    pos[i].t++;
                }
            }
        }
        int sum=0;
        for (int i=0;i<len;++i){
            func(i);
            sum+=pos[i].ham;
        }
        printf("\n%d\n",sum);
    }
    return 0;
}

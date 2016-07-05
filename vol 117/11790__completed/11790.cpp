#include <cstdio>
#include <algorithm>

#define sz 10001

using namespace std;

struct ss{
    int height,width;
}building[sz];
int total;
int dpIncreasing[sz];
int dpDecreasing[sz];

int DFS1(int n){

    if (dpIncreasing[n]!=-1)return dpIncreasing[n];

    int mx=0;
    for(int i=n+1;i<total;++i){
        if (building[i].height>building[n].height)
            mx=max( mx,DFS1(i) );
    }
    return dpIncreasing[n]=building[n].width+mx;

}

int DFS2(int n){
    if (dpDecreasing[n]!=-1)return dpDecreasing[n];

    int mx=0;
    for(int i=n+1;i<total;++i){
        if (building[i].height<building[n].height)
            mx=max( mx,DFS2(i) );
    }
    return dpDecreasing[n]=building[n].width+mx;

}


int main(){
    freopen("in.txt","r",stdin);


    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d",&total);

        for (int i=0;i<total;++i){
            dpDecreasing[i]=-1;
            dpIncreasing[i]=-1;
        }

        for (int i=0;i<total;++i)
            scanf("%d",&building[i].height);
        for (int i=0;i<total;++i)
            scanf("%d",&building[i].width);

        int increasing=0;
        for (int i=0;i<total;++i){
            increasing=max(increasing,DFS1(i));
        }

        int decreasing=0;
        for (int i=0;i<total;++i){
            decreasing=max(decreasing,DFS2(i));
        }
        printf("Case %d.",kk);
        if (increasing>=decreasing){
            printf(" Increasing (%d). Decreasing (%d).\n",increasing,decreasing);
        }
        else{
            printf(" Decreasing (%d). Increasing (%d).\n",decreasing,increasing);
        }

    }
    return 0;

}

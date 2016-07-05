#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

struct lists {
    int start;
    int end;
    int distance;
} a [100+ 10];

int parent [20];

bool cmp (lists p, lists q)
{
    if ( p.distance < q.distance ) return true;
    return false;
}

int parentOf (int n)
{
    if ( n == parent [n] ) return n;
    return parent [n] = parentOf (parent [n]);
}

int pop[20];

bool check(int N,int pos){
    return (bool)(N & (1<<pos));
}


int main(){
    freopen("in.txt","r",stdin);
    int n,m,lim,kase;

    scanf("%d",&kase);

    while(kase--){
        scanf("%d %d %d",&n,&m,&lim);

        for (int i=0;i<n;++i){
            scanf("%d",&pop[i]);
        }

        for (int i=0;i<m;++i){
            scanf("%d %d %d",&a[i].start,&a[i].end,&a[i].distance);
            a[i].start--;
            a[i].end--;
        }

        sort(a,a+m,cmp);
        int ans=0;

        for (int i=(1<<n)-1;i>0;--i){

            if ( check(i,0)==0 )continue;
            //printf("shoan %d\n",i);
            int sum=0,city=0;
            for (int j=0;j<n;++j){
                if ( check( i,j )==1 ){
                    sum+=pop[j];
                    ++city;
                }
            }
            if ( sum<=ans )continue;

            for (int j=0;j<n;++j){
                parent[j]=j;
            }
            int cost=0;
            for (int j=0;j<m;++j){
                if ( check( i,a[j].start )==1 && check( i,a[j].end )==1  ){

                    int p = parentOf (a [j].start);
                    int q = parentOf (a [j].end);
                    //printf("shoan %d %d\n",p,q);
                    if ( p != q ) {
                        parent [p] = q;
                        cost+= a[j].distance;
                        --city;
                        //printf("%d\n",a[j].distance);
                    }
                }
            }
            //printf("%d\n",cost);
            if ( cost<=lim && city==1 )ans=sum;
        }
        printf("%d\n",ans);
    }
    return 0;
}

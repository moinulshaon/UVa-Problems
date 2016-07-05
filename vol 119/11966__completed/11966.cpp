#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <iostream>
#include <complex>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define SIZE 1100

int parent[SIZE];
int size[SIZE];

int parentOf (int n){
    if ( n == parent [n] ) return n;
    return parent [n] = parentOf (parent [n]);
}

void makeUnion(int p,int q){
    if ( p==q )return ;

    if (size[p]>size[q])swap(p,q);
    size[q]+=size[p];
    parent [p] = q;
}

typedef complex<double> pdou;

pdou arr[SIZE];

int main(){
    FRO

    int n;
    double d;
    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d %lf",&n,&d);
        double a,b;
        for (int i=0;i<n;++i){
            scanf("%lf %lf",&a,&b);
            arr[i]=pdou(a,b);
            parent[i]=i;
            size[i]=1;
        }



        for (int i=0;i<n;++i){
            for (int j=i+1;j<n;++j){
                if ( abs(arr[i]-arr[j])<=d+1e-6 ){
                    makeUnion( parentOf(i),parentOf(j) );
                }
            }
        }

        int cnt=0;
        for (int i=0;i<n;++i){
            if ( parentOf(i)==i ){
                ++cnt;
            }
        }
        printf("Case %d: %d\n",kk,cnt);
    }


    return 0;
}

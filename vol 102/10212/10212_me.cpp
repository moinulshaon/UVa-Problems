#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <iostream>
#include <queue>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

int fact( int n,int p ){
    int cnt=0;
    while( n ){
        cnt+=n/p;
        n=n/p;
    }
    return cnt;
}

int main(){

    int n,m;

    while( scanf("%d %d",&n,&m)==2 ){

        int ans=1;
        for (int i=n-m+1;i<=n;++i){
            int tmp=i;
            while( tmp%2==0 ){
                tmp/=2;
            }
            while( tmp%5==0 ){
                tmp/=5;
            }
            ans=(ans*tmp)%10;
        }

        int two=fact(n,2)-fact(n-m,2);
        int five=fact(n,5)-fact(n-m,5);
        //printf("%d\n",ans%10);
        if ( two>five ){
            two-=five;

            for (int i=0;i<two;++i){
                ans=(ans*2)%10;
            }
        }else{
            five-=two;
            for (int i=0;i<five;++i){
                ans=(ans*5)%10;
            }
        }
        printf("%d\n",ans%10);
    }


    return 0;
}

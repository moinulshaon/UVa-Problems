#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

typedef long long LL;

LL ncr[101][101];

LL combination(int n,int r){

    if (r>n/2)r=n-r;

    if (r==0)return 1;
    else if (n==r)return 1;
    else if (ncr[n][r]!=-1)return ncr[n][r];
    else return ncr[n][r]=ncr[n][n-r]=combination(n-1,r-1)+combination(n-1,r);

}
LL factorial(LL n){
    if (!n)return 1;
    return n*factorial(n-1);
}
int main(){

    memset(ncr,-1,sizeof(ncr));
    int n,k;

    while ( scanf("%d %d",&n,&k)==2 ){

        LL sum=0;

        for (int i=k;i<=n;++i){

            sum+=combination(n,i)-2;
            printf("%lld %d %lld\n",combination(n,i),n-i+1,sum);
        }


    }
    return 0;

}

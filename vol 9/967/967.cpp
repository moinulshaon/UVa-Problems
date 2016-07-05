#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#define sz 1000001

using namespace std;

bool prime[sz];
int dp[sz];


void circular(int n){
    if (dp[n]==-1){
        int tmp=n,cnt=0;
        while(tmp/=10){
            ++cnt;
        }
        ++cnt;
        bool on=true;
        vector <int> v;
        for (int i=0;i<cnt;++i){
            if (!prime[n])on=false;
            v.push_back(n);
            tmp=n%10;
            n/=10;
            n+=tmp*pow(10,cnt-1);
        }
        for (int i=0;i<cnt;++i)
            if (dp[ v[i] ]== -1)
                dp[ v[i] ]=on;
    }
}


int main(){
    for (int i=2;i<sz;++i)
        prime[i]=true;
    for (int i=2;i<=1000;++i)
        if (prime[i])
            for (int j=2*i;j<sz;j+=i)
                prime[j]=false;

    memset(dp,-1,sizeof(dp));
    for (int i=0;i<sz;++i)
        circular(i);

    for (int i=0;i<sz;++i)
        dp[i]+=dp[i-1];

    int ql,qr;
    while (true){
        scanf("%d",&ql);
        if (ql==-1)return 0;
        scanf("%d",&qr);
        int result=dp[qr]-dp[ql-1];
        if (result==1)
            printf("1 Circular Prime.\n");
        else if (result)
            printf("%d Circular Primes.\n",result);
        else
            printf("No Circular Primes.\n");
    }
}

#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

unsigned long long n,x;

unsigned long long  dp[30][200];

unsigned long long DFS(unsigned long long diceNo,unsigned long long s){

    if (s>=x && diceNo==n+1){
        return 1;
    }else if (diceNo>n+1)return 0;

    if ( diceNo>=0 && dp[diceNo][s] != -1 ){
        //cout<<dp[diceNo][s]<<endl;
        return dp[diceNo][s];
    }
    unsigned long long tmp=0;
    for (int i=1;i<=6;++i){
        if (diceNo)
            tmp=tmp+DFS(diceNo+1,s+i);
        else{
            tmp=DFS(diceNo+1,s);
            break;
        }
    }
    return dp[diceNo][s]=tmp;

}


unsigned long long gcd(unsigned long long a,unsigned long long b)
{
    unsigned long long temp=a;
    while (b!=0)
    {
        temp=b;
        b=a%b;
        a=temp;
    }
    return temp;

}

int main(){

    freopen("in.txt","r",stdin);

    while ( scanf("%llu %llu",&n,&x)==2 ){

        if (!n && !x)return 0;

        memset(dp,-1,sizeof(dp));

        unsigned long long num=DFS(0,0);
        unsigned long long den=1;

        for (int i=0;i<n;++i){
            den=den*6;
        }

        unsigned long long d=gcd(num,den);
        num/=d;
        den/=d;

        if (num==0){
            printf("0\n");
        }else if (num==1 && den==1){
            printf("1\n");
        }else{
            printf("%llu/%llu\n",num,den);
        }

    }
    return 0;

}

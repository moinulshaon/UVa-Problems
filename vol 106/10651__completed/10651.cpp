#include <cstdio>
#include <cstring>
#include <algorithm>


using namespace std;




int set(int N,int pos){
    return N=N | (1<<pos);
}
int reset(int N,int pos){
    return N= N & ~(1<<pos);
}
bool check(int N,int pos){
    return (bool)(N & (1<<pos));
}


int dp[ 1<<12 +2];

int count( int n ){

    int cnt=0;
    for (int i=0;i<12;++i){
        if ( check(n,i) ){
            cnt++;
        }
    }
    return cnt;

}


int func( int state ){

    if ( dp[state]!= -1)return dp[state];

    int ans= state;

    for (int i=0;i<13;++i){

        if (i+2<12 && check(state,i)==0 && check(state,i+1)==1 && check(state,i+2)==1 ){
            int tmp=func( reset( reset( set(state,i ) ,i+1),i+2) );
            if ( count(ans)> count(tmp) ){
                ans=tmp;
            };

        }

        if (i+2<12 && check(state,i)==1 && check(state,i+1)==1 && check(state,i+2)==0 ){
            int tmp=func( set( reset( reset(state,i ) ,i+1),i+2) );
            if ( count(ans)> count(tmp) ){
                ans=tmp;
            };
        }


    }
    return dp[state]= ans;



}


int main(){

    freopen("in.txt","r",stdin);

    memset(dp,-1,sizeof(dp));

    int kase;
    char arr[15];
    scanf("%d",&kase);

    while (kase--){
        scanf("%s",arr);
        int n=0;

        for (int i=0;i< 12;++i){
            if (  arr[i]=='o' ){
                n=set(n,i);
            }
            //printf("%d",check(n,i));
        }
        //printf("\n");

        printf("%d\n",count( func(n) ));
    }
    return 0;

}

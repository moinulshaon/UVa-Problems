#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

char nxt[1010][1010];
int dp[1010][1010];

char line[1010];
int len;
char result[2020];
int cc;

int func( int left ,int right){
    if ( left>right )return 0;

    if ( dp[left][right]!= -1 ) return dp[left][right];

    if ( line[left]==line[right] ){
        if ( left!=right )
            return dp[left][right]=1+func(left+1,right-1)+1;
        else
            return dp[left][right]=1;
    }else{
        int a=1+func(left,right-1)+1;
        int b=1+func(left+1,right)+1;
        if ( a<b ){
            return dp[left][right]=a;
        }else{
            return dp[left][right]=b;
        }
    }

}
void build(int left,int right){
    if ( left>right )return ;

    if ( line[left]==line[right] ){
        if ( left!=right ){
            result[cc++]=line[left];
            build(left+1,right-1);
            result[cc++]=line[right];
        }else{
            result[cc++]=line[left];
        }
    }else{
        if ( dp[left][right-1]<dp[left+1][right] ){
            result[cc++]=line[right];
            build(left,right-1);
            result[cc++]=line[right];
        }else{
            result[cc++]=line[left];
            build(left+1,right);
            result[cc++]=line[left];
        }
    }
}

int main(){
    freopen("in.txt","r",stdin);

    while (gets(line)){
        memset(dp,-1,sizeof(dp));
        len=strlen(line);
        cc=0;
        int rr=func(0,len-1);
        build(0,len-1);
        result[cc++]='\0';
        printf("%d ",rr-len);
        puts(result);

    }
    return 0;

}

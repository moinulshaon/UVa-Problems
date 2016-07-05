#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<string>
#define min(a,b) (a<b?a:b)
#define CLR(a) memset(a,0,sizeof(a))
#define RESET(a) memset(a,-1,sizeof(a))
#define FRO freopen("input.txt","r",stdin);
#define lld long long int
#define FROout freopen("output.txt","w",stdout);
using namespace std;

lld sum[10];

lld count(lld a,lld mult)
{
    if(a<=0) return 0;
    int l=a%10;
	a/=10;
	lld ret=0,left=0,b=a;
    while(b)
    {
        left=left+b%10;
        b/=10;
    }
    return sum[l]*mult+left*(1+l)*mult+ a*45*mult+count(a-1,mult*10);
}

int main()
{
    //FRO
    lld i,a,b,ret;
    for(i=0;i<10;i++) sum[i]=i;
    for(i=1;i<10;i++) sum[i]+=sum[i-1];
    while(scanf("%lld %lld",&a,&b)==2 && (a||b))
    {
        if(a>b) swap(a,b);
        ret=count(b,1);
		ret-=count(a-1,1);
        printf("%lld\n",ret);
    }
    return 0;
}

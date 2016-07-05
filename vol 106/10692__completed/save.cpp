//====================================================================||
//                                                                    ||
//                                                                    ||
//                         Author : GCA                               ||
//                  6AE7EE02212D47DAD26C32C0FE829006                  ||
//====================================================================||
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cctype>
#include <utility>
using namespace std;
#ifdef ONLINE_JUDGE
#define ll "%lld"
#else
#define ll "%I64d"
#endif
typedef unsigned int uint;
typedef long long int Int;
#define Set(a,s) memset(a,s,sizeof(a))
#define Write(w) freopen(w,"w",stdout)
#define Read(r) freopen(r,"r",stdin)
#define Pln() printf("\n")
#define I_de(x,n)for(int i=0;i<n;i++)printf("%d ",x[i]);Pln()
#define De(x)printf(#x"%d\n",x)
#define For(i,x)for(int i=0;i<x;i++)
#define CON(x,y) x##y
#define Pmz(dp,nx,ny)for(int hty=0;hty<ny;hty++){for(int htx=0;htx<nx;htx++){\
    printf("%d ",dp[htx][hty]);}Pln();}
#define M 55
#define PII pair<int,int>
#define PB push_back
#define oo INT_MAX
#define Set_oo 0x3f
#define Is_debug true
#define debug(...) if(Is_debug)printf("DEBUG: "),printf(__VA_ARGS__)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define eps 1e-6
bool xdy(double x,double y){return x>y+eps;}
bool xddy(double x,double y){return x>y-eps;}
bool xcy(double x,double y){return x<y-eps;}
bool xcdy(double x,double y){return x<y+eps;}
int min3(int x,int y,int z){
    int tmp=min(x,y);
    return min(tmp,z);
}
int max3(int x,int y,int z){
    int tmp=max(x,y);
    return max(tmp,z);
}
int n,m;
int a[15];
char str[100];
int phi[10005];
int powmod(int a,int x,int c){
    if(x<=0)return 1;
    int t=powmod(a,x/2,c);
    int ans=(Int)t*t%c;
    if(x&1){
        ans=(Int)ans*a%c;
    }
    return ans;
}
int cal(int x,int a,int c){
    int t=x+phi[c];
    return powmod(a,t,c);
}
int bt(int now,int c){
    if(now>=n-1)return a[now]%c;
    int x=bt(now+1,phi[c]);
    return powmod(a[now],x+ phi[c] ,c);
}
void init(){
    Set(phi,0);
    phi[1]=1;
    for(int i=2;i<10005;i++){
        if(!phi[i]){
            for(int j=i;j<10005;j+=i){
                if(!phi[j])phi[j]=j;
                phi[j]=phi[j]/i*(i-1);
            }
        }
    }
}
int main() {

    freopen("in.txt","r",stdin);

    ios_base::sync_with_stdio(0);
    init();
    int ff=0;
//    debug("%d\n",powmod(2,8,3));
    while(scanf("%d%d",&m,&n)==2){
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        printf("Case #%d: %d\n",++ff,bt(0,m));
    }
}

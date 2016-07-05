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
#include <climits>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

#define X first
#define Y second

#define MP make_pair

#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)


typedef pair<int,int> pint;
typedef map<int,int> mint;

int main(){

    //FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int n,m,r,mov;
        scanf("%d %d %d %d",&n,&m,&r,&mov);

        double ans = 0;
        for (int i=1;i<=n;++i){
            for (int j=1;j<=m;++j){
                for (int k=1;k<=r;++k){
                    double x = 2*i*(n-i+1)-1;
                    double y = 2*j*(m-j+1)-1;
                    double z = 2*k*(r-k+1)-1;

                    x = x*y*z /pow(n*m*r,2);

                    ans += x * ( 1- pow( 1-2*x,mov ) )/( 1-(1-2*x) );
                    //cout<<x<<endl;
                    /*
                    double sum = 0;
                    for (int xx=0;xx<mov;++xx){
                        sum = ( 1-2*x )*sum + x;
                    }
                    ans += sum;
                    cout<<i<<" "<<j<<" "<<k<<" "<<x<<endl;*/
                }
            }
        }
        printf("Case %d: %.7lf\n",kk,ans);

    }


    return 0;
}

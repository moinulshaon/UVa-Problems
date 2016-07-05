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
#include <stack>

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

#define SIZE 50100

int n;
int arr[SIZE];

int frml[SIZE],frmr[SIZE];

const int INF = 1000000;

void calcleft(){
    arr[0] = -INF;
    stack<int> stk;
    stk.push( 0 );
    for (int i=1;i<=n;++i ){
        while ( arr[ stk.top() ] >= arr[ i ] ){
            stk.pop();
        }
        frml[i] = stk.top();
        stk.push( i );
    }
}
void calcright(){
    arr[n+1] = -INF;
    stack<int> stk;
    stk.push( n+1 );
    for (int i=n;i>0;--i ){
        while ( arr[ stk.top() ] > arr[ i ] ){
            stk.pop();
        }
        frmr[i] = stk.top();
        stk.push( i );
    }
}

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d",&n);
        for (int i=1;i<=n;++i){
            scanf("%d",&arr[i]);
        }

        calcleft();
        calcright();

        LL left = 0;

        //cout<<left<<endl;

        for (int i=1;i<=n;++i){
            left += LL( arr[i] )*LL(i)*LL(n-i+1);

            LL l= i-frml[i]-1;
            LL r = frmr[i]-i-1;
            //cout<<i<<" "<<l<<" "<<r<<endl;
            left-= arr[i]*( (l+1)*(r+1)*(r+2)/2 + l*(l+1)*(r+1)/2 );
        }

        //cout<<right<<endl;

        printf("Case %d: %lld\n",kk,left);
    }



    return 0;
}

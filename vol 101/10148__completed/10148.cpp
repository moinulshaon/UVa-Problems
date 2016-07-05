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

#define SIZE 1010

pint arr[SIZE];

bool vis[2*SIZE*10]={0};
int mid = 10010;

bool cmp( const pint &a,const pint &b ){
    return a.Y<b.Y;
}

int main(){

    int kase;
    scanf("%d",&kase);

    while ( kase-- ){

    CLR(vis);

    int k,n;
    scanf("%d %d",&k,&n);

    for (int i=0;i<n;++i){

        scanf("%d %d",&arr[i].X,&arr[i].Y);
        arr[i].X += mid;
        arr[i].Y += mid;
        if ( arr[i].X> arr[i].Y ){
            swap( arr[i].X, arr[i].Y );
        }
    }

    sort( arr,arr+n,cmp );

    for (int i=0;i<n;++i){

        int tmp = 0 ;
        for (int j=arr[i].X ; j<=arr[i].Y ; ++j ){
            if ( vis[ j ] ){
                tmp++;
            }
        }

        if ( tmp < min( k, arr[i].Y-arr[i].X+1 ) ){
            tmp = min( k, arr[i].Y-arr[i].X+1 ) - tmp;
            for (int j=arr[i].Y , k = 0 ; k <tmp;--j ){
                if ( !vis[ j ] ){
                    vis[j]=true;
                    ++k;
                }
            }
        }
    }

    int cnt = 0;
    for (int i=0;i<2*SIZE*10;++i){
        if ( vis[i] )cnt++;
    }

    printf("%d\n",cnt);
    for (int i=0;i<2*SIZE*10;++i){
        if ( vis[i] ){
            printf("%d\n",i-mid);
        }
    }

    if ( kase )printf("\n");

    }

    return 0;
}

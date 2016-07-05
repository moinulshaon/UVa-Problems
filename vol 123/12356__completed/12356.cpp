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

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

typedef pair<int,int> pint;
typedef map<int,int> mint;

#define SIZE 101000

int leftparent[SIZE];
int rightparent[SIZE];


int main(){
    FRO

    int n,m;

    while( scanf("%d %d",&n,&m)==2 && (n+m) ){

        for (int i=1;i<=n;++i){
            leftparent[i]=i-1;
            rightparent[i]=i+1;
        }
        leftparent[1]= 0;
        rightparent[n]= 0;

        int a,b;

        while( m-- ){
            scanf("%d %d",&a,&b);
            int u=leftparent[a] ;
            int v=rightparent[b] ;

            if ( u==0 )printf("*");
            else printf("%d",u);

            printf(" ");

            if ( v==0 )printf("*\n");
            else printf("%d\n",v);

            rightparent[ u ]=v;
            leftparent[ v ]=u;

        }
        printf("-\n");
    }


    return 0;
}

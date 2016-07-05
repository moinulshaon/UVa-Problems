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

typedef pair<int,int> pint;
typedef map<int,int> mint;

int main(){

    int n,a,b;

    while ( scanf("%d %d %d",&n,&a,&b) == 3 ){

        for (int i=1;i<=n;++i){
            if ( a/2+a%2 == b/2+b%2 ){
                printf("%d\n",i);
                break;
            }
            a= a/2+a%2;
            b= b/2+b%2;
        }

    }


    return 0;
}

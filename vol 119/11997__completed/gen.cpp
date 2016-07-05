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

    freopen("in.txt","w",stdout);

    int n=750;
    printf("%d\n",n);

    for (int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            printf("%d ",rand()%1000000);
        }printf("\n");
    }


    return 0;
}

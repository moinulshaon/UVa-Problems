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

int main(){

    freopen("in.txt","w",stdout);

    printf("901\n");
    for (int i=0;i<5;++i){
        if ( i<3 )
            printf("@");
        else
            printf("0");
        for (int j=0;j<900;++j){
            printf("%c",rand()%10+'0');
        }printf("\n");
    }
    printf("0\n");


    return 0;
}

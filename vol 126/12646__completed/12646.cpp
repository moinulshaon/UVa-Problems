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

    int a,b,c;

    while ( scanf("%d %d %d",&a,&b,&c)==3 ){
        if ( (a+b+c) == 0 || (a+b+c) == 3 ){
            printf("*\n");
        }else{
            if ( a!=b && a!=c ){
                printf("A\n");
            }else if ( b!= a && b!=c ){
                printf("B\n");
            }else{
                printf("C\n");
            }
        }
    }


    return 0;
}

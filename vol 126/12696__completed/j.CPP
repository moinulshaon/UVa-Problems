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

#define SIZE 510000

#define EPS 1e-6

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    int ans = 0;
    while ( kase-- ){

        double a,b,c,w;
        cin>>a>>b>>c>>w;

        if ( w<7+EPS && ( ( a<56+EPS && b<45+EPS && c<25+EPS ) || (a+b+c) <125+EPS )  ){
            printf("1\n");
            ans++;
        }else{
            printf("0\n");
        }

    }

    printf("%d\n",ans);

    return 0;
}

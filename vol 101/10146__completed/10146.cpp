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

#define SIZE 10100

char now[SIZE],prv[SIZE];

int main(){

    //FRO

    int kase;
    scanf("%d",&kase);
    gets( now );
    gets( now );

    while ( kase-- ){



    int lim = 0;
    while ( gets(now) && strlen(now) >0 ){
        int save = 0;
        for (int i=0;i<lim && now[i] == prv[i] ;++i) {
            printf(" ");
            save = i+1;
        }
        printf("%s\n",now);
        lim = min(save+1,int ( strlen(now) ) );
        strcpy(prv,now);
    }

    if ( kase )printf("\n");

    }
    return 0;
}

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

#define SIZE 10100

int qq[SIZE];
char arr[SIZE];

bool cutle[SIZE],cutri[SIZE];
bool le[26],ri[26];

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    while ( kase-- ){
        int x;
        scanf("%d",&x);

        for (int i=0;i<x;++i){
            scanf("%d",&qq[i]);
        }
        scanf("%s",arr);

        CLR(cutle);
        CLR(cutri);

        int ans= 0;

        for (int i=0;i<x;++i){

            int tmp= qq[i]-1;

            CLR(le);
            CLR(ri);

            for (int i=tmp;i>=0 && !cutri[i] ;--i){
                if ( !le[ arr[i]-'a' ] )
                    le[ arr[i]-'a' ]= true;
            }

            for (int i=tmp+1;arr[i] && !cutle[i] ;++i){
                if ( !ri[ arr[i]-'a' ] )
                    ri[ arr[i]-'a' ]= true;
            }


            for (int i=0;i<26;++i){
                if ( (le[i] && !ri[i]) || (!le[i] && ri[i]) ){
                    ++ans;
                }
            }

            cutri[ tmp ] = true;
            cutle[ tmp+1 ] = true;


        }

        printf("%d\n",ans);

    }


    return 0;
}

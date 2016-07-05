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

struct qq{
    int type;
    int item,trans;
}query[SIZE];

mint transmp,itemmp;

set<int> itembelong[SIZE];
bool transok[SIZE];
bool xclusive[SIZE];

int main(){

    //FRO
    //freopen("out1.txt","w",stdout);

    int kase;
    scanf("%d",&kase);

    while ( kase-- ){

    transmp.clear();
    itemmp.clear();

    for (int i=0;i<SIZE;++i){
        itembelong[i].clear();
        xclusive[i]=false;
        transok[i] = true;
    }

    char ttt[5];

    int q=0;
    int u,v;
    while ( scanf("%s",ttt)==1 && ttt[0] != '#' ){
        qq tmp;
        if ( ttt[0] == 'S' ){
            tmp.type = 1;
        }else{
            tmp.type = 2;
        }

        scanf("%d %d",&u,&v);
        tmp.trans= u;
        tmp.item = v;

        query[ q++ ] = tmp;

        transmp[u];
        itemmp[v];
    }

    int tmp=0;
    snuke( transmp ,itr ){
        itr->second = tmp++;
    }
    tmp=0;
    snuke( itemmp ,itr ){
        itr->second = tmp++;
    }

    for (int i=0;i<q;++i){
        query[i].trans = transmp[ query[i].trans ];
        query[i].item = itemmp[ query[i].item ];
    }


    for (int i=0;i<q;++i){
        u = query[i].trans;
        v = query[i].item;

        if ( !transok[ u ] ){
            printf("IGNORED\n");
            continue;
        }

        if ( query[i].type == 1 ){
            if ( !xclusive[v] || ( itembelong[v].size() == 1 && *itembelong[v].begin() == u ) ){
                printf("GRANTED\n");
                itembelong[v] .insert(u);
            }else{
                printf("DENIED\n");
                transok[u] = false;
            }
        }else{
            if ( itembelong[v].size() == 0 || ( itembelong[v].size() == 1 && *itembelong[v].begin() == u ) ){
                printf("GRANTED\n");
                itembelong[v].clear();
                itembelong[v].insert(u);
                xclusive[v] = true;
            }else{
                printf("DENIED\n");
                transok[u] = false;
            }
        }
    }

    if ( kase )printf("\n");

    }

    return 0;
}

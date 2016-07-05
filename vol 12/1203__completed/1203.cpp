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

struct st{
    int num,time,base;
    bool operator < (const st & p)const{
        if ( time!=p.time )
            return time>p.time;
        else
            return num>p.num;
    }
};

int main(){
    FRO


    char ttt[15];
    st me;
    while( scanf("%s",ttt)==1 ){

        priority_queue<st> pq;
        do{
            scanf("%d %d",&me.num,&me.time);
            me.base=me.time;
            pq.push( me );
        }while( scanf("%s",ttt)==1 && ttt[0]!='#' );

        int query;
        scanf("%d",&query);
        for (int i=0;i<query;++i){
            st tmp=pq.top();pq.pop();
            printf("%d\n",tmp.num);
            tmp.time+=tmp.base;
            pq.push( tmp );
        }

    }


    return 0;
}

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

int cost[3][12];

struct node{
    int val,city;
    int move;
    bool operator < (const node & p)const{
        if ( val!= p.val )
            return val>p.val;
        else
            return move>p.move;
    }
};

#define SIZE 100010
bool vis[SIZE+10];

pint dijkstra(int s,int f){

    CLR(vis);

    node place,temp,u;
    place.val=0;
    place.city=s;
    place.move=0;

    priority_queue<node> q;

    q.push(place);


    while (!q.empty()){
        temp=q.top();q.pop();
        if (temp.city==f)return make_pair( temp.val,temp.move );

        if ( temp.city>f ||  vis[temp.city])
            continue;
        vis[temp.city]=true;


        for (int i=0;i<10;++i){
            u.city=temp.city*10+i;
            u.move=temp.move+1;
            u.val=temp.val+cost[0][i];
            if ( u.city<=f && !vis[ u.city ] ){
                q.push(u);
            }
        }

        for (int i=1;i<10;++i){
            u.city=temp.city+i;
            u.move=temp.move+1;
            u.val=temp.val+cost[1][i];
            if ( u.city<=f && !vis[ u.city ] ){
                q.push(u);
            }
        }

        for (int i=2;i<10;++i){
            u.city=temp.city*i;
            u.move=temp.move+1;
            u.val=temp.val+cost[2][i];
            if ( u.city<=f && !vis[ u.city ] ){
                q.push(u);
            }
        }
    }
    return make_pair( INT_MAX,INT_MAX );
}

int main(){
    FRO

    int x,y;

    for ( int kk=1; scanf("%d %d",&x,&y)==2 ;++kk ){
        for (int i=0;i<3;++i){
            for (int j=0;j<10;++j){
                scanf("%d",&cost[i][j]);
            }
        }

        pint ans=dijkstra(x,y);
        pint tmp=dijkstra(0,y);
        tmp.first+= cost[2][0];
        tmp.second++;

        if ( tmp.first<ans.first ){
            ans=tmp;
        }else if ( tmp.first==ans.first ){
            ans.second=min( ans.second,tmp.second );
        }

        printf("Case %d: %d %d\n",kk,ans.first,ans.second);

    }


    return 0;
}

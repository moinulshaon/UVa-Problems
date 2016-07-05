#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

#define SIZE 10010

vector <int> edge[SIZE], cost[SIZE];
int total;

bool hotel[SIZE];
bool vis[SIZE][10*60+5];

struct node
{
    int val,city,carry;
    bool operator < (const node & p)const{return val>p.val;}
};


void dijkstra(int s,int f){

    node place,temp,u;
    place.val=0;
    place.city=s;
    place.carry=0;

    priority_queue<node> q;

    q.push(place);

    memset(vis,false,sizeof(vis));

    while (!q.empty()){
        temp=q.top();q.pop();


        if (vis[temp.city][temp.carry])
            continue;
        vis[temp.city][temp.carry]=true;
        //printf("%d %d %d\n",temp.city,temp.val,temp.carry);
        if (temp.city==f)break;
        for (int i=0;i<edge[temp.city].size();++i)
        {
            int cc=temp.carry+cost[ temp.city ][i];

            if ( cc>60*10 )continue;

            if ( hotel[ edge[ temp.city ][i] ] ){
                u.val=temp.val+1;
                u.carry=0;
                u.city=edge[temp.city][i];

                if ( !vis[u.city][u.carry] )
                    q.push(u);
            }



            u.val=temp.val;
            u.carry=cc;
            u.city=edge[temp.city][i];

            if ( !vis[u.city][u.carry] )
                    q.push(u);


        }
    }
    if (  temp.city==f ){
        printf("%d\n",temp.val);
    }else {
        printf("-1\n");
    }

}


int main()
{

    freopen("in.txt","r",stdin);
    int h;
    while( scanf("%d",&total)==1 && total ){

        scanf("%d",&h);
        memset(hotel,false,sizeof(hotel));
        int tmp;
        while( h-- ){
            scanf("%d",&tmp);
            hotel[tmp]=true;
        }

        for (int i=0;i<=total;++i){
            edge[i].clear();
            cost[i].clear();
        }

        int e;
        scanf("%d",&e);

        int x,y,w;
        while(e--){
            scanf("%d %d %d",&x,&y,&w);
            edge[x].push_back(y);
            cost[x].push_back(w);

            edge[y].push_back(x);
            cost[y].push_back(w);
        }
        dijkstra(1,total);
    }
    return 0;
}

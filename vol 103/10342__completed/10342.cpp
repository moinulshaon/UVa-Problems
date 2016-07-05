#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#define sz 110
#define ttt 10

using namespace std;

vector <int> edge[sz], cost[sz];
int total;

struct node
{
    int val,city;
    bool operator < (const node & p)const{return val>p.val;}
};


void dijkstra(int s,int f)
{

    int vis[sz]={0};

    node place,temp,u;
    place.val=0;
    place.city=s;

    int cnt=0;

    priority_queue<node> q;

    q.push(place);

    int save=-1;
    while (!q.empty())
    {
        temp=q.top();q.pop();

        if (vis[temp.city]==ttt)
            continue;
        vis[temp.city]++;

        if (temp.city==f){

            if (save!=temp.val)
                cnt++;
            save=temp.val;
            if (cnt==2)break;
        }


        for (int i=0;i<edge[temp.city].size();++i)
        {
            u.val=cost[temp.city][i]+temp.val;
            u.city=edge[temp.city][i];
            q.push(u);
        }
    }

    if (cnt==2)
        printf("%d\n",temp.val);
    else
        printf("?\n");

}


int main()
{

    freopen("in.txt","r",stdin);
    int ed;

    for (int m=1;scanf("%d %d",&total,&ed)==2;++m)
    {

        for (int i=0;i<sz;++i)
        {
            edge[i].clear();
            cost[i].clear();
        }

        int temp,temp2,temp3;
        while (ed--)
        {
            scanf("%d %d %d",&temp,&temp2,&temp3);
            edge[temp].push_back(temp2);
            edge[temp2].push_back(temp);
            cost[temp].push_back(temp3);
            cost[temp2].push_back(temp3);

        }

        printf("Set #%d\n",m);
        int query;

        scanf("%d",&query);

        while (query--){
            int s,f;
            scanf("%d %d",&s,&f);



            dijkstra(s,f);
        }
    }

    return 0;
}

#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector <int> edge[50010], cost[50010];

struct node
{
    int val,city;
    bool operator < (const node & p)const{return val>p.val;}
};


void dijkstra(int s,int f)
{

    bool vis[20010]={false};

    node place,temp,u;
    place.val=0;
    place.city=s;

    priority_queue<node> q;

    q.push(place);


    while (!q.empty())
    {
        temp=q.top();q.pop();
        if (temp.city==f)break;

        if (vis[temp.city])
            continue;
        vis[temp.city]=true;


        for (int i=0;i<edge[temp.city].size();++i)
        {
            u.val=cost[temp.city][i]+temp.val;
            u.city=edge[temp.city][i];
            q.push(u);
        }
    }



    if (temp.city==f)
        printf("%d\n",temp.val);
    else
        printf("unreachable\n");




}


int main()
{

    freopen("input.txt","r",stdin);

    int test,s,f,server,line;
    scanf("%d",&test);

    for (int m=1;m<=test;++m)
    {
        for (int i=0;i<50010;++i)
        {
            edge[i].clear();
            cost[i].clear();
        }


        scanf("%d %d %d %d",&server,&line,&s,&f);

        int temp,temp2,temp3;
        for (int i=0;i<line;++i)
        {
            scanf("%d %d %d",&temp,&temp2,&temp3);

            edge[temp].push_back(temp2);
            edge[temp2].push_back(temp);

            cost[temp].push_back(temp3);
            cost[temp2].push_back(temp3);
        }




        printf("Case #%d: ",m);
        dijkstra(s,f);
    }

    return 0;
}

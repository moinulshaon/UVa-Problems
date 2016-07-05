#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector <int> edge[12], cost[12];
int total;

struct node
{
    int val,city;
    vector <int> a;
    bool operator < (const node & p)const{return val>p.val;}
};


void dijkstra(int s,int f)
{

    bool vis[12]={false};

    node place,temp,u;
    place.val=0;
    place.city=s;
    place.a.push_back(s);


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
            u.a=temp.a;
            u.a.push_back(u.city);
            q.push(u);
        }
    }


    for (int i=0;i<temp.a.size();++i)
        printf(" %d",temp.a[i]);
    printf("; %d second delay\n",temp.val);



}


int main()
{

    freopen("input.txt","r",stdin);

    for (int m=1;;++m)
    {

        for (int i=0;i<12;++i)
        {
            edge[i].clear();
            cost[i].clear();
        }


        scanf("%d",&total);
        if (!total)return 0;

        int temp,temp2,temp3;
        for (int i=1;i<=total;++i)
        {

            scanf("%d",&temp);
            for (int j=1;j<=temp;++j)
            {
                scanf("%d %d",&temp2,&temp3);
                edge[i].push_back(temp2);
                cost[i].push_back(temp3);
            }
        }
        int s,f;
        scanf("%d %d",&s,&f);


        printf("Case %d: Path =",m);
        dijkstra(s,f);
    }

    return 0;
}

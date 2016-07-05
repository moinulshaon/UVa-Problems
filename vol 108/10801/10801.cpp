#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <sstream>


using namespace std;

vector <int> edge[205], cost[205];

struct node
{
    int val,city;
    bool operator < (const node & p)const{return val>p.val;}
};


void dijkstra(int s,int f)
{

    bool vis[12]={false};

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


    printf("%d\n",temp.val);



}


int main()
{

    freopen("input.txt","r",stdin);

    int n,k,arr[205];
    while (scanf("%d %d",&n,&k)==2)
    {

        for (int i=0;i<205;++i)
        {
            edge[i].clear();
            cost[i].clear();
        }
        for (int i=0;i<n;++i)
            scanf("%d",&arr[i]);

        char line[500];
        for (int i=0;i<n;++i)
        {
            gets(line);
            stringstream ss ( line );

            int temp;

            while (ss>>temp)
            {
                edge[0].push_back(temp);
                cost[0].push_back(temp3);
            }
        }




        dijkstra(0,k);








/*        int temp,temp2,temp3;
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
        dijkstra(s,f);*/
    }

    return 0;
}

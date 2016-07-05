#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

vector<int> edge[1000000], cost[1000000];
const int infinity = 1000000000;
int d[1000000];
bool vis[1000000];

//edge[i][j] = jth node connected with i
//cost[i][j] = cost of that edge
int row,col,cityn;
int arr[1010][1010];

struct data {
    int city, dist;
    bool operator < ( const data& p ) const {
        return dist > p.dist;
    }
};

int dijkstra(int source, int destination) {

    memset(vis,false,sizeof(vis));
    vis[0]=true;
    for(int i=0; i<1000000; i++) d[i] = infinity;

    priority_queue<data> q;
    data u, v;
    u.city = source, u.dist = 0;
    q.push( u );
    d[ source ] = arr[0][0];

    while( !q.empty() && !vis[destination]) {
        u = q.top(); q.pop();
        int ucost = d[ u.city ];

        for(int i=0; i<edge[u.city].size(); i++) {
            v.city = edge[u.city][i], v.dist = cost[u.city][i] + ucost;
            if( d[v.city] > v.dist && !vis[v.city]) {
                d[v.city] = v.dist;
                q.push( v );
                vis[v.city]=true;
            }
        }
    }

    return d[ destination ];
}


int main()
{
    int cases;

    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    scanf("%d",&cases);

    while (cases--)
    {
        scanf("%d %d",&row,&col);
        for (int i=0;i<row;i++)
            for (int j=0;j<col;++j)
                scanf("%d",&arr[i][j]);

        cityn=0;

        for (int i=0;i<1000000;++i)
        {
            edge[i].clear();
            cost[i].clear();
        }

        for (int i=0;i<row;i++)
        {

            for (int j=0;j<col;++j)
            {
                if (j+1<col)
                {
                    edge[cityn].push_back(cityn+1);
                    cost[cityn].push_back(arr[i][j+1]);
                }
                if (j-1>=0)
                {
                    edge[cityn].push_back(cityn-1);
                    cost[cityn].push_back(arr[i][j-1]);
                }
                if (i+1<row)
                {
                    edge[cityn].push_back(cityn+col);
                    cost[cityn].push_back(arr[i+1][j]);
                }
                if (i-1>=0)
                {
                    edge[cityn].push_back(cityn-col);
                    cost[cityn].push_back(arr[i-1][j]);
                }
                ++cityn;
            }
        }

        printf("%d\n",dijkstra(0,cityn-1));

    }
    return 0;

}

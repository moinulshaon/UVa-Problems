#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#define INF 10000000

using namespace std;


bool existairport[2010];


struct city
{
    int val;
    vector <int> connected;
};



int main()
{

    freopen("input.txt","r",stdin);

    int test;
    scanf("%d",&test);

    int a,b,N,M,K,temp;
    for (int m=1;m<=test;++m)
    {
        scanf("%d %d %d",&N,&M,&K);

        printf("Case %d:\n",m);

        memset(existairport,false,sizeof(existairport));
        struct city map[2010];
        memset(map,0,sizeof(map));

        while (K--)
        {
            scanf("%d",&temp);
            existairport[temp]=true;
        }
        while (M--)
        {
            scanf("%d %d",&a,&b);
            map[a].connected.push_back(b);
            map[b].connected.push_back(a);
        }
        scanf("%d",&K);
        while (K--)
        {
            scanf("%d %d",&a,&b);

            queue <city> q;

            for (int i=0;i<=N;++i)
                map[i].val=INF;
            if (!existairport[a])
                map[a].val=1;
            else
                map[a].val=0;
            q.push(map[a]);

            while (!q.empty())
            {
                city t=q.front();
                q.pop();

                for (int i=0;i<t.connected.size();++i)
                {
                    if(t.val+(!existairport[t.connected[i]]) < map[t.connected[i]].val)
                    {
                        map[t.connected[i]].val=t.val+(!existairport[t.connected[i]]);
                        q.push(map[t.connected[i]]);
                    }
                }
            }
            if (a==b)
                printf("0\n");
            else if (map[b].val!=INF)
                printf("%d\n",map[b].val);
            else
                printf("-1\n");


        }
        printf("\n");
    }
    return 0;

}

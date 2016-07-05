#include <cstdio>
#include <queue>
#include <map>
#include <cstring>
#include <iostream>

using namespace std;





int main()
{


    int edges,cases=1;


    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    while(1)
    {
        map<int,int> index;

        bool matrix[35][35]={0};

        scanf("%d",&edges);

        if (!edges)return 0;

        int nodeNumber=1;
        for(int i=0;i<edges;++i)
        {
            int a,b;

            scanf("%d %d",&a,&b);

            if (!index[a]) index[a]=nodeNumber++;
            if (!index[b]) index[b]=nodeNumber++;

            matrix[ index[a] ][ index[b] ]=matrix[ index[b] ][ index[a] ]=true;

        }


        int ttl,input;

        while(1)
        {
            scanf("%d %d",&input,&ttl);

            if (!input && !ttl)break;



            int dist[35];

            for (int i=0;i<35;++i)
                dist[i]= -1;

            dist[index[input]]=0;

            queue <int> q;

            q.push(index[input]);
            while(!q.empty())
            {
                int temp=q.front();
                q.pop();

                for (int i=1;i<nodeNumber;++i)
                {
                    if (dist[i]== -1 && matrix[temp][i])
                    {
                        dist[i]=dist[temp]+1;
                        q.push(i);
                    }
                }
            }
            int cnt=0;
            for (int i=1;i<nodeNumber;++i)
                if (dist[i]==-1 || dist[i]>ttl)
                    ++cnt;
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",cases++,cnt,input,ttl);

        }


    }


}

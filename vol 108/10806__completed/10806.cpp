#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#define INF 2147483647
//#define INF 1000
#define sz 120

using namespace std;

int total;
int d[sz][sz];
bool vis[sz];

struct node
{
    int val,city;
    vector <int> a;
    bool operator < (const node & p)const{return val>p.val;}
};

int dijsktra(int source,int destination)
{
    memset(vis,false,sizeof(vis));

    node place,temp,u;
    place.val=0;
    place.city=source;
    place.a.push_back(source);



    priority_queue<node> q;

    q.push(place);


    while (!q.empty())
    {
        temp=q.top();q.pop();
        if (temp.city==destination)
        {
            vis[destination]=true;
            break;
        }

        if (vis[temp.city])
            continue;
        vis[temp.city]=true;


        for (int i=1;i<=total;++i)
        {
            if (d[temp.city][i]!=INF)
            {
                u.val=d[temp.city][i]+temp.val;
                u.city=i;
                u.a=temp.a;
                u.a.push_back(u.city);
                q.push(u);
            }
        }
    }

    if (vis[destination])
    {
        int tmp=temp.a.size()-1;
        for (int i=0;i<tmp;++i)
        {
            d[ temp.a[i] ] [ temp.a[i+1] ]=INF;
            d[ temp.a[i+1] ][ temp.a[i] ]=-d[ temp.a[i+1] ][ temp.a[i] ];
        }

        return temp.val;
    }
    else
        return INF;

}



int main()
{

    freopen("in.txt","r",stdin);

    while (true)
    {
        scanf("%d",&total);
        if (!total)return 0;

        for (int i=1;i<=total;++i)
            for (int j=1;j<=total;++j)
                d[i][j]=INF;

        int edges,a,b,c;
        scanf("%d",&edges);
        while (edges--)
        {
            scanf("%d %d %d",&a,&b,&c);
            d[a][b]=d[b][a]=c;
        }
        if (  (a=dijsktra(1,total))!=INF &&  (b=dijsktra(1,total))!=INF )
            printf("%d\n",a+b);
        else
            printf("Back to jail\n");
    }
}

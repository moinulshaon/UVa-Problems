#include <cstdio>
#include <map>
#include <cstring>
#include <vector>
#define sz 10

using namespace std;

vector <int> outedges[sz];
vector <int> inedges[sz];
bool vis[sz];
int edges;
bool tree;


void dfs(int k)
{
    if (vis[k])
    {
        tree=false;

    }
    if (!tree)return ;

    vis[k]=true;
    for (int i=0;i<outedges[k].size() ;++i)
            dfs(outedges[k][i]);
}


int main()
{

    freopen("prob_2.in","r",stdin);

    int total,a,b;
    for (int m=1;scanf("%d %d",&a,&b)==2;++m)
    {


        if (a==-1 && b==-1)return 0;
        if (!a && !b)
        {
            printf("Case %d is a tree.\n",m);
            continue;
        }
        for (int i=0;i<sz;++i)
        {
            inedges[i].clear();
            outedges[i].clear();
        }


        map <int,int> ind;

        total=0;

        if (ind.find(a)==ind.end())ind[a]=total++;
        if (ind.find(b)==ind.end())ind[b]=total++;

        outedges [ ind[a] ].push_back(ind [b] );
        inedges [ ind[b] ].push_back(ind [a] );

        for ( edges=1;;++edges)
        {
            scanf("%d %d",&a,&b);

            if (!a && !b)break;

            if (ind.find(a)==ind.end())ind[a]=total++;
            if (ind.find(b)==ind.end())ind[b]=total++;

            outedges [ ind[a] ].push_back(ind [b] );
            inedges [ ind[b] ].push_back(ind [a] );
        }


        for (int i=0;i<total;++i)
            vis[i]=false;

        int root=-1;

        for (int i=0;i<total;++i)
        {
            if (inedges[i].size()==0)
            {
                root=i;
                break;
            }

        }
        if (root==-1)
        {

            printf("Case %d is not a tree.\n",m);
            continue;
        }
        tree=true;

        dfs(root);
        if (!tree)
        {
            printf("Case %d is not a tree.\n",m);
            continue;
        }

        for (int i=0;i<total;++i)
            if (!vis[i])
            {
                tree=false;
                break;
            }

        if (tree)
            printf("Case %d is a tree.\n",m);
        else
            printf("Case %d is not a tree.\n",m);
    }
    return 0;
}

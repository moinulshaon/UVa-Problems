#include <cstdio>
#include <map>
#include <cstring>
#define size 100000

using namespace std;

int arr1[size],arr2[size];
bool vis[size];
int edges;
bool tree;


void dfs(int k)
{
    if (vis[k])
        tree=false;
    if (!tree)return ;

    vis[k]=true;
    for (int i=0;i<edges;++i)
    {
        if (arr1[i]==k)
            dfs(arr2[i]);
    }
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


        map <int,int> ind;
        total=0;

        if (ind.find(a)==ind.end())ind[a]=total++;
        if (ind.find(b)==ind.end())ind[b]=total++;

        arr1[0]=ind[a];
        arr2[0]=ind[b];

        for ( edges=1;;++edges)
        {
            scanf("%d %d",&a,&b);

            if (!a && !b)break;

            if (ind.find(a)==ind.end())ind[a]=total++;
            if (ind.find(b)==ind.end())ind[b]=total++;

            arr1[edges]=ind[a];
            arr2[edges]=ind[b];
        }


        for (int i=0;i<total;++i)
            vis[i]=false;

        int root=-1;

        for (int i=0;i<total;++i)
        {
            bool in=false;
            for (int j=0;j<edges;++j)
                if (arr2[j]==i)
                {
                    in=true;
                    break;
                }
            if (!in)
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

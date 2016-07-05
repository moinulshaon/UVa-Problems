#include <cstdio>
#include <vector>

using namespace std;

vector <int> v[110];
bool vis[110];


void dfs(int a)
{
    for (int i=0;i<v[a].size();++i)
    {
        if (!vis[v[a][i]])
        {
            vis[v[a][i]]=true;
            dfs(v[a][i]);
        }

    }
}


int main()
{

    freopen("input.txt","r",stdin);

    int input;

    while (true)
    {
        scanf("%d",&input);
        if (!input)return 0;

        for (int i=1;i<=input;++i)
        {
            v[i].clear();
            vis[i]=false;
        }

        int n,a;
        for (int i=1;i<=input;++i)
        {
            scanf("%d",&n);
            while (n--)
            {
                scanf("%d",&a);
                v[i].push_back(a);
            }
        }
        int max=0,temp,result;

        for (int i=1;i<=input;++i)
        {
            temp=0;

            for (int j=0;j<v[i].size();++j)
            {
                if (!vis[v[i][j]])
                {
                    vis[v[i][j]]=true;
                    dfs(v[i][j]);
                }
            }


            for (int j=1;j<=input;++j)
            {
                if (vis[j])
                {
                    ++temp;
                    vis[j]=false;
                }
            }
            if (temp>max)
            {
                max=temp;
                result=i;
            }
        }
        printf("%d\n",result);
    }
}

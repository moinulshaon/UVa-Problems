#include <cstdio>
#include <iostream>
#include <queue>
#include <sstream>
#define si 1000

using namespace std;

int n;

struct nodes
{
    int pos;
    vector <int> v;
};

vector <int> mat[si];
bool vis[si];

void bfs(int start,int finish)
{
    queue <nodes> q;
    nodes temp;
    temp.pos=start;
    temp.v.push_back(start);
    for (int i=0;i<=n;++i)
        vis[i]=false;

    q.push(temp);

    while (!q.empty())
    {
        temp=q.front();
        q.pop();
        if (temp.pos==finish)
        {
            vis[temp.pos]=true;
            break;
        }
        else if (vis[temp.pos])continue;
        vis[temp.pos]=true;

        for (int i=0;i<mat[temp.pos].size();++i)
        {
            nodes tt;
            tt.pos=mat[temp.pos][i];
            tt.v=temp.v;
            tt.v.push_back(tt.pos);
            q.push(tt);
        }
    }
    if (!vis[finish])
        printf("connection impossible\n");
    else
    {
        printf("%d",temp.v[0]);
        for (int i=1;i<temp.v.size();++i)
            printf(" %d",temp.v[i]);
        printf("\n");
    }
    return ;

}


int main()
{
    freopen("in.txt","r",stdin);

    string str;

    while (scanf("%d",&n)==1)
    {
        getchar();

        for (int i=0;i<=n;++i)
            mat[i].clear();

        for (int i=0;i<n;++i)
        {
            int n;
            getline(cin,str);

            istringstream sstr(str);
            int id,temp;
            char c;
            sstr>>id;

            while (sstr>>c && sstr>> temp)
                mat[id].push_back(temp);


        }
        int query,start,finish;
        scanf("%d",&query);

        printf("-----\n");
        while (query--)
        {
            scanf("%d %d",&start,&finish);
            bfs(start,finish);

        }
    }
    return 0;

}

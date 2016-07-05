#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

int start,finish,button;
int value[15];
bool vis[10010];

struct state
{
    int now;
    int move;
};


int main()
{
    int cases=1;
    while (true)
    {
        scanf("%d %d %d",&start,&finish,&button);
        if (!start && !finish && !button)return 0;

        for (int i=0;i<button;++i)
            scanf("%d",&value[i]);

        state begin,tmp,tt;
        begin.now=start;
        begin.move=0;

        memset(vis,false,sizeof(vis));

        queue<state> q;
        q.push(begin);
        vis[begin.now]=true;

        while ( !q.empty() )
        {
            tmp=q.front();
            q.pop();

            if (tmp.now==finish)break;


            for (int i=0;i<button;++i)
            {
                tt.now=(tmp.now+value[i])%10000;
                tt.move=tmp.move+1;

                if (!vis[tt.now])
                {
                    q.push(tt);
                    vis[tt.now]=true;
                }
            }
        }
        if (vis[finish])
            printf("Case %d: %d\n",cases++,tmp.move);
        else
            printf("Case %d: Permanently Locked\n",cases++);

    }
}

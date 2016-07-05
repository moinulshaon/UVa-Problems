#include <cstdio>
#include <vector>
#define N 1000100
using namespace std;

vector <int> outarrow [N + 10];
vector <int> inarrow [N + 10];
bool vis [N + 10];
vector <int> stk;
int component [N + 10];


void dfs1 (int x)
{
	vis [x] = true;

	for ( int u = 0; u < outarrow [x].size (); u++ )
		if ( !vis [ outarrow [x] [u]] )
            dfs1 (outarrow [x] [u]);

	stk.push_back (x);
}

void dfs2 (int x, int c)
{
	vis [x] = false;
	component [x] = c;

	for ( int u = 0; u < inarrow [x].size (); u++ )
		if ( vis [inarrow [x] [u]] )
            dfs2 (inarrow [x] [u], c);
}

int main ()
{
	while (true)
	{
		int n, m;
		scanf ("%d %d", &n, &m);

        if (!n && !m)return 0;

        for ( int i = 0; i <= n ; i++ )
        {
            outarrow [i].clear ();
            inarrow [i].clear ();
            vis[i]=false;
        }

        stk.clear ();

		for ( int i = 0; i < m; i++ )
		{
			int a, b;
			scanf ("%d %d", &b, &a);
			outarrow [a].push_back (b);
			inarrow [b].push_back (a);
		}

		for ( int i = 1; i <= n; i++ )
			if ( !vis [i] )
                dfs1 (i);

		int c = 0;

		for ( int i = stk.size () - 1; i >= 0; i-- )
			if ( vis [stk [i]] )
                dfs2 (stk [i], ++c);

        if (c!=n)
            printf("IMPOSSIBLE\n");
        else
        {
            int tmp=stk.size();
            for (int i=0;i<tmp;++i)
                printf("%d\n",stk[i]);
        }
	}
}

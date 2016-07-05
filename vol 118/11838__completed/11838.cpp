#include <cstdio>
#include <vector>
#define N 2010
using namespace std;

vector <int> outarrow [N];
vector <int> inarrow [N ];
bool vis [N];
vector <int> stk;

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

	for ( int u = 0; u < inarrow [x].size (); u++ )
		if ( vis [inarrow [x] [u]] )
            dfs2 (inarrow [x] [u], c);
}

int main ()
{
	while ( true )
	{
		int n, m;
		scanf ("%d %d", &n, &m);

        if (!n && !m)return 0;

        for ( int i = 0; i < n ; i++ )
        {
            outarrow [i].clear ();
            inarrow [i].clear ();
            vis[i]=false;

        }

        stk.clear ();

		for ( int i = 0; i < m; i++ )
		{
			int a, b,tt;
			scanf ("%d %d %d", &a, &b, &tt);
            --a;
            --b;

			if (tt==1)
			{
                outarrow [a].push_back (b);
                inarrow [b].push_back (a);
			}
			else
			{
			    outarrow [a].push_back (b);
                inarrow [b].push_back (a);

                outarrow [b].push_back (a);
                inarrow [a].push_back (b);
			}
		}

		for ( int i = 0; i < n; i++ )
			if ( !vis [i] )
                dfs1 (i);

		int c = 0;

		for ( int i = stk.size () - 1; i >= 0; i-- )
			if ( vis [stk [i]] )
                dfs2 (stk [i], ++c);
        if (c==1)
            printf("1\n");
        else
            printf("0\n");

	}
}

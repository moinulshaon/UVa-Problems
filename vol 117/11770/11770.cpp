#include <cstdio>
#include <vector>
#define N 10005
using namespace std;

vector <int> outarrow [N + 10];
vector <int> inarrow [N + 10];
bool vis [N + 10];
vector <int> stk;
int component [N + 10];
bool in [N + 10];



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
	int testCase;
	scanf ("%d", &testCase);

	for (int kk=1; testCase-- ;++kk)
	{
		int n, m;
		scanf ("%d %d", &n, &m);

        for ( int i = 0; i <= n ; i++ )
        {
            outarrow [i].clear ();
            inarrow [i].clear ();
            vis[i]=false;
            in[i]=false;
        }

        stk.clear ();

		for ( int i = 0; i < m; i++ )
		{
			int a, b;
			scanf ("%d %d", &a, &b);
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

		for ( int i = 1; i <= n; i++ )
			for ( int j = 0; j < outarrow [i].size (); j++ )
				if ( component [i] != component [outarrow [i] [j]] )
					in [component [outarrow [i] [j]]]=true;


		int cnt = 0;

		for ( int i = 1; i <= c; i++ )
			if ( !in [i] )
                cnt++;

		printf("Case %d: %d\n",kk,cnt );
	}

	return 0;
}

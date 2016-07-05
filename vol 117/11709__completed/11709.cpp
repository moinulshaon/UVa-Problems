#include <iostream>
#include <string>
#include <cstdio>
#include <map>
#include <vector>
#define N 1005
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
    freopen("in.txt","r",stdin);

	while (true)
	{
		int n, m;
		scanf ("%d %d", &n, &m);

        if (!n && !m)return 0;

        getchar();

        for ( int i = 0; i <= n ; i++ )
        {
            outarrow [i].clear ();
            inarrow [i].clear ();
            vis[i]=false;
        }


        map<string,int> mymap;
        string a,b;

        for (int i=1;i<=n;++i)
        {
            getline(cin,a);
            mymap[a]=i;
        }


        stk.clear ();

		for ( int i = 0; i < m; i++ )
		{
			getline(cin,a);
			getline(cin,b);
			outarrow [  mymap[a]  ].push_back ( mymap[b] );
			inarrow [ mymap[b] ].push_back (  mymap[a] );
		}

		for ( int i = 1; i <= n; i++ )
			if ( !vis [i] )
                dfs1 (i);

		int c = 0;

		for ( int i = stk.size () - 1; i >= 0; i-- )
			if ( vis [stk [i]] )
                dfs2 (stk [i], ++c);

		printf("%d\n",c );
	}

	return 0;
}

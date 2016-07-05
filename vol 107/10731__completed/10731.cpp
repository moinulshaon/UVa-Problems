#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define N 26
using namespace std;

vector <int> outarrow [N];
vector <int> inarrow [N];
bool vis [N];
vector <int> stk;
vector <char> component [N];
bool on[N];




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
	component [c].push_back( x+'A');

	for ( int u = 0; u < inarrow [x].size (); u++ )
		if ( vis [inarrow [x] [u]] )
            dfs2 (inarrow [x] [u], c);
}

int main ()
{

    freopen("in.txt","r",stdin);

    int n;
    bool notfirst=false;;
	while (true)
	{
		int n;
		scanf ("%d", &n);

        if (!n)return 0;

        if (notfirst)
            printf("\n");
        notfirst=true;

        for ( int i = 0; i <N ; i++ )
        {
            outarrow [i].clear ();
            inarrow [i].clear ();
            component [i].clear();
            vis[i]=false;
            on[i]=false;
        }

        stk.clear ();

		for ( int i = 0; i < n; i++ )
		{
			char c[6];
			for (int i=0;i<6;++i)
                cin>>c[i];
            for (int i=0;i<5;++i)
            {
                if (c[i]!=c[5])
                {
                    outarrow[ c[5]-'A' ].push_back(c[i]-'A');
                    inarrow[ c[i]-'A' ].push_back(c[5]-'A');
                }
                on[ c[i]-'A' ]=true;
            }

		}

		for ( int i = 0; i < 26; i++ )
			if ( !vis [i] && on[i] )
                dfs1 (i);

		int c = 0;

		for ( int i = stk.size () - 1; i >= 0; i-- )
			if ( vis [ stk [i] ] )
                dfs2 (stk [i], c++);

        for (int i=0;i<c;++i)
            if ( component[i].size() >1 )
                sort( component[i].begin() ,component[i].end() );


        sort( component ,component+c );

        for (int i=0;i<c;++i)
        {
            printf("%c",component[i][0]);
            for (int j=1; j<component[i].size(); ++j)
            {
                printf(" %c",component[i][j]);
            }
            printf("\n");
        }
	}

	return 0;
}

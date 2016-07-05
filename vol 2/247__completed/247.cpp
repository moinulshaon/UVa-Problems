#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#define N 26
using namespace std;

vector <int> outarrow [N];
vector <int> inarrow [N];
bool vis [N];
vector <int> stk;
vector <int> component [N];

map <int,string> rmyp;

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
	component [c].push_back( x );

	for ( int u = 0; u < inarrow [x].size (); u++ )
		if ( vis [inarrow [x] [u]] )
            dfs2 (inarrow [x] [u], c);
}

int main ()
{

    freopen("in.txt","r",stdin);

    int n,m;
    bool notfirst=false;;
	for (int kk=1; true ;++kk)
	{
		int n;
		scanf ("%d %d", &n ,&m);

        if (!n && !m)return 0;

        if (notfirst)
            printf("\n");
        notfirst=true;

        printf("Calling circles for data set %d:\n",kk);

        for ( int i = 0; i <n ; i++ )
        {
            outarrow [i].clear ();
            inarrow [i].clear ();
            component [i].clear();
            vis[i]=false;
        }

        stk.clear ();

        rmyp.clear();
        map <string,int> myp;
        int node=0;

		while ( m-- )
		{
			string a,b;
			cin>>a>>b;

            if ( myp.find(a)==myp.end() )
            {
                rmyp[node]=a;
                myp[a]=node++;
            }
            if ( myp.find(b)==myp.end() )
            {
                rmyp[node]=b;
                myp[b]=node++;
            }

            outarrow[ myp[a] ].push_back( myp[b] );
            inarrow[ myp[b] ].push_back( myp[a] );

		}

		for ( int i = 0; i < n; i++ )
			if ( !vis [i] )
                dfs1 (i);

		int c = 0;

		for ( int i = stk.size () - 1; i >= 0; i-- )
			if ( vis [ stk [i] ] )
                dfs2 (stk [i], c++);


        for (int i=0;i<c;++i)
        {
            for (int j=0; j<component[i].size()-1; ++j)
            {
                cout<<rmyp[ component[i][j] ]<<", ";
            }
            cout<<rmyp[ component[i][ component[i].size()-1 ] ]<<endl;
        }
	}

	return 0;
}

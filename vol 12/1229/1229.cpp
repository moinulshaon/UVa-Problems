#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#define N 105
#define INF 10000000
using namespace std;

vector <int> outarrow [N];
vector <int> inarrow [N ];
vector <int> stk;
vector <int> component [N];
bool vis[N];
map <string,int> myp;


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
	component [c].push_back(x);

	for ( int u = 0; u < inarrow [x].size (); u++ )
		if ( vis [inarrow [x] [u]] )
            dfs2 (inarrow [x] [u], c);
}

int main ()
{
    freopen("in.txt","r",stdin);
	while ( true )
	{
		int n;
		scanf ("%d", &n);
        getchar();
		if (!n)return 0;

        for ( int i = 0; i <= n ; i++ )
        {
            outarrow [i].clear ();
            inarrow [i].clear ();
            component[i].clear();
            vis[i]=false;
        }

        stk.clear ();

        int node=0;

        myp.clear();
        map <int,string> rmyp;

		for ( int i = 0; i < n; i++ )
		{
			string a,b;
			getline(cin,a);

			stringstream sstr(a);

            sstr>>a;

            if (myp.find(a)==myp.end())
            {
                rmyp[node]=a;
                myp[a]=node++;
            }
            while (sstr>>b)
            {
                if (myp.find(b)==myp.end())
                {
                    rmyp[node]=b;
                    myp[b]=node++;
                }

                outarrow [ myp[a] ].push_back (myp[b]);
                inarrow [ myp[b] ].push_back (myp[a]);
            }
		}

		for ( int i = 0; i < n; i++ )
			if ( !vis [i] )
                dfs1 (i);

		int c = 0;

		for ( int i = stk.size () - 1; i >= 0; i-- )
			if ( vis [stk [i]] )
                dfs2 (stk [i], c++);
        int mn=INF,ind=0;
        for (int i=0;i<c;++i)
            if (component[i].size()>1 && component[i].size()<mn)
            {
                mn=component[i].size();
                ind=i;
            }
        sort(component[ind].begin(),component[ind].end());

        printf("%d\n",component[ind].size() );
        for (int i=0;i<component[ind].size()-1;++i)
            cout<<rmyp[ component[ind][i] ]<<' ';
        cout<<rmyp[ component[ind][ component[ind].size()-1 ] ]<<endl;
	}

}

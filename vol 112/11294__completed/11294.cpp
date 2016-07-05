#include <cstdio>
#include <cstring>
#include <vector>
#define N 1000
using namespace std;

vector <int> outarrow [N + 10];
vector <int> inarrow [N + 10];
bool vis [N + 10];
vector <int> stk;
int component [N + 10];

char check[N+10];


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
void dfs3( int u ,int ss){
    //printf("%d\n",u);

    check[u]=ss;
    check[u^1]=!ss;
    if ( ss ){
        for (int i=0;i<outarrow[u].size();++i){
            if ( check[ outarrow[u][i] ]==-1 ){
                dfs3( outarrow[u][i] , 1 );
            }
        }
    }else{
        for (int i=0;i<outarrow[u^1].size();++i){
            if ( check[ outarrow[u^1][i] ]==-1 ){
                dfs3( outarrow[u^1][i] , 1 );
            }
        }
    }

}


int main ()
{
    freopen("in.txt","r",stdin);

    int  m,n;
	while ( scanf ("%d %d", &n, &m)==2 ){

		if ( !n && !m )return 0;
        n<<=1;

        for ( int i = 0; i <= n ; i++ ){
            outarrow [i].clear ();
            inarrow [i].clear ();
            vis[i]=false;
        }

        stk.clear ();
        char mm[3],mmm[3];
		int a, b;
		for ( int i = 0; i < m; i++ ){
			scanf ("%d%s %d%s", &a,mm, &b,mmm);
			a<<=1;
			b<<=1;
			if ( mm[0]=='w'){
                ++a;
			}
			if ( mmm[0]=='w'){
                ++b;
			}
			outarrow [a].push_back (b^1);
			inarrow [b^1].push_back (a);

			outarrow [b].push_back (a^1);
			inarrow [a^1].push_back (b);
		}
        outarrow[1].push_back(0);
        inarrow[0].push_back(1);


		for ( int i = 0; i < n; i++ )
			if ( !vis [i] )
                dfs1 (i);

		int c = 0;

		for ( int i = stk.size () - 1; i >= 0; i-- )
			if ( vis [stk [i]] ){
                dfs2 (stk [i], ++c);
			}
        bool pos=true;
        for (int i=0;i<n;i+=2){
            if ( component[i]==component[i+1] ){
                pos=false;
                break;
            }
        }
        if ( !pos ){
            printf("bad luck\n");
        }else{
            memset(check,-1,sizeof(check));

            for ( int i = stk.size () - 1; i >= 0; i-- ){
                //printf("%d %d\n",stk[i],component[ stk[i] ]);
                if ( check[ stk[i] ]== -1 ){
                    dfs3(  stk[i] , 0 );
                    //printf("%d\n",stk[i]);
                }

            }
            bool on=false;
            for(int i=2; i <n; i++){
                if(check[i] == check[ 1 ]){
                    if  ( on )printf(" ");
                    printf("%d",i>>1);
                    if ( i%2 ){
                        printf("w");
                    }else{
                        printf("h");
                    }
                    on=true;
                }
            }

            printf("\n");

        }


	}

	return 0;
}

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define MUL2(x) (2*(x))

using namespace std;

#define SIZE 400

int row,col;

vector <int> outarrow [SIZE + 10];
vector <int> inarrow [SIZE + 10];
bool vis [SIZE + 10];
vector <int> stk;
int component [SIZE  + 10];



void dfs1 (int x){
	vis [x] = true;

	for ( int u = 0; u < outarrow [x].size (); u++ )
		if ( !vis [ outarrow [x] [u]] )
            dfs1 (outarrow [x] [u]);

	stk.push_back (x);
}

void dfs2 (int x, int c){
	vis [x] = false;
	component [x] = c;

	for ( int u = 0; u < inarrow [x].size (); u++ )
		if ( vis [inarrow [x] [u]] )
            dfs2 (inarrow [x] [u], c);
}

void addor(int a,int b){
    outarrow[a^1].push_back(b);
    inarrow[b].push_back(a^1);

    outarrow[b^1].push_back(a);
    inarrow[a].push_back(b^1);
}

bool twosat(int node){
    for (int i=0;i<node;i+=2){
        if ( component[i] == component[i^1] ){
            return false;
        }
        //printf("%d %d\n",component[i],component[i^1]);
    }
    return true;
}

void func( int x ){
    printf("it is a %s ",( x<MUL2(row) )?"row":"col",x);
    printf("%d going to %s\n",x/2,(x%2==0)?"way":"opposite way");


}

int main(){
    freopen("in.txt","r",stdin);
    int kase,edge,r1,r2,c1,c2;
    scanf("%d",&kase);

    while(kase--){
        scanf("%d %d %d",&row,&col,&edge);

        for (int i=0;i<MUL2(row+col);++i){
            outarrow [i].clear ();
            inarrow [i].clear ();
            vis[i]=false;
        }


        while(edge--){
            scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
            r1--;
            r2--;
            c1+=row-1;
            c2+=row-1;
            r1=MUL2(r1);
            r2=MUL2(r2);

            c1=MUL2(c1);
            c2=MUL2(c2);

            if ( c2<c1 ){
                r1=r1^1;
                r2=r2^1;
            }
            if ( r2<r1 ){
                c1=c1^1;
                c2=c2^1;
            }

            if ( c1!=c2 ){
                addor( r1,r2 );
            }
            if ( c1!=c2 && r1!=r2  ){
                addor( r1,c1 );
            }
            if ( c1!=c2 && r1!=r2  ){
                addor( c2,r2 );
            }
            if ( r1!=r2 ){
                addor( c1,c2 );
            }
        }


        stk.clear();
		for ( int i = 0; i < MUL2(row+col); i++ )
			if ( !vis [i] )
                dfs1 (i);

		int c = 0;

		for ( int i = stk.size () - 1; i >= 0; i-- )
			if ( vis [stk [i]] )
                dfs2 (stk [i], ++c);

        if ( twosat( MUL2(row+col) ) ){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}

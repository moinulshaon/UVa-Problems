#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <iostream>
#include <queue>
#include <climits>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

#define X first
#define Y second

#define MP make_pair

#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)


typedef pair<int,int> pint;
typedef map<int,int> mint;

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
            //max number of vertices in one part
#define INF 100000000    //just infinity

struct tt {

    vector< vector<int> > cost;          //cost matrix
    int n, max_match;        //n workers and n jobs
    vector<int> lx, ly;        //labels of X and Y parts
    vector<int> xy;               //xy[x] - vertex that is matched with x,
    vector<int> yx;               //yx[y] - vertex that is matched with y
    vector<bool> S, T;         //sets S and T in algorithm
    vector<int> slack;            //as in the algorithm description
    vector<int> slackx;           //slackx[y] such a vertex, that
    // l(slackx[y]) + l(y) - w(slackx[y],y) = slack[y]
    vector<int> prev;             //array for memorizing alternating paths

    tt(int dim){
        n=dim;
        cost.resize( n );
        for (int i=0;i<n;++i){
            cost[i].resize(n);
        }
        lx.resize(n);
        ly.resize(n);

        xy.resize(n);
        yx.resize(n);

        S.resize(n);
        T.resize(n);

        slack.resize(n);
        slackx.resize(n);

        prev.resize(n);
    }


    void init_labels() {
        for (int i=0;i<lx.size();++i){
            lx[i]=0;
        }
        for (int i=0;i<ly.size();++i){
            ly[i]=0;
        }

        for (int x = 0; x < n; x++)
            for (int y = 0; y < n; y++)
                lx[x] = max(lx[x], cost[x][y]);
    }


    void add_to_tree(int x, int prevx){
        S[x] = true;                    //add x to S
        prev[x] = prevx;                //we need this when augmenting
        for (int y = 0; y < n; y++)    //update slacks, because we add new vertex to S
            if (lx[x] + ly[y] - cost[x][y] < slack[y]) {
                slack[y] = lx[x] + ly[y] - cost[x][y];
                slackx[y] = x;
            }
    }

    void update_labels() {
        int x, y, delta = INF;             //init delta as infinity
        for (y = 0; y < n; y++)            //calculate delta using slack
            if (!T[y])
                delta = min(delta, slack[y]);
        for (x = 0; x < n; x++)            //update X labels
            if (S[x]) lx[x] -= delta;
        for (y = 0; y < n; y++)            //update Y labels
            if (T[y]) ly[y] += delta;
        for (y = 0; y < n; y++)            //update slack array
            if (!T[y])
                slack[y] -= delta;
    }

    void augment() {                       //main function of the algorithm
        if (max_match == n) return;        //check wether matching is already perfect
        int x, y, root;                    //just counters and root vertex
        int  wr = 0, rd = 0;
        vector<int> q;
        q.resize(n);          //q - queue for bfs, wr,rd - write and read
        //pos in queue
        for (int i=0;i<S.size();++i){
            S[i]=false;
        }
        for (int i=0;i<T.size();++i){
            T[i]=false;
        }
        for (int i=0;i<prev.size();++i){
            prev[i]= -1;
        }
        for (x = 0; x < n; x++)            //finding root of the tree
            if (xy[x] == -1) {
                q[wr++] = root = x;
                prev[x] = -2;
                S[x] = true;
                break;
            }

        for (y = 0; y < n; y++) {          //initializing slack array
            slack[y] = lx[root] + ly[y] - cost[root][y];
            slackx[y] = root;
        }
        //second part of augment() function
        while (true) {                                                      //main cycle
            while (rd < wr) {                                               //building tree with bfs cycle
                x = q[rd++];                                                //current vertex from X part
                for (y = 0; y < n; y++)                                     //iterate through all edges in equality graph
                    if (cost[x][y] == lx[x] + ly[y] &&  !T[y]) {
                        if (yx[y] == -1) break;                             //an exposed vertex in Y found, so
                        //augmenting path exists!
                        T[y] = true;                                        //else just add y to T,
                        q[wr++] = yx[y];                                    //add vertex yx[y], which is matched
                        //with y, to the queue
                        add_to_tree(yx[y], x);                              //add edges (x,y) and (y,yx[y]) to the tree
                    }
                if (y < n) break;                                           //augmenting path found!
            }
            if (y < n) break;                                               //augmenting path found!

            update_labels();                                                //augmenting path not found, so improve labeling
            wr = rd = 0;
            for (y = 0; y < n; y++)
                if (!T[y] &&  slack[y] == 0) {
                    if (yx[y] == -1) {                                      //exposed vertex in Y found - augmenting path exists!
                        x = slackx[y];
                        break;
                    } else {
                        T[y] = true;                                        //else just add y to T,
                        if (!S[yx[y]]) {
                            q[wr++] = yx[y];                                //add vertex yx[y], which is matched with
                            //y, to the queue
                            add_to_tree(yx[y], slackx[y]);                  //and add edges (x,y) and (y,
                            //yx[y]) to the tree
                        }
                    }
                }
            if (y < n) break;                                               //augmenting path found!
        }

        if (y < n) {                                                        //we found augmenting path!
            max_match++;                                                    //increment matching
            //in this cycle we inverse edges along augmenting path
            for (int cx = x, cy = y, ty; cx != -2; cx = prev[cx], cy = ty) {
                ty = xy[cx];
                yx[cy] = cx;
                xy[cx] = cy;
            }
            augment();                                                      //recall function, go to step 1 of the algorithm
        }
    }//end of augment() function

    int hungarian() {
        int ret = 0;                      //weight of the optimal matching
        max_match = 0;
        for (int i=0;i<xy.size();++i){
            xy[i] = -1;
        }
        for (int i=0;i<yx.size();++i){
            yx[i] = -1;
        }              //number of vertices in current matching
        init_labels();                    //step 0
        augment();                        //steps 1-3
        for (int x = 0; x < n; x++)       //forming answer there
            ret += cost[x][xy[x]];
        return ret;
    }

};

#define SIZE 205

vector<int> tree1[SIZE],tree2[SIZE];
int sz1[SIZE],sz2[SIZE];

void dfs1(int x){
    sz1[x]=1;
    for (int i=0;i<tree1[x].size();++i){
        dfs1( tree1[x][i] );
        sz1[x] += sz1[ tree1[x][i] ];
    }
}

void dfs2(int x){
    sz2[x]=1;
    for (int i=0;i<tree2[x].size();++i){
        dfs2( tree2[x][i] );
        sz2[x] += sz2[ tree2[x][i] ];
    }
}

int dp[SIZE][SIZE];
bool vis[SIZE][SIZE];
int mx ;

int func( int x,int y ){
    //cout<<x<<" "<<y<<" "<<mx<<endl;



    int &ret = dp[x][y];

    if ( vis[x][y] )return ret;
    vis[x][y] = true;

    if ( sz1[x] == 0 ){
        return ret= sz2[y];
    }else if ( sz2[y] == 0 ){
        return ret= sz1[x];
    }

    int n=  max( tree1[x].size(),tree2[y].size() );
    tt mat ( n );

    for (int i=0;i<n;++i){
        for (int j=0;j<n;++j){
            int p,q;
            int cnt = 0;
            if ( i >= tree1[x].size() ){
                p=mx;
                cnt++;
            }else{
                p= tree1[x][i];
            }

            if ( j >= tree2[y].size() ){
                q=mx;
                cnt++;
            }else{
                q= tree2[y][j];
            }

            mat.cost[i][j] = -( cnt+func( p,q ) );
        }
    }
    //cout<<"shaon\n";
    return ret = -mat.hungarian();
}


int main() {

    //FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        for (int i=0;i<SIZE;++i){
            tree1[i].clear();
            tree2[i].clear();
        }

        CLR( sz1 );
        CLR( sz2 );

        int node1,tmp;
        scanf("%d",&node1);
        for (int i=1;i<=node1;++i){
            scanf("%d",&tmp);
            tree1[ tmp ].PB( i );
        }

        dfs1(0);

        int node2;
        scanf("%d",&node2);
        for (int i=1;i<=node2;++i){
            scanf("%d",&tmp);
            tree2[ tmp ].PB( i );
        }

        dfs2(0);

        CLR(vis);

        for (int i=0;i<=node1;++i){
            sz1[i]--;
            //cout<<i<<" "<<sz1[i]<<endl;
        }
        for (int i=0;i<=node2;++i){
            sz2[i]--;
            //cout<<i<<" "<<sz2[i]<<endl;
        }

        mx = max( node1,node2 )+1;

        printf("Case %d: %d\n",kk,func(0,0));
/*
        for (int i=0;i<=node1;++i){
            for (int j=0;j<=node2;++j){
                printf("%3d",dp[i][j]);
            }printf("\n");
        }
*/
    }


    return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );
#define ALL(v) v.begin(),v.end()

#define X first
#define Y second
#define MP make_pair

typedef pair<int,int> pint;
typedef map<int,int> mint;

void show() {cout<<'\n';}
template<typename T,typename... Args>
void show(T a, Args... args) { cout<<a<<" "; show(args...); }
template<typename T>
void show_c(T& a) { for ( auto &x:a ){ cout<<x<<" ";}cout<<endl;  }

#define SIZE 205

struct two_sat{

    vector <int> out[SIZE];
    vector <int> in[SIZE];
    bool vis [SIZE];
    vector <int> stk;
    int component[SIZE];

    void ini(int n){
        n<<=1;

        for (int i=0;i<n;++i){
            out[i].clear();
            in[i].clear();
            vis[i]=false;
        }
        stk.clear();
    }

    void add_edge(int x,int y){
        out[x].PB( y );
        in[y].PB( x );
    }

    void add_or(int x,int basex,int y,int basey){

        x= x*2+basex;
        y= y*2+basey;

        add_edge( x^1,y );
        add_edge( y^1,x );
    }

    void dfs1 (int x){
        vis [x] = true;
        for ( auto&y:out[x] )
            if ( !vis [ y ] )
                dfs1(y);
        stk.push_back (x);
    }
    void dfs2 (int x, int c){
        vis [x] = false;
        component [x] = c;

        for ( auto&y:in[x] )
            if ( vis [y] )
                dfs2 ( y, c);
    }




    bool solve(int n){
        n<<=1;

        for ( int i = 0; i < n; i++ )
			if ( !vis [i] )
                dfs1 (i);

        int c= 0;
        for ( int i = stk.size () - 1; i >= 0; i-- )
			if ( vis [ stk [i] ] )
                dfs2 (stk [i], ++c);

        for (int i=0;i<n;++i){
            if ( component[i] == component[i^1] ){
                return false;
            }
        }
        return true;
    }

};

two_sat solver,ysolver,nsolver;

vector<pint> edge[10*SIZE];

int main(){

    FRO

    int n,m,kk=1;
    while ( scanf("%d %d",&n,&m)==2 && (n+m) ){

        for (int i=0;i<m;++i){
            edge[i].clear();
        }

        int tmp;
        char str[SIZE];
        for (int i=0;i<m;++i){
            scanf("%d",&tmp);
            edge[i].resize(tmp);
            for (int j=0;j<tmp;++j){
                scanf("%d %s",&edge[i][j].X,str);
                edge[i][j].X--;
                edge[i][j].Y= ( str[0]=='y' );
            }
        }

        solver.ini(n);

        for (int i=0;i<m;++i){
            if ( edge[i].size() >=3 ){
                for (int p=0;p<edge[i].size();++p){
                    for (int q=p+1;q<edge[i].size();++q){
                        solver.add_or( edge[i][p].X,edge[i][p].Y,edge[i][q].X,edge[i][q].Y );
                    }
                }
            }else{
                for (auto&u:edge[i]){
                    solver.add_or( u.X,u.Y,u.X,u.Y );
                }
            }
        }
        printf("Case %d: ",kk++);
        if ( !solver.solve(n) )printf("impossible\n");
        else{

            int ans = 0;
            for (int len=0;len<n;++len){
                //checking n
                nsolver.ini(n);
                nsolver.add_or( len,0,len,0 );
                for (int i=0;i<m;++i){
                    if ( edge[i].size() >=3 ){
                        for (int p=0;p<edge[i].size();++p){
                            for (int q=p+1;q<edge[i].size();++q){
                                nsolver.add_or( edge[i][p].X,edge[i][p].Y,edge[i][q].X,edge[i][q].Y );
                            }
                        }
                    }else{
                        for (auto&u:edge[i]){
                            nsolver.add_or( u.X,u.Y,u.X,u.Y );
                        }
                    }
                }

                //checking y
                ysolver.ini(n);
                ysolver.add_or( len,1,len,1 );
                for (int i=0;i<m;++i){
                    if ( edge[i].size() >=3 ){
                        for (int p=0;p<edge[i].size();++p){
                            for (int q=p+1;q<edge[i].size();++q){
                                ysolver.add_or( edge[i][p].X,edge[i][p].Y,edge[i][q].X,edge[i][q].Y );
                            }
                        }
                    }else{
                        for (auto&u:edge[i]){
                            ysolver.add_or( u.X,u.Y,u.X,u.Y );
                        }
                    }
                }

                if ( ysolver.solve(n) ){
                    if ( nsolver.solve(n) ){
                        str[ans++]='?';
                    }else{
                        str[ans++]='y';
                    }
                }else{
                    if ( nsolver.solve(n) ){
                        str[ans++]='n';
                    }else{
                        exit(5);
                    }
                }

            }
            str[ans++]='\0';
            printf("%s\n",str);
        }


    }

    return 0;
}

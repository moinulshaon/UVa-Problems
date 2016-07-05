#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

typedef long long LL;

typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
ordered_set;
//find_by_order
//order_of_key

#define FO(i,a,b) for (int i = (a); i < (b); i++)

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

#define SIZE 310

vector <int> edge[SIZE], cost[SIZE];
vector<pint> ww[SIZE];

struct node{
    LL val;
    int city;
    bool operator < (const node & p)const{return val>p.val;}
};


LL dijkstra(int s,int f){

    bool vis[SIZE]={false};

    node place,temp,u;
    place.val=0;
    place.city=s;


    priority_queue<node> q;

    q.push(place);

    int a,b;

    while (!q.empty()){
        temp=q.top();q.pop();
        if (temp.city==f)return temp.val;

        if (vis[temp.city])
            continue;
        vis[temp.city]=true;

        //printf("%d %d\n",temp.city,temp.val);

        for (int i=0;i<edge[temp.city].size();++i){
            u.val=cost[temp.city][i]+temp.val;

            a= ww[temp.city][i].first;
            b= ww[temp.city][i].second;

            if ( a-temp.val%(a+b)< cost[temp.city][i] ){
                u.val = u.val + a+b -temp.val%(a+b) ;
            }

            u.city=edge[temp.city][i];

            if ( !vis[ u.city ] )
                q.push(u);
        }
    }
    exit(5);
    return -1;
}

int main(){

    int n,m,s,t;

    for (int kk=1;  scanf("%d %d %d %d",&n,&m,&s,&t)==4  ;++kk ){

        int u,v,a,b,cc;

        for (int i=0;i<SIZE;++i){
            edge[i].clear();
            cost[i].clear();
            ww[i].clear();
        }

        while ( m-- ){

            scanf("%d %d",&u,&v);
            scanf("%d %d",&a,&b);
            scanf("%d",&cc);

            if ( cc>a ){
                cc=(1<<29);
            }

            edge[u].PB( v );
            cost[u].PB( cc );
            ww[u].PB( make_pair(a,b) );
        }

        printf("Case %d: %lld\n",kk,dijkstra(s,t));
    }


    return 0;
}

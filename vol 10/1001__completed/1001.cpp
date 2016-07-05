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

#define SIZE 110

struct tt{
    double x,y,z,r;
}point[SIZE];

double sq(double x){
    return x*x;
}
double dis( tt&a,tt&b ){
    return sqrt( sq( a.x-b.x ) + sq( a.y-b.y )+sq( a.z-b.z ) );
}


double d[SIZE][SIZE];
int n;

vector <int> edge[12], cost[12];
int total;

struct node{
    double val;
    int city;
    bool operator < (const node & p)const{return val>p.val;}
};


int dijkstra(int s,int f){

    bool vis[SIZE]={false};

    node place,temp,u;
    place.val=0;
    place.city=s;


    priority_queue<node> q;

    q.push(place);


    while (!q.empty()){

        temp=q.top();q.pop();
        if (temp.city==f)break;

        if (vis[temp.city])
            continue;
        vis[temp.city]=true;


        for (int i=0;i<n;++i){
            u.val=d[temp.city][i]+temp.val;
            u.city=i;
            if ( !vis[ i ] )
                q.push(u);
        }
    }
    return int( temp.val*10 + .5 + 1e-6 );
}

int main(){

    //FRO

    int tmp;
    int kk = 1;
    while ( scanf("%d",&tmp)==1 && tmp != -1 ){
        n=tmp+2;
        for (int i=0;i<tmp;++i){
            scanf("%lf %lf %lf %lf",&point[i].x,&point[i].y,&point[i].z,&point[i].r);
        }

        scanf("%lf %lf %lf",&point[tmp].x,&point[tmp].y,&point[tmp].z);
        point[tmp].r = 0;

        scanf("%lf %lf %lf",&point[tmp+1].x,&point[tmp+1].y,&point[tmp+1].z);
        point[tmp+1].r = 0;


        for (int i=0;i<n;++i){
            for (int j=0;j<n;++j){
                d[i][j] = max( dis( point[i],point[j] ) - point[i].r-point[j].r , 0.0 );
            }
        }
        printf("Cheese %d: Travel time = %d sec\n",kk++,dijkstra( tmp,tmp+1 )  );
    }


    return 0;
}

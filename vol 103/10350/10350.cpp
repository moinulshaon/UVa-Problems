#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define SIZE 3000

vector <int> edge[SIZE], cost[SIZE];
int total;

struct node
{
    int val,city;
    bool operator < (const node & p)const{return val>p.val;}
};


void dijkstra(int s,int f)
{

    bool vis[SIZE]={false};

    node place,temp,u;
    place.val=0;
    place.city=s;




    priority_queue<node> q;

    q.push(place);


    while (!q.empty())
    {
        temp=q.top();q.pop();
        if (temp.city==f){
            //printf("found\n");
            break;
        }

        if (vis[temp.city])
            continue;
        vis[temp.city]=true;


        for (int i=0;i<edge[temp.city].size();++i)
        {
            u.val=cost[temp.city][i]+temp.val;
            u.city=edge[temp.city][i];

            q.push(u);
        }
    }
    printf("%d\n",temp.val);
}

int n,m;
int ff(int r,int c){
    return (r-1)*m+c;
}

int main(){
    freopen("in.txt","r",stdin);

    char line[20];
    int w;
    while ( scanf("%s",line)==1 ){

        scanf("%d %d",&n,&m);
        int total=n*m;

        for (int i=0;i<SIZE;++i){
            edge[i].clear();
            cost[i].clear();
        }


        for (int i=1;i<=m;++i){
            edge[0].push_back( ff(1,i) );
            cost[0].push_back( 0 );
        }

        for (int i=1;i<n;++i){

            for (int j=1;j<=m;++j){

                for (int k=1;k<=m;++k){
                    scanf("%d",&w);
                    //printf("%d %d %d %d %d\n",i,i+1,j,k,w);
                    edge[ff(i,j)].push_back( ff(i+1,k) );
                    cost[ff(i,j)].push_back( w+2 );

                }

            }

        }

        for (int i=1;i<=m;++i){
            edge[ff(n,i)].push_back( ff(n+1,1) );
            cost[ff(n,i)].push_back( 0 );
        }
        printf("%s\n",line);
        dijkstra( 0,ff(n+1,1) );

    }
    return 0;
}

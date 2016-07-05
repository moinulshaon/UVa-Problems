#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

#define INF 100000000

int set(int N,int pos){
    return N=N | (1<<pos);
}
int reset(int N,int pos){
    return N= N & ~(1<<pos);
}
bool check(int N,int pos){
    return (bool)(N & (1<<pos));
}
struct PP{
    int x,y;
}point[20];

double dis[20][20];

double distanced(int i,int j){

    if ( ! ( dis[i][j]<0 ) )return dis[i][j];

    PP &a=point[i];
    PP &b=point[j];

    return dis[i][j]=dis[j][i]=sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) );
}


double dp[1<<16+2];
bool vis[1<<16+2];

int person;

double func(int state){

    if ( state== ( (1<<person) -1) ) return 0;

    if ( vis[state] )return dp[state];

    double ans=INF;

    for (int i=0;i<person;++i){

        if ( check(state,i)==0 ){
            for (int j=i+1;j<person;++j){

                if ( check( state,j )==0 ){

                    ans= min( ans, distanced(i,j)+func( set( set( state,i ),j )  ) );

                }
            }
        }
    }
    vis[state]=true;
    return dp[state]=ans;

}

int main(){
    freopen("in.txt","r",stdin);


    for (int kk=1;scanf("%d",&person)==1 && person;++kk){
        //printf("%d\n",person);
        person=person+person;
        for (int i=0;i<person;++i){
            scanf("%*s %d %d",&point[i].x,&point[i].y);
        }

        memset(vis,false,sizeof(vis));

        for (int i=0;i<person;++i){
            for (int j=0;j<person;++j){
                dis[i][j]= -1;
            }
        }

        printf("Case %d: %.2lf\n",kk,func(0));


    }
    return 0;

}

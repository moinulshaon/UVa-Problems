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

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

int Set(int N,int pos){
    return N=N | (1<<pos);
}
int Reset(int N,int pos){
    return N= N & ~(1<<pos);
}
bool Check(int N,int pos){
    return (bool)(N & (1<<pos));
}

#define SIZE 10
#define X first
#define Y second

double dis[SIZE][SIZE];

typedef pair<int,int> pint;
pint point[SIZE];


double calc( int a,int b ){
    return sqrt( (point[a].X-point[b].X)*(point[a].X-point[b].X)+
                (point[a].Y-point[b].Y) *(point[a].Y-point[b].Y)  );
}

int n;
double dp[SIZE][1<<SIZE+5][SIZE];
int nxt[SIZE][1<<SIZE+5][SIZE];

double func( int state,int now,int start ){

    if ( state==(1<<n)-1 ){
        return 0;
    }
    if ( nxt[start][state][now]!= -1  )return dp[start][state][now];

    double tmp=0;
    double save=(1<<29);

    for (int i=0;i<n;++i){
        if ( Check( state,i )==0 ){
            tmp=dis[now][i]+func( Set( state,i ),i,start );
            if ( tmp<save ){
                save=tmp;
                nxt[start][state][now]=i;
            }
        }
    }

    return dp[start][state][now]=save;
}

void printrecursively(int now,int state,int start){
    if ( nxt[start][state][now]== -1 )return ;
    int y=nxt[start][state][now];

    printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n"
           ,point[now].X,point[now].Y,point[ y ].X,point[ y ].Y
           ,dis[now][ y ]);
    printrecursively( y,Set(state,y),start );
}

int main(){
    FRO
    for(int kk=1;scanf("%d",&n)==1 && n ;++kk){
        for (int i=0;i<n;++i){
            scanf("%d %d",&point[i].X,&point[i].Y);
        }

        for (int i=0;i<n;++i){
            for (int j=i;j<n;++j){
                dis[i][j]=dis[j][i]=calc(i,j)+16;
            }
        }

        double ans=(1<<29);
        int pans=-1;



        memset(nxt,-1,sizeof(nxt));

        for (int i=0;i<n;++i){
            if ( func( Set(0,i),i,i )<ans ){
                ans=func( Set(0,i),i,i );
                pans=i;
            }
        }



        printf("**********************************************************\n");
        printf("Network #%d\n",kk);
        printrecursively(pans,Set(0,pans) , pans);

        printf("Number of feet of cable required is %.2lf.\n",ans);
    }


    return 0;
}

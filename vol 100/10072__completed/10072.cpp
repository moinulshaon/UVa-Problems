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

typedef pair<int,int> pint;
typedef map<int,int> mint;

#define SIZE 110

double bat[SIZE],bowl[SIZE],field[SIZE];

int dp[SIZE][11][11][11][11];
bool vis[SIZE][11][11][11][11];
int n;
int func( int totake,int bb,int bo,int ff,int taken ){

    if ( totake == n ){
        if (  taken == 10 && bb==0 && bo==0 && ff==0 )return 0;
        else return -(1<<29);
    }

    if ( vis[ totake ][ bb ][bo][ff][taken] ) return dp[ totake ][ bb ][bo][ff][taken];

    int ans = int ( func( totake+1,bb,bo,ff,taken )+.5 ) ;
    if ( bb>0 ){
        ans=max( ans,int(0.8*bat[totake]+0.2*field[totake]+func( totake+1,bb-1,bo,ff,taken+1 )+.5) );
    }
    if ( bo>0 ){
        ans=max( ans,
               int ( 0.7*bowl[totake]+0.1*bat[totake]+0.2*field[totake]+func( totake+1,bb,bo-1,ff,taken+1 ) +.5 ) );
    }
    if ( ff>0 ){
        ans=max( ans,
               int ( 0.4*bat[totake]+0.4*bowl[totake]+0.2*field[totake]+ func( totake+1,bb,bo,ff-1,taken+1 ) +.5 ) );
    }
    vis[ totake ][ bb ][bo][ff][taken]=true;
    return dp[ totake ][ bb ][bo][ff][taken]=ans;
}

vector<int> va,vb,vc;

void prnt(int totake,int bb,int bo,int ff,int taken ){
    if ( totake == n ){
        return ;
    }

    if ( dp[ totake ][ bb ][bo][ff][taken] ==  int( func( totake+1,bb,bo,ff,taken ) +.5 ) ){
        prnt( totake+1,bb,bo,ff,taken );
    }
    else if ( bb>0
            && dp[ totake ][ bb ][bo][ff][taken] ==
                   int( 0.8*bat[totake]+0.2*field[totake]+func( totake+1,bb-1,bo,ff,taken+1 ) +.5 ) ){
            va.PB( totake );
            prnt( totake+1,bb-1,bo,ff,taken+1 );
    }
    if ( bo>0 && dp[ totake ][ bb ][bo][ff][taken] ==
        int( 0.7*bowl[totake]+0.1*bat[totake]+0.2*field[totake]+func( totake+1,bb,bo-1,ff,taken+1 )+.5 ) ){
        vb.PB( totake );
        prnt( totake+1,bb,bo-1,ff,taken+1 );
    }
    if ( ff>0 && dp[ totake ][ bb ][bo][ff][taken] ==
             int( .4*bat[totake]+.4*bowl[totake]+.2*field[totake]+ func( totake+1,bb,bo,ff-1,taken+1 )+.5 ) ){
        vc.PB( totake );
        prnt( totake+1,bb,bo,ff-1,taken+1 );
    }
}

int main(){
    FRO

    for (int kk=1; scanf("%d",&n)==1 && n ;++kk ){

        if ( kk!= 1 )printf("\n");

        for (int i=0;i<n;++i){
            scanf("%lf %lf %lf",&bat[i],&bowl[i],&field[i]);
        }

        int bb,bo,ff;
        scanf("%d %d %d",&bb,&bo,&ff);

        //cout<<bb<<' '<<bo<<' '<<ff<<endl;

        CLR(vis);

        int ans= int ( func( 0,bb,bo,ff,0 ) + 0.5 +1e-7 );
        //cout<<func( 0,bb,bo,ff,0 )<<endl;

        va.clear();
        vb.clear();
        vc.clear();

        prnt( 0,bb,bo,ff,0 );

        //double tt=0;

        printf("Team #%d\n",kk);
        printf("Maximum Effective Score = %d\n",ans);
        printf("Batsmen :");
        for (int i=0;i<va.size();++i){
            printf(" %d",va[i]+1);
            //tt+= .8*bat[ va[i] ]+.2* field[ va[i] ];
        }printf("\n");

        printf("Bowlers :");
        for (int i=0;i<vb.size();++i){
            printf(" %d",vb[i]+1);
            //tt+= .7*bowl[vb[i]]+.1*bat[ vb[i] ]+.2* field[ vb[i] ];
        }printf("\n");

        printf("All-rounders :");
        for (int i=0;i<vc.size();++i){
            printf(" %d",vc[i]+1);
            //tt+= .4*bowl[vc[i]]+.4*bat[ vc[i] ]+.2* field[ vc[i] ];
        }printf("\n");

        //cout<<tt<<endl;

    }


    return 0;
}

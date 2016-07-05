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

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

#define MP make_pair

typedef pair<int,int> pint;
typedef map<int,int> mint;

map< pair< pint,pint >,int > mp;

void pre(){

    mp[ MP( MP( 1,0 ),MP( 1,1 ) ) ] = 0;
    mp[ MP( MP( 1,1 ),MP( 1,0 ) ) ] = 0;

    mp[ MP( MP( 2,0 ),MP( 2,1 ) ) ] = 1;
    mp[ MP( MP( 2,1 ),MP( 2,0 ) ) ] = 1;

    mp[ MP( MP( 0,1 ),MP( 1,1 ) ) ] = 2;
    mp[ MP( MP( 1,1 ),MP( 0,1 ) ) ] = 2;

    mp[ MP( MP( 1,1 ),MP( 2,1 ) ) ] = 3;
    mp[ MP( MP( 2,1 ),MP( 1,1 ) ) ] = 3;

    mp[ MP( MP( 2,1 ),MP( 3,1 ) ) ] = 4;
    mp[ MP( MP( 3,1 ),MP( 2,1 ) ) ] = 4;

    mp[ MP( MP( 1,1 ),MP( 1,2 ) ) ] = 5;
    mp[ MP( MP( 1,2 ),MP( 1,1 ) ) ] = 5;

    mp[ MP( MP( 2,1 ),MP( 2,2 ) ) ] = 6;
    mp[ MP( MP( 2,2 ),MP( 2,1 ) ) ] = 6;

    mp[ MP( MP( 0,2 ),MP( 1,2 ) ) ] = 7;
    mp[ MP( MP( 1,2 ),MP( 0,2 ) ) ] = 7;

    mp[ MP( MP( 1,2 ),MP( 2,2 ) ) ] = 8;
    mp[ MP( MP( 2,2 ),MP( 1,2 ) ) ] = 8;

    mp[ MP( MP( 2,2 ),MP( 3,2 ) ) ] = 9;
    mp[ MP( MP( 3,2 ),MP( 2,2 ) ) ] = 9;

    mp[ MP( MP( 1,2 ),MP( 1,3 ) ) ] = 10;
    mp[ MP( MP( 1,3 ),MP( 1,2 ) ) ] = 10;

    mp[ MP( MP( 2,2 ),MP( 2,3 ) ) ] = 11;
    mp[ MP( MP( 2,3 ),MP( 2,2 ) ) ] = 11;

}

int Set(int N,int pos){
    return N=N | (1<<pos);
}
int Reset(int N,int pos){
    return N= N & ~(1<<pos);
}
bool Check(int N,int pos){
    return (bool)(N & (1<<pos));
}


bool vis[3][3];
bool connected( int x,int y,int state,int fx,int fy ){

    //cout<<x<<' '<<y<<endl;

    if ( x == fx && y== fy )return true;


    vis[x][y]= true;

    if ( x==0 && y== 0 ){
        if (!vis[x+1][y] &&  Check( state,0 )==1 && connected( x+1,y,state,fx,fy ) ){
            return true;
        }
        if (!vis[x][y+1] && Check( state,2 )==1 && connected( x,y+1,state,fx,fy ) ){
            return true;
        }
    }else if ( x== 1 && y== 0 ){
        if ( !vis[x-1][y] &&  Check( state,0 )==1 && connected( x-1,y,state,fx,fy ) ){
            return true;
        }
        if ( !vis[x][y+1] &&  Check( state,3 )==1 && connected( x,y+1,state,fx,fy ) ){
            return true;
        }
        if ( !vis[x+1][y] &&  Check( state,1 )==1 && connected( x+1,y,state,fx,fy ) ){
            return true;
        }
    }else if ( x==2 && y==0 ){
        if (!vis[x-1][y] &&  Check( state,1 )==1 && connected( x-1,y,state,fx,fy ) ){
            return true;
        }
        if (!vis[x][y+1] && Check( state,4 )==1 && connected( x,y+1,state,fx,fy ) ){
            return true;
        }
    }else if ( x==0 && y==1 ){
        if (!vis[x][y-1] &&  Check( state,2 )==1 && connected( x,y-1,state,fx,fy ) ){
            return true;
        }
        if (!vis[x+1][y] && Check( state,5 )==1 && connected( x+1,y,state,fx,fy ) ){
            return true;
        }
        if (!vis[x][y+1] && Check( state,7 )==1 && connected( x,y+1,state,fx,fy ) ){
            return true;
        }
    }else if ( x==1 && y==1 ){
        if (!vis[x][y-1] &&  Check( state,3 )==1 && connected( x,y-1,state,fx,fy) ){
            return true;
        }
        if (!vis[x+1][y] && Check( state,6 )==1 && connected( x+1,y,state,fx,fy ) ){
            return true;
        }
        if (!vis[x][y+1] && Check( state,8 )==1 && connected( x,y+1,state,fx,fy ) ){
            return true;
        }
        if ( !vis[x-1][y] && Check( state,5 )==1 && connected( x-1,y,state,fx,fy ) ){
            return true;
        }
    }else if ( x== 2 && y== 1 ){
        if (!vis[x][y-1] &&  Check( state,4 )==1 && connected( x,y-1,state,fx,fy ) ){
            return true;
        }
        if (!vis[x][y+1] && Check( state,9 )==1 && connected( x,y+1,state,fx,fy ) ){
            return true;
        }
        if ( !vis[x-1][y] && Check( state,6 )==1 && connected( x-1,y,state,fx,fy ) ){
            return true;
        }
    }else if ( x== 0 && y== 2 ){
        if (!vis[x][y-1] &&  Check( state,7 )==1 && connected( x,y-1,state,fx,fy ) ){
            return true;
        }
        if (!vis[x+1][y] && Check( state,10 )==1 && connected( x+1,y,state,fx,fy ) ){
            return true;
        }
    }else if ( x== 1 && y== 2 ){
        if (!vis[x][y-1] &&  Check( state,8 )==1 && connected( x,y-1,state,fx,fy ) ){
            return true;
        }
        if (!vis[x+1][y] && Check( state,11 )==1 && connected( x+1,y,state,fx,fy ) ){
            return true;
        }
        if ( !vis[x-1][y] && Check( state,10 )==1 && connected( x-1,y,state,fx,fy ) ){
            return true;
        }
    }else if ( x==2 && y== 2 ){
        if (!vis[x][y-1] &&  Check( state,9 )==1 && connected( x,y-1,state,fx,fy ) ){
            return true;
        }
        if ( !vis[x-1][y] && Check( state,11 )==1 && connected( x-1,y,state,fx,fy ) ){
            return true;
        }
    }
    return false;
}

char dp[3][3][1<<13][3][3];
char func( int x,int y, int state ,int fx,int fy  ){

    if ( dp[x][y][state][fx][fy] != -1 )return dp[x][y][state][fx][fy];

    CLR(vis);
    if ( connected( x,y,state,fx,fy ) ){
        //cout<<state<<endl;
        return dp[x][y][state][fx][fy]=0;
    }

    char ok=0;
    for (int i=0;i<12 && !ok;++i){
        if ( Check( state,i ) == 0 && !func( x,y,Set(state,i),fx,fy ) ){
            ok=1;
            break;
        }
    }

    return dp[x][y][state][fx][fy]= ok;
}

pint shaon(int x){

    return MP( x%3,x/3 );

}

int main(){
    FRO

    pre();
    NEG(dp);

    int kase,kk=1;
    scanf("%d",&kase);

    while ( kase-- ){
        int s,f,state=0,tmp,a,b,c,d;
        scanf("%d %d %d",&s,&f,&tmp);

        s--;
        f--;

        while ( tmp-- ){
            scanf("%d %d %d %d",&a,&b,&c,&d);
            state= Set( state,mp[ MP( MP(a,b),MP(c,d) ) ] );
        }

        printf("Case %d: ",kk++);
        CLR(vis);

        pint tt=shaon( s );
        a=tt.first;
        b=tt.second;
        tt= shaon( f );
        c=tt.first;
        d=tt.second;

        if(  connected( a,b,state ,c, d ) ){
            printf("No Cheese!\n");
        }else if ( func( a,b,state,c,d ) ){
            printf("SOHA\n");
        }else{
            printf("TARA\n");
        }

    }


    return 0;
}

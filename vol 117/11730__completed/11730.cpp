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

typedef pair<int,int> pint;
typedef map<int,int> mint;

vector<int> pp;

int bfs( int s,int f ){

    if ( s>f )return -1;
    else if ( s==f )return 0;


    bool vis[1010]={false};
    queue<int> q;
    queue<int> move;

    q.push(s);
    move.push(0);

    while ( !q.empty() ){

        int tmp=q.front();q.pop();
        int m=move.front();move.pop();

        int save=tmp;

        for (int i=0;pp[i]*pp[i]<= tmp;++i ){

            if ( tmp%pp[i] == 0 ){
                while( tmp%pp[i]==0 ){
                    tmp/=pp[i];
                }
                if ( save+pp[i]==f )return m+1;
                if ( save+pp[i] <f &&  !vis[ save+pp[i] ] ){
                    q.push( save+pp[i] );
                    move.push( m+1 );
                    vis[ save+pp[i] ]=true;
                }

            }

        }

        if ( tmp!=1 && tmp!=save ){
            if ( save+tmp==f )return m+1;
            if ( save+tmp<f &&!vis[ save+tmp ] ){
                q.push( save+tmp );
                move.push( m+1 );
                vis[ save+tmp ]=true;
            }
        }
    }
    return -1;
}


bool prime[1010];

int main(){


    for (int i=2;i<=32;++i){
        if ( !prime[i] ){
            for (int j=2*i;j<1010;j+=i){
                prime[j]=true;
            }
        }
    }

    for (int i=2;i<1010;++i){
        if ( !prime[i] ){
            pp.PB(i);
        }
    }

    int s,f;

    for (int kk=1;scanf("%d %d",&s,&f)==2 && (s+f) ;++kk){


        printf("Case %d: %d\n",kk,bfs(s,f));
    }


    return 0;
}

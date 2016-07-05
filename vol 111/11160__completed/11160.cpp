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
#define X first
#define Y second

typedef pair<int,int> pint;
typedef map<int,int> mint;

int dim;

typedef pair<pint,int> pul;

struct st{
    int a,b,c;
    string board;
}saving;

int all( int r,int c ){
    return r*dim+c;
}
pint undoing( int x ){
    return MP( x/dim,x%dim );
}

st moveup( st ini ){

    st final=ini;
    bool aok=false,bok=false,cok=false;
    for (int i=0;i<3 && (aok+bok+cok)<3 ;++i){
        pint tmp=undoing( final.a );
        if (!aok && tmp.X-1>=0 &&( final.board[ all( tmp.X-1,tmp.Y ) ] == '.'
                                   || final.board[ all( tmp.X-1,tmp.Y ) ] == 'X') ){
            final.board[ all( tmp.X-1,tmp.Y ) ] = 'A';
            final.board[ final.a ]= (saving.board[ final.a ]>='A' && saving.board[ final.a ]<='C' )
                                    ?'.':(saving.board[ final.a ]) ;
            final.a=all( tmp.X-1,tmp.Y );
            aok=true;
        }

        tmp=undoing( final.b );
        if (!bok && tmp.X-1>=0 && ( final.board[ all( tmp.X-1,tmp.Y ) ] == '.'
                                   || final.board[ all( tmp.X-1,tmp.Y ) ] == 'X') ){
            final.board[ all( tmp.X-1,tmp.Y ) ] = 'B';
            final.board[ final.b ]=(saving.board[ final.b ]>='A' && saving.board[ final.b ]<='C' )
                                    ?'.':(saving.board[ final.b ]);
            final.b=all( tmp.X-1,tmp.Y );
            bok=true;
        }

        tmp=undoing( final.c );
        if (!cok && tmp.X-1>=0 && ( final.board[ all( tmp.X-1,tmp.Y ) ] == '.'
                                   || final.board[ all( tmp.X-1,tmp.Y ) ] == 'X') ){
            final.board[ all( tmp.X-1,tmp.Y ) ] = 'C';
            final.board[ final.c ]=(saving.board[ final.c ]>='A' && saving.board[ final.c ]<='C' )
                                    ?'.':(saving.board[ final.c ]);
            final.c=all( tmp.X-1,tmp.Y );
            cok=true;
        }
    }
    return final;
}

st moveleft( st ini ){

    st final=ini;
    bool aok=false,bok=false,cok=false;
    for (int i=0;i<3 && (aok+bok+cok)<3 ;++i){
        pint tmp=undoing( final.a );
        if (!aok && tmp.Y-1>=0 && (final.board[ all( tmp.X,tmp.Y-1 ) ] == '.'
                                    || final.board[ all( tmp.X,tmp.Y-1 ) ] == 'X') ){
            final.board[ all( tmp.X,tmp.Y-1 ) ] = 'A';
            final.board[ final.a ]=(saving.board[ final.a ]>='A' && saving.board[ final.a ]<='C' )
                                    ?'.':(saving.board[ final.a ]);
            final.a=all( tmp.X,tmp.Y-1 );
            aok=true;
        }

        tmp=undoing( final.b );
        if (!bok && tmp.Y-1>=0 &&  (final.board[ all( tmp.X,tmp.Y-1 ) ] == '.'
                                    || final.board[ all( tmp.X,tmp.Y-1 ) ] == 'X') ){
            final.board[ all( tmp.X,tmp.Y-1 ) ] = 'B';
            final.board[ final.b ]=(saving.board[ final.b ]>='A' && saving.board[ final.b ]<='C' )
                                    ?'.':(saving.board[ final.b ]);
            final.b=all( tmp.X,tmp.Y-1 );
            bok=true;
        }

        tmp=undoing( final.c );
        if (!cok && tmp.Y-1>=0 &&  (final.board[ all( tmp.X,tmp.Y-1 ) ] == '.'
                                    || final.board[ all( tmp.X,tmp.Y-1 ) ] == 'X')){
            final.board[ all( tmp.X,tmp.Y-1 ) ] = 'C';
            final.board[ final.c ]=(saving.board[ final.c ]>='A' && saving.board[ final.c ]<='C' )
                                    ?'.':(saving.board[ final.c ]);
            final.c=all( tmp.X,tmp.Y-1 );
            cok=true;
        }
    }
    return final;
}

st movedown( st ini ){

    st final=ini;
    bool aok=false,bok=false,cok=false;
    for (int i=0;i<3 && (aok+bok+cok)<3 ;++i){
        pint tmp=undoing( final.a );
        if (!aok && tmp.X+1<dim && ( final.board[ all( tmp.X+1,tmp.Y ) ] == '.'
                                    || final.board[ all( tmp.X+1,tmp.Y ) ] == 'X') ){
            final.board[ all( tmp.X+1,tmp.Y ) ] = 'A';
            final.board[ final.a ]=(saving.board[ final.a ]>='A' && saving.board[ final.a ]<='C' )
                                    ?'.':(saving.board[ final.a ]);
            final.a=all( tmp.X+1,tmp.Y );
            aok=true;
        }

        tmp=undoing( final.b );
        if (!bok && tmp.X+1<dim && ( final.board[ all( tmp.X+1,tmp.Y ) ] == '.'
                                    || final.board[ all( tmp.X+1,tmp.Y ) ] == 'X') ){
            final.board[ all( tmp.X+1,tmp.Y ) ] = 'B';
            final.board[ final.b ]=(saving.board[ final.b ]>='A' && saving.board[ final.b ]<='C' )
                                    ?'.':(saving.board[ final.b ]);
            final.b=all( tmp.X+1,tmp.Y );
            bok=true;
        }

        tmp=undoing( final.c );
        if (!cok && tmp.X+1<dim && ( final.board[ all( tmp.X+1,tmp.Y ) ] == '.'
                                    || final.board[ all( tmp.X+1,tmp.Y ) ] == 'X') ){
            final.board[ all( tmp.X+1,tmp.Y ) ] = 'C';
            final.board[ final.c ]=(saving.board[ final.c ]>='A' && saving.board[ final.c ]<='C' )
                                    ?'.':(saving.board[ final.c ]);
            final.c=all( tmp.X+1,tmp.Y );
            cok=true;
        }
    }
    return final;
}

st moveright( st ini ){

    st final=ini;
    bool aok=false,bok=false,cok=false;
    for (int i=0;i<3 && (aok+bok+cok)<3 ;++i){
        pint tmp=undoing( final.a );
        if (!aok && tmp.Y+1<dim && ( final.board[ all( tmp.X,tmp.Y+1 ) ] == '.'
                                    || final.board[ all( tmp.X,tmp.Y+1 ) ] == 'X' ) ){
            final.board[ all( tmp.X,tmp.Y+1 ) ] = 'A';
            final.board[ final.a ]=(saving.board[ final.a ]>='A' && saving.board[ final.a ]<='C' )
                                    ?'.':(saving.board[ final.a ]);
            final.a=all( tmp.X,tmp.Y+1 );
            aok=true;
        }

        tmp=undoing( final.b );
        if (!bok && tmp.Y+1<dim &&  ( final.board[ all( tmp.X,tmp.Y+1 ) ] == '.'
                                    || final.board[ all( tmp.X,tmp.Y+1 ) ] == 'X' ) ){
            final.board[ all( tmp.X,tmp.Y+1 ) ] = 'B';
            final.board[ final.b ]=(saving.board[ final.b ]>='A' && saving.board[ final.b ]<='C' )
                                    ?'.':(saving.board[ final.b ]);
            final.b=all( tmp.X,tmp.Y+1 );
            bok=true;
        }

        tmp=undoing( final.c );
        if (!cok && tmp.Y+1<dim &&  ( final.board[ all( tmp.X,tmp.Y+1 ) ] == '.'
                                    || final.board[ all( tmp.X,tmp.Y+1 ) ] == 'X' ) ){
            final.board[ all( tmp.X,tmp.Y+1 ) ] = 'C';
            final.board[ final.c ]= (saving.board[ final.c ]>='A' && saving.board[ final.c ]<='C' )
                                    ?'.':(saving.board[ final.c ]);
            final.c=all( tmp.X,tmp.Y+1);
            cok=true;
        }
    }
    return final;
}

set<pul> result;

int bfs( st start ){


    set< pul > ss;
    ss.insert( MP( MP(start.a,start.b),start.c ) );

    queue< st > q;
    queue<int> move;
    pul tt;

    q.push( start );
    move.push(0);

    ss.insert( MP( MP(start.a,start.b),start.c ) );

    while( !q.empty() ){
        st tmp=q.front();q.pop();
        int mm=move.front();move.pop();
        //printf("shaon %d %d %d\n",tmp.a,tmp.b,tmp.c);
        if ( result.find( MP( MP(tmp.a,tmp.b),tmp.c ) )!= result.end() ){
            return mm;
        }

        st xx=moveup( tmp );
        if ( ss.find( MP( MP(xx.a,xx.b),xx.c ) ) == ss.end() ){
            q.push( xx );
            move.push( mm+1 );
            ss.insert( MP( MP(xx.a,xx.b),xx.c ) );
        }

        xx=movedown( tmp );
        if ( ss.find( MP( MP(xx.a,xx.b),xx.c ) ) == ss.end() ){
            q.push( xx );
            move.push( mm+1 );
            ss.insert( MP( MP(xx.a,xx.b),xx.c ) );
        }

        xx=moveleft( tmp );
        if ( ss.find( MP( MP(xx.a,xx.b),xx.c ) ) == ss.end() ){
            q.push( xx );
            move.push( mm+1 );
            ss.insert( MP( MP(xx.a,xx.b),xx.c ) );
        }

        xx=moveright( tmp );
        if ( ss.find( MP( MP(xx.a,xx.b),xx.c ) ) == ss.end() ){
            q.push( xx );
            move.push( mm+1 );
            ss.insert( MP( MP(xx.a,xx.b),xx.c ) );
        }

    }

    return -1;
}

int main(){
    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d",&dim);
        st start;
        start.board="";
        string tmp;

        for (int i=0;i<dim;++i){
            cin>>tmp;
            start.board+=tmp;
        }

        int shaon[5];
        int cnt=0;
        for (int i=0;i<dim;++i){
            for (int j=0;j<dim;++j){
                if ( start.board[ all(i,j) ]=='A' ){
                    start.a=all(i,j);
                }else if ( start.board[ all(i,j) ]=='B' ){
                    start.b=all(i,j);
                }else if ( start.board[ all(i,j) ]=='C' ){
                    start.c=all(i,j);
                }
                else if ( start.board[ all(i,j) ]=='X' ){
                    shaon[cnt++]=all(i,j);
                }
            }
        }

        result.clear();
        sort( shaon ,shaon+3);
        do{
            result.insert( MP( MP(shaon[0],shaon[1]),shaon[2] ) );
        }while( next_permutation(shaon,shaon+3) );

        saving=start;
        int ans= bfs( start );

        if ( ans == -1 ){
            printf("Case %d: trapped\n",kk);
        }else{
            printf("Case %d: %d\n",kk,ans);
        }

    }


    return 0;
}

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

#define HASH 50


char str[33];
char ans[33];
int cnt ;

set<string> ss[33];
set<string> shaon;

void func( int totake,int left ){

    //cout<<totake<<" "<<left<<endl;

    if ( str[totake] == '\0' ){
        if ( left == 0 ){
            ans[ cnt++ ] = '\0';
            //cout<<ans<<endl;
            ss[totake].insert( ans );
            shaon.insert( ans );
            cnt--;
        }
        return ;
    }

    ans[ cnt++ ] = '\0';

    if ( ss[totake] .find( ans ) != ss[totake].end() ){
        cnt--;
        return ;
    }

    ss[totake].insert( ans );
    cnt--;

    if ( left != 0 ){
        ans[cnt++] = str[totake];
        func( totake+1,left-1 );
        cnt--;
    }

    func( totake+1,left );
}

int main(){

    FRO
    //freopen("out.txt","w",stdout);

    int n;
    while ( scanf("%s %d",str,&n) == 2 ){

        for (int i=0;;++i){
            ss[i].clear();
            if ( !str[i] )break;
        }

        shaon.clear();

        sort( str,str+strlen(str) );
        func( 0,n );


        for ( set<string>::iterator it = shaon.begin(); it != shaon.end() ;++it ){
            cout<<*it<<endl;
        }

    }

    return 0;
}

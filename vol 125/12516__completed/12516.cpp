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

int n;
bool cover[30][150];
bool per[30][150];

int main(){

    FRO

    int row,col;
    while ( cin>>row>>col && (row+col) ){
        int n,tmp;
        cin>>n;
        char c1,c2;

        CLR(cover);
        CLR(per);

        bool ok=true;

        for (int i=0;i<n;++i){
            cin>>c1>>tmp>>c2;
            if ( c2 == '-' ){
                if ( cover [ c1-'A' ][ tmp-1 ] )ok=false;
                cover [ c1-'A' ][ tmp-1 ] = true;
            }else{
                if ( cover [ c1-'A' ][ tmp ] )ok=false;
                cover [ c1-'A' ][ tmp ] = true;
            }
        }

        cin>>n;
        for (int i=0;i<n;++i){
            cin>>c1>>tmp;
            per[ c1-'A' ][ tmp ]=true;
        }

        for (int i=0;i<30;++i){
            for (int j=0;j<110;++j){
                if ( per[ i ][ j ] ){
                    if ( !cover[ i ][ j-1 ] ){
                        cover[ i ][ j-1 ] = true;
                    }else if ( !cover[ i ][ j ] ){
                        cover[ i ][ j ]=true;
                    }else{
                        ok=false;
                    }
                }
            }
        }

        if ( ok )printf("YES\n");
        else printf("NO\n");

    }


    return 0;
}

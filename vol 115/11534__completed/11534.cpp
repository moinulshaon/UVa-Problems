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


char str[150];
int dp[110][3][3];

int calc(char x){
    if ( x== '*' )return 2;
    else if ( x== 'X' )return 1;
    else if ( x== 'O' )return 0;
    else exit(5);
}

const int lim = 105;

int func( int len,int le,int ri ){

    //cout<<len<<" "<<le<<" "<<ri<<endl;

    if ( len == 0 ){
        return 0;
    }

    int &ret = dp[len][le][ri];
    if ( ret != -1 )return ret;

    bool vis[lim]={0};
    if ( len == 1 ){
        for (int i=0;i<2;++i){
            if ( le != i && ri != i ){
                vis[0] = true;
            }
        }
    }else{
        for (int i=0;i<2;++i){
            if ( le != i ){
                vis[ func(len-1,i,ri) ] = true;
            }
        }
        for (int i=0;i<2;++i){
            if ( ri != i ){
                vis[ func(len-1,le,i) ] = true;
            }
        }
    }

    for (int i=1;i<len-1;++i){
        for (int j=0;j<2;++j){
            vis[ func( i,le,j ) ^ func( len-1-i,j,ri ) ]=true;
        }
    }

    for (int i=0;i<lim;++i){
        if ( !vis[i] ){
            return ret = i;
        }
    }

}


int main(){



    NEG(dp);

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%s",&str[1]);
        int len = strlen(&str[1]);
        str[0]='*';
        str[++len]='*';
        str[++len] = '\0';

        //cout<<str<<endl;

        int ans = 0;
        for (int i=0;i<len-1;){
            if ( str[i] != '.' ){
                int val = 0;
                int beg = i;
                i++;
                while ( str[i] == '.' ){
                    i++;
                    val++;
                }
                int le= calc( str[beg] );
                int ri = calc( str[i] );
                //cout<<val<<" "<<le<<" "<<ri<<endl;
                ans ^= func( val,le,ri );
            }
        }

        int made = 0;
        for (int i=0;i<len;++i){
            if ( str[i] == 'O' || str[i] == 'X' )made++;
        }

        if ( made%2 == 0 ){
            if ( ans >0 ){
                printf("Possible.\n");
            }else{
                printf("Impossible.\n");
            }
        }else{
            if ( ans == 0 ){
                printf("Possible.\n");
            }else{
                printf("Impossible.\n");
            }
        }

    }


    return 0;
}

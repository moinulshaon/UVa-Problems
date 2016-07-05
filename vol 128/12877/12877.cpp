#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>

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



#define SIZE 20

char word[100][SIZE];

char map[26];
bool nzr[26];

vector<char> need;

int x;
int n;

char tmp[SIZE];

int convert_num( char *str ){
    int len;
    for (len=0;str[len];++len){
        tmp[ len ] = map[ str[len]-'A' ];
    }
    tmp[len]='\0';
    int val;
    sscanf(tmp,"%d",&val);
    return val;
}

int func( int ind,int state ){
    //cout<<ind<<endl;
    if ( ind == need.size() ){
        int sum = 0;
        for (int i=0;i<n-1;++i){
            sum += convert_num( word[i] );
        }
        if ( sum == convert_num(word[n-1]) ){
            return 1;
        }else {
            return 0;
        }
    }
    int ans = 0;
    for (int i=0;i<10;++i){
        if ( i==0 && nzr[ need[ind]-'A' ] )continue;
        if ( ( state & (1<<i) )==0 ){
            map[ need[ind]-'A' ] = i+'0';
            ans += func( ind+1,state | (1<<i) );
        }
    }
    return ans;
}

int main(){

    FRO

    while ( scanf("%d",&n) == 1 ){

        bool already[30];

        CLR(nzr);
        CLR(already);
        need.clear();

        for (int i=0;i<n;++i){
            scanf("%s",word[i]);
            nzr[ word[i][0]-'A' ]=true;
            for (int j=0;word[i][j];++j){
                if ( !already[ word[i][j]-'A' ] ){
                    already[ word[i][j]-'A' ]= true;
                    need.PB( word[i][j] );
                }
            }
        }



        NEG(map);
        int ans = func(0,0);

        printf("%d\n",ans);
    }


    return 0;
}

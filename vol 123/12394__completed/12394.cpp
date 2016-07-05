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

#define SIZE 1010

bool mat[SIZE][SIZE];
char name[SIZE][13];
vector<int> rev[SIZE];

bool ans[SIZE];
int cnt[SIZE];

int main(){

    FRO

    int k,n;
    while ( scanf("%d %d",&k,&n) == 2 && (n+k) ){

        for (int i=1;i<=n;++i){
            for (int j=1;j<=n;++j){
                mat[i][j] = false;
            }
            ans[i] = true;
            rev[i].clear();
            cnt[i] = 0;
        }

        int tmp;
        for (int i=1;i<=n;++i){
            scanf("%s",name[i]);
            for (int j=0;j<k;++j){
                scanf("%d",&tmp);
                rev[i].PB( tmp );
            }
        }

        for (int i=1;i<=n;++i){
            for (int j=0;j<k;++j){
                if ( i==rev[i][j] || mat[i][ rev[i][j] ] || strcmp( name[i] , name[ rev[i][j] ] ) == 0 ){
                    ans[ rev[i][j] ]=false;
                }else{
                    cnt[ rev[i][j] ]++;
                }
                mat[i][ rev[i][j] ] = true;
            }
        }

        int xx = 0;
        for (int i=1;i<=n;++i){
            //cout<<i<<" "<<cnt[i]<<endl;
            if ( !ans[i] || cnt[i] != k ){
                xx++;
            }
        }
        if ( xx== 0 )printf("NO PROBLEMS FOUND\n");
        else if ( xx == 1 )printf("1 PROBLEM FOUND\n");
        else printf("%d PROBLEMS FOUND\n",xx);

    }


    return 0;
}

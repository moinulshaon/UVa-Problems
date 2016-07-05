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

#define SIZE 205

int dp[SIZE][33];
int save[SIZE][SIZE];

int n;
int pos[SIZE];
int lefts;

int func( int totake,int have ){

    int &ret= dp[totake][have];

    if ( ret != -1 )return ret;

    ret = 0;
    for (int i=totake+1;i<n;++i){
        ret += pos[i] - pos[totake] ;
    }

    if ( have == lefts )return ret;

    for (int i=totake+1;i<n;++i){
        ret= min( ret , save[totake][i] + func( i,have+1 ) );
    }
    return ret;
}

vector<int> fuck;

void prnt( int totake,int have  ){

    int &ret= dp[totake][have];

    int tmp = 0;
    for (int i=totake+1;i<n;++i){
        tmp += pos[i] - pos[totake] ;
    }

    if ( tmp == ret ){
        return ;
    }
    for (int i=totake+1;i<n;++i){
        if ( ret ==  save[totake][i] + func( i,have+1 ) ){
            fuck.PB( i );
            prnt( i,have+1 );
            return ;
        }
    }


}

vector<int> sss[SIZE];

int main(){

    FRO

    int kk= 1;
    while ( scanf("%d %d",&n,&lefts) == 2 && ( n+lefts ) ){

        for (int i=0;i<n;++i){
            scanf("%d",&pos[i]);
        }

        NEG(dp);

        for (int i=0;i<n;++i){
            for (int j=i+1;j<n;++j){
                int tmp = 0;
                for (int k=i+1;k<j;++k){
                    tmp+= min( pos[j]-pos[k] , pos[k]-pos[i] );
                }
                save[i][j] = tmp;
            }
        }

        int ans = (1<<29);

        for (int i=0;i<n;++i){
            int tmp = func( i,1 );
            for (int j=0;j<i;++j){
                tmp+= pos[i]-pos[j];
            }
            ans = min( ans , tmp );
        }
        //cout<<ans<<endl;

        printf("Chain %d\n",kk++);

        fuck.clear();
        for (int i=0;i<n;++i){
            int tmp = func( i,1 );
            for (int j=0;j<i;++j){
                tmp+= pos[i]-pos[j];
            }
            if ( tmp == ans ){
                fuck.PB( i );
                prnt( i,1 );
                break;
            }
        }

        for (int i=0;i<SIZE;++i){
            sss[i].clear();
        }


        for (int i=0;i<n;++i){
            int dis=(1<<29);
            int num = -1;
            for (  int j=0;j<fuck.size();++j ){
                if ( abs( pos[i] - pos[ fuck[j] ] )<dis ){
                    dis= abs( pos[i] - pos[ fuck[j] ] );
                    num = j;
                }
            }
            sss[num].PB( i );
        }

        for (int i=0;i<fuck.size();++i){
            printf("Depot %d at restaurant %d serves ",i+1,fuck[i]+1);
            if ( sss[ i ].size() == 1 ){
                printf("restaurant %d\n",sss[i].back()+1);
            }else{
                printf("restaurants %d to %d\n",sss[i][0]+1,sss[i].back()+1);
            }
        }
        printf("Total distance sum = %d\n\n",ans);
    }


    return 0;
}

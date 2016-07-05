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

#define SIZE 1003

int dp[SIZE][SIZE];

map<string ,int >mp;

set<int> weak[SIZE];

int pp,vv;
int num[SIZE],attack[SIZE],cost[SIZE];
int def[SIZE];
char str[SIZE];

int func( int vnum,int anum ){

    //cout<<vnum<<" "<<anum<<endl;

    if ( vnum> vv )return 0;

    int &ret = dp[vnum][anum];
    if ( ret != -1 )return ret;

    ret = (1<<29);

    if ( anum+1 <= pp ){
        ret = min( ret, func( vnum,anum+1 ) );
    }

    if ( weak[ vnum ].find( num[anum] ) !=  weak[ vnum ].end() && def[vnum] <= attack[anum] ){
        ret = min( ret, cost[anum] + func( vnum+1,anum+1 ) );
    }
    return ret;
}

int main(){

    FRO

    int energy;

    while ( scanf("%d %d %d",&pp,&vv,&energy) == 3 && (pp+vv+energy) ){

        mp.clear();
        int cnt = 1;
        string tmp;
        for (int i=1;i<=pp;++i){
            scanf("%s %d %d",str,&attack[i],&cost[i]);
            tmp= str;
            if ( mp.find( tmp ) == mp.end()  ){
                mp[ tmp ]= cnt++;
            }
            num[i]= mp[tmp];
        }

        for (int i=1;i<=vv;++i){
            scanf("%*s %d %s",&def[i],str);
            weak[i].clear();
            char *pch = strtok (str,",");
            while (pch != NULL){
                tmp= pch;
                //cout<<tmp<<endl;
                weak[i].insert( mp[tmp] );
                pch = strtok (NULL, ",");
            }

        }

        NEG(dp);

        //cout<<func(1,1)<<endl;

        if ( func(1,1) <= energy ){
            printf("Yes\n");
        }else{
            printf("No\n");
        }

    }


    return 0;
}

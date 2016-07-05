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

pint dp[23][105][55][3];
int arr[55];
int cc[55];
int n;

pint func( int day,int cost,int prv,int cnt ){

    if ( cost<0 )return MP(-1<<29,-(1<<29));
    if ( day ==0 ){
        return MP(0,cost);
    }

    pint &ret= dp[day][cost][prv][cnt];
    if ( ret.X!= -1 )return ret;

    ret.X = -(1<<29);
    ret.Y = (1<<29);

    pint tmp;
    for (int i=0;i<n;++i){
        if ( i!= prv ){
            tmp = func( day-1,cost-cc[i],i,1 );
            tmp.X += arr[i];
        }else{
            if ( cnt== 1 ){
                tmp = func( day-1,cost-cc[i],i,2 );
                tmp.X+= arr[i]/2;
            }
            else{
                tmp = func( day-1,cost-cc[i],i,2 );
            }
        }
        if ( tmp.X>ret.X ){
            ret= tmp;
        }else if ( tmp.X == ret.X ){
            ret.Y= max( ret.Y,tmp.Y );
        }
    }
    return ret;
}

vector<int> ans;
void prnt( int day,int cost,int prv,int cnt ){

    if ( day ==0 ){
        return ;
    }

    pint &ret= dp[day][cost][prv][cnt];


    pint tmp;
    for (int i=0;i<n;++i){
        if ( i!= prv ){
            tmp = func( day-1,cost-cc[i],i,1 );
            tmp.X += arr[i];
            if ( tmp == ret ){
                ans.PB( i );
                prnt( day-1,cost-cc[i],i,1 );
                return ;
            }
        }else{
            if ( cnt== 1 ){
                tmp = func( day-1,cost-cc[i],i,2 );
                tmp.X+= arr[i]/2;

                if ( tmp == ret ){
                    ans.PB( i );
                    prnt( day-1,cost-cc[i],i,2 );
                    return ;
                }
            }
            else{
                tmp = func( day-1,cost-cc[i],i,2 );
                if ( tmp == ret ){
                    ans.PB( i );
                    prnt( day-1,cost-cc[i],i,2 );
                    return ;
                }
            }
        }
    }
    return ;
}
int main(){

    FRO

    int k,m;
    bool on=false;
    while ( scanf("%d %d %d",&k,&n,&m)==3 && ( k+m+n ) ){

        if ( on )printf("\n");

        NEG(dp);
        for (int i=0;i<n;++i){
            scanf("%d %d",&cc[i],&arr[i]);
            arr[i]*=2;
        }

        double shaon = func( k,m,n+1,1 ).X;

        //cout<<func( k,m,n+1,1 ).X<<" "<<func( k,m,n+1,1 ).Y<<endl;

        if ( shaon<0 ){
            printf("0.0\n");
        }else{
            printf("%.1lf\n",shaon/2);
            ans.clear();
            prnt( k,m,n+1,1 );
            for (int i=0;i<ans.size();++i){
                if ( i )printf(" ");
                printf("%d",ans[i]+1);
            }
            printf("\n");
        }

        on=true;
    }


    return 0;
}

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


struct tt{
    int point,cost;
    char des[70];
}arr[110];

int n;
int w;

bool cmp( const tt&a, const tt&b ){
    if ( a.cost!=b.cost )
        return a.cost<b.cost;
    else if ( a.point!= b.point )
        return a.point>b.point;
    else
        return strcmp( a.des,b.des )<=0;
}

int dp[110][250];

int func( int totake,int now ){

    if ( totake == n ){
        return 0;
    }

    int &ret = dp[totake][now];

    if ( ret != -1 )return ret;

    int shaon= func( totake+1,now );

    if (  now+arr[totake].cost <= w ){
        shaon = max( shaon, arr[totake].point +func( totake+1,now+arr[totake].cost  ) );
    }
    return ret = shaon;
}

int mmm ;

void prnt( int totake,int now ){

    if ( totake == n ){
        mmm= now;
        return ;
    }
    int &ret = dp[totake][now];

    if ( ret ==  func( totake+1,now ) ){
        prnt( totake+1,now );
    }else if ( now+arr[totake].cost <= w  && ret == arr[totake].point +func( totake+1,now+arr[totake].cost  ) ){
        printf("%3d%7d   %s\n",arr[totake].point,arr[totake].cost,arr[totake].des);
        prnt( totake+1,now+arr[totake].cost  );
    }
}

char str[2000];

int main(){

    FRO
    //freopen("out.txt","w",stdout);
    int kase;
    gets(str);

    sscanf(str,"%d",&kase);

    //cout<<kase<<" "<<str<<endl;

    gets(str);

    while ( kase-- ){

        gets(str);
        sscanf(str,"%d",&w);

        //cout<<w<<" "<<str<<endl;

        for ( n=0; gets( str ) && str[0]  ;++n ){
            //cout<<str<<endl;
            sscanf(str,"%d %d %[^\n]",&arr[n].point,&arr[n].cost,&arr[n].des);
            //cout<<arr[n].point<<" "<<arr[n].cost<<" "<<arr[n].des<<endl;
        }



        sort( arr,arr+n,cmp );

        NEG(dp);
        int ans = func( 0,0 );

        //cout<<ans<<endl;

        if ( ans == 0 ){
            printf("There is not enough time to present any evidence. Drop the charges.\n");
        }else{
            printf("Score  Time  Description\n");
            printf("-----  ----  -----------\n");
            prnt(0,0);

            printf("\nTotal score: %d points\n Total time: %d hours\n",ans,mmm);
        }

        if ( kase )printf("\n");

    }


    return 0;
}

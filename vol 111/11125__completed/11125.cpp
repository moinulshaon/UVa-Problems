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

typedef pair<int,int> pint;
typedef map<int,int> mint;

int dp[8][8][8][8][4][4][4][4][5];

int func( int totake,int left0,int left1,int left2,int left3,int prv,int consec,int first
         ,int group,int fsz ){

    if ( consec>3 )return 0;

    if ( totake == 0 ){
        //cout<<"ss "<<consec<<' '<<group<<' ';
        //cout<<prv<<' '<<first<<endl;
        if ( prv!=first && consec!= fsz && consec != group  ){
            //cout<<"ss "<<fsz<<' '<<consec<<endl;
            //cout<<group<<' '<<consec<<endl;
            //cout<<ss<<endl;
            return 1;
        }
        else return 0;
    }


    if ( dp[left0][left1][left2][left3][prv][consec][first][group][fsz] != -1 ){
        return dp[left0][left1][left2][left3][prv][consec][first][group][fsz];
    }
    //cout<<left0<<' '<<left1<<' '<<left2<<' '<<left3<<endl;
    int ans=0;
    if ( left0>0 ){
        if(prv==0){
            ans+= func( totake-1, left0-1, left1,left2,left3,0,consec+1, first,group,fsz );
        }else if ( prv!=0 && consec!=group ){
            if ( fsz>3 )
            ans+= func( totake-1, left0-1, left1,left2,left3,0, 1, first,consec ,consec );
            else
            ans+= func( totake-1, left0-1, left1,left2,left3,0, 1, first,consec ,fsz );
        }
    }
    if ( left1>0 ){
        if (prv==1){
            ans+= func( totake-1, left0, left1-1,left2,left3,1,consec+1, first,group,fsz );
        }else if ( prv!= 1 &&  consec != group ) {
            if ( fsz>3 )
            ans+= func( totake-1, left0, left1-1 ,left2,left3,1, 1, first,consec,consec );
            else
            ans+= func( totake-1, left0, left1-1 ,left2,left3,1, 1, first,consec,fsz );
        }
    }

    if ( left2>0 ){
        if (prv ==2 ){
            ans+= func( totake-1, left0, left1 ,left2-1,left3,2,consec+1, first,group ,fsz);
        }else if ( prv!=2 && consec!=group ){
            if ( fsz<=3 )
            ans+= func( totake-1, left0, left1 ,left2-1,left3,2, 1, first,consec ,fsz );
            else
            ans+= func( totake-1, left0, left1 ,left2-1,left3,2, 1, first,consec ,consec );
        }
    }
    if ( left3>0 ){
        if (prv== 3){
            ans+= func( totake-1, left0, left1,left2,left3-1 ,3,consec+1, first,group,fsz );
        }else if ( prv!=3 && consec!=group ){
            if ( fsz<=3 )
            ans+= func( totake-1, left0, left1 ,left2,left3-1,3, 1, first,consec,fsz );
            else
            ans+= func( totake-1, left0, left1 ,left2,left3-1,3, 1, first,consec,consec );
        }
    }

    return dp[left0][left1][left2][left3][prv][consec][first][group][fsz]=ans;
}

int main(){
    FRO

    NEG(dp);

    int kase;
    scanf("%d",&kase);

    while ( kase-- ){
        int n,c[4];
        CLR(c);
        scanf("%d",&n);

        for (int i=0;i<n;++i){
            scanf("%d",&c[i]);
        }

        int ans= 0 ;
        int sum= 0;
        for (int i=0;i<4;++i){
            sum+=c[i];
        }

        if ( c[0]>0 ){
            ans+= func( sum-1,c[0]-1,c[1],c[2],c[3],0,1,0,0,4  );
        }

        if ( c[1]>0 ){
            ans+= func( sum-1,c[0],c[1]-1,c[2],c[3],1,1,1,0 ,4);
        }

        if ( c[2]>0 ){
            ans+= func( sum-1,c[0],c[1],c[2]-1,c[3],2,1,2,0 ,4);
        }
        if ( c[3]>0 ){
            ans+= func( sum-1,c[0],c[1],c[2],c[3]-1,3,1,3,0 ,4 );
        }


        if ( sum==0 )ans=1;

        printf("%d\n",ans);

    }


    return 0;
}

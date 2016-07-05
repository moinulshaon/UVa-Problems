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

bool prime[301];

char dp[1010][65][3][15];
vector<int> p;

char func( int n,int at,int left,int ss ){

    if ( n==0 )return ss==0;
    if ( at== p.size() )return 0;

    if ( p[at] == 2 && left>1 ){
        left=1;
    }


    if ( dp[n][at][left][ss] != -1 )return dp[n][at][left][ss];

    bool pos=false;
    if (!pos && n-p[at]>=0 && left>0 && ss>0 ){
        pos=func( n-p[at],at,left-1 ,ss-1);
    }

    if ( !pos ){
        pos=func( n,at+1,2,ss );
    }

    return dp[n][at][left][ss]= pos;
}
vector<int> ans;

void prnt(int n,int at,int left,int ss){
    //cout<<n<<' '<<ss<<endl;
    if ( n==0 ){
        //cout<<ss<<endl;
        return ;
    }
    if ( p[at] == 2 && left>1 ){
        left=1;
    }

    if (left>0 && n-p[at]>=0 && ss>0  && func( n-p[at],at,left-1,ss-1  ) ){
        ans.PB( p[at] );
        prnt( n-p[at],at,left-1 ,ss-1 );
    }else{
        prnt( n,at+1,2,ss );
    }
}

char tt[10],tt2[10];

bool cmp( const int &a,const int&b ){
    sprintf(tt,"%d",a);
    sprintf(tt2,"%d",b);

    return  strcmp( tt,tt2 ) <0 ;
}

int main(){
    FRO

    prime[0]=prime[1]=true;

    for (int i=2;i<=18;++i){
        if ( !prime[i] ){
            for (int j=2*i;j<301;j+=i){
                prime[j]=true;
            }
        }
    }


    for (int i=0;i<301;++i){
        if ( !prime[i] ){
            p.PB(i);
            //cout<<p.back()<<endl;
        }
    }
    //cout<<p[0]<<endl;
    sort( p.begin(),p.end(),cmp );

    //cout<<p.size()<<endl;

    int n,k;

    NEG(dp);

    for (int kk=1; scanf("%d %d",&n,&k) == 2 && (n+k) ;++kk ){

        printf("CASE %d:\n",kk);

        if ( func( n,0,2,k ) >0  ){
            ans.clear();
            prnt(n,0,2,k);

            for (int i=0;i<ans.size();++i){
                if ( i )printf("+");
                printf("%d",ans[i]);
            }printf("\n");
        }else{
            printf("No Solution.\n");
        }
    }


    return 0;
}

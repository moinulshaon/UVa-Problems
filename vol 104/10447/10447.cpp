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

bool prime[310];

vector<int> p;

map<int,int> mp;

char tt[10],tt2[10];

int dp[810][6];
int with[810][6];

vector<int> ans;

void func( int n,int k,int arr[810][6] ){

    if ( n==0 )return ;

    ans.PB( arr[n][k] );

    func( n-arr[n][k],k-1,arr );

}

bool cmp( const int &a,const int&b ){
    sprintf(tt,"%d",a);
    sprintf(tt2,"%d",b);

    if ( strcmp( tt,tt2 ) <0 ){
        return true;
    }else{
        return false;
    }
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
    //cout<<p.back()<<endl;
    sort( p.begin(),p.end(),cmp );

    //cout<<p.size()<<endl;

    int n,k;

    int kase;
    scanf("%d",&kase);

    for (int kk=1; kase-- ;++kk ){
        printf("Block %d:\n",kk);

        mp.clear();


        int tmp;
        for (int i=3;i<301;++i){
            if ( !prime[i] ){
                scanf("%d",&tmp);
                mp[ i ] = tmp ;
                //cout<<i<<' '<<tmp<<endl;
            }
        }

        NEG(dp);

        dp[0][0]=0;

        for (int i=0;i<p.size();++i){
            tmp= mp[ p[i] ];
            for (int j=1;j<=tmp;++j ){
                for (int k=0;k<31;++k){
                    for (int m=5;m>=0;--m){
                        if (dp[k][m] == -1 && k-p[i]>=0 && m-1>=0 && dp[ k-p[i] ][ m-1 ] >=0 ){
                            dp[ k ][ m ] = p[i];
                            //cout<<k<<' '<<m<<' '<<dp[ k ][ m ]<<endl;
                        }
                    }
                }
            }
        }

        NEG(with);

        with[0][0]=0;

        bool on=false;

        for (int i=0;i<p.size();++i){

            if ( !on && cmp( 2,p[i] ) ){
                tmp= mp[ p[i] ];
                for (int j=1;j<=tmp;++j ){
                    for (int k=31;k>=0;--k){
                        for (int m=5;m>=0;--m){
                            if (with[k][m] == -1 && k-p[i]>=0 && m-1>=0 && with[ k-p[i] ][ m-1 ] >=0 ){
                                with[ k ][ m ] = p[i];
                                //cout<<k<<' '<<m<<' '<<dp[ k ][ m ]<<endl;
                            }
                        }
                    }
                }
                on=true;
            }

            tmp= mp[ p[i] ];
            for (int j=1;j<=tmp;++j ){
                for (int k=31;k>=0;--k){
                    for (int m=5;m>=0;--m){
                        if (with[k][m] == -1 && k-p[i]>=0 && m-1>=0 && with[ k-p[i] ][ m-1 ] >=0 ){
                            with[ k ][ m ] = p[i];
                            //cout<<k<<' '<<m<<' '<<dp[ k ][ m ]<<endl;
                        }
                    }
                }
            }
        }


        int qq;
        scanf("%d",&qq);

        //printf("sahon %d\n",qq);

        for (int mm=1; qq-- ; ++mm ){

            scanf("%d %d %d",&n,&k,&tmp);

            printf("Query %d:\n",mm);
            //cout<<dp[n][k]<<endl;
            if ( tmp ){
                if ( with[ n ][ k ]>=0 ){
                    ans.clear();
                    func( n,k,with );
                    tmp=ans.size()-1;
                    for (int i=tmp;i>=0;--i){
                        if ( i!= tmp )printf("+");
                        printf("%d",ans[i]);
                    }printf("\n");
                }else{
                    printf("No Solution.\n");
                }
            }else{
                if ( dp[ n ][ k ]>=0 ){
                    ans.clear();
                    func( n,k,dp );
                    tmp=ans.size()-1;
                    for (int i=tmp;i>=0;--i){
                        if ( i!= tmp )printf("+");
                        printf("%d\n",ans[i]);
                    }printf("\n");
                }else{
                    printf("No Solution.\n");
                }
            }

        }


        printf("\n");

    }


    return 0;
}

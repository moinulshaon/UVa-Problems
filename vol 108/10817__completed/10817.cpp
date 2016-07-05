#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>

using namespace std;

#define INF 1000000000

int set(int N,int pos){
    return N=N | (1<<pos);
}
int reset(int N,int pos){
    return N= N & ~(1<<pos);
}
bool check(int N,int pos){
    return (bool)(N & (1<<pos));
}

int sub,n,m;

struct ttt{
    int val;
    bool pos[10];
}teacher[150];

void makeOne( int no,int &s1,int &s2 ){

    if ( check( s1,no )==0 ){
        s1=set(s1,no);
    }else{
        s2=set(s2,no);
    }

}
int dp[260][260][110];

int func( int totake,int s1,int s2 ){
    if ( s1==((1<<sub)-1) && s2==((1<<sub)-1) ){
        return 0;
    }
    if (totake==m)return INF;
    if ( dp[s1][s2][totake] !=-1 )return dp[s1][s2][totake];
    int a=func( totake+1,s1,s2 );
    int tmp1=s1;
    int tmp2=s2;
    for (int i=0;i<sub;++i){
        if ( teacher[totake].pos[i] ){
            makeOne( i,s1,s2 );
        }
    }

    int b=teacher[totake].val+func( totake+1,s1,s2 );
    return dp[tmp1][tmp2][totake]=min( a,b );
}


int main(){

    freopen("in.txt","r",stdin);

    string ss;

    while ( true ){

        getline(cin,ss);
        stringstream sstr(ss);
        sstr>>sub>>n>>m;
        if ( !sub && !n && !m )return 0;

        int state1=0,state2=0,cost=0;

        for (int i=0;i<n;++i){
            getline(cin,ss);

            stringstream sstr2(ss);
            int a;
            sstr2>>teacher[i].val;
            memset(teacher[i].pos,false,sizeof(teacher[i].pos));
            while ( sstr2>>a ){
                teacher[i].pos[a-1]=true;
            }
            for (int j=0;j<sub;++j){

                if ( teacher[i].pos[j] ){
                    makeOne( j,state1,state2 );
                }

            }
            cost+=teacher[i].val;
        }

        for (int i=0;i<m;++i){
            getline(cin,ss);

            stringstream sstr2(ss);
            int a;
            sstr2>>teacher[i].val;
            memset(teacher[i].pos,false,sizeof(teacher[i].pos));
            while ( sstr2>>a ){
                teacher[i].pos[a-1]=true;
            }

        }
        for (int i=0;i<(1<<sub);++i){
            for (int j=0;j<(1<<sub);++j){
                for (int k=0;k<m;++k){
                    dp[i][j][k]= -1;
                }
            }
        }
        cost+=func(0,state1,state2);
        printf("%d\n",cost);
    }

}

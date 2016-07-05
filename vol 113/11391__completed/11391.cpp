#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

int set(int N,int pos){
    return N=N | (1<<pos);
}
int reset(int N,int pos){
    return N= N & ~(1<<pos);
}
bool check(int N,int pos){
    return (bool)(N & (1<<pos));
}
int row,col;

int rc(int a,int b){
    return a*row+b;
}

int dp[5][5][1<<16+2];

int numberOne(int s){
    int cnt=0;
    while ( s ){
        if ( s & 1  )
            ++cnt;
        s>>=1;
    }
    return cnt;
}

void print(int n){
    string s;
    while (n){
        s+=(n&1)?"1":"0";
        n>>=1;
    }
    reverse(s.begin(),s.end());
    printf("%16s\n",s.c_str());
}

int func( int state ){
    //print(state);
    //getchar();
    if ( numberOne(state)== 1 ){
        return 1;
    }

    if ( dp[row][col][state]!=-1 )return dp[row][col][state];
    int sum=0;
    for (int i=0;i<row;++i){
        for (int j=0;j<col;++j){
            if ( check( state,rc(i,j) )==0 )
                continue;

            if ( j+2<col && check( state, rc(i,j) )==1 && check( state,rc(i,j+1))==1 && check( state,rc(i,j+2))==0 ){
                sum+=func( reset( reset( set( state,rc( i,j+2 ) ) , rc(i,j+1) )  ,rc( i,j ) ) );
            }
            if (i+2<row && j+2<col && check( state, rc(i,j) )==1 && check( state, rc(i+1,j+1) )==1 &&check( state, rc(i+2,j+2))==0 ){
                sum+=func( reset( reset( set( state,rc( i+2,j+2 ) ) ,rc( i+1,j+1 ) ),rc(i,j) ) );
                //printf("here\n");
            }
            if ( i+2<row && check( state, rc(i,j))==1 && check( state,rc(i+1,j))==1 && check( state,rc(i+2,j))==0 ){
                sum+=func( reset( reset( set( state,rc( i+2,j ) ) ,rc( i+1,j ) ) ,rc(i,j) ) );
            }
            if (i+2<row && j-2 >=0 && check( state,rc(i,j))==1 && check( state,rc(i+1,j-1))==1 && check( state,rc(i+2,j-2))==0 ){
                sum+=func( reset( reset( set( state,rc( i+2,j-2 ) ) ,rc( i+1,j-1 ) ),rc(i,j) ) );
            }
            if ( j-2 >=0 && check( state,rc(i,j))==1 && check( state,rc(i,j-1))==1 && check( state,rc(i,j-2))==0 ){
                sum+=func( reset( reset( set( state,rc( i,j-2 ) ) ,rc( i,j-1 ) ),rc(i,j) ) );
            }
            if (i-2>=0 && j-2 >=0 && check( state,rc(i,j))==1 && check( state,rc(i-1,j-1))==1 && check( state,rc(i-2,j-2))==0 ){
                sum+=func( reset( reset( set( state,rc( i-2,j-2 ) ) ,rc( i-1,j-1 ) ) ,rc(i,j) ) );
            }
            if (i-2>=0 && check( state,rc(i,j) )==1 && check( state,rc(i-1,j))==1 && check( state,rc(i-2,j))==0 ){
                sum+=func( reset( reset( set( state,rc( i-2,j ) ) ,rc( i-1,j ) ) ,rc(i,j)  ) );
            }
            if (i-2>=0 && j+2 <col && check( state, rc(i,j))==1 && check( state,rc(i-1,j+1))==1 && check( state,rc(i-2,j+2))==0 ){
                sum+=func( reset( reset( set( state,rc( i-2,j+2 ) ) ,rc( i-1,j+1 ) ),rc(i,j) ) );
            }
        }
    }
    return dp[row][col][state]=sum;
}


int main(){
    freopen("in.txt","r",stdin);

    memset(dp,-1,sizeof(dp));
    int kase,num;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        scanf("%d %d %d",&row,&col,&num);
        int n=0,a,b;
        while ( num-- ){
            scanf("%d %d",&a,&b);
            n=set( n,rc(a-1,b-1) );
            //print(n);
        }

        printf("Case %d: %d\n",kk,func(n));

    }
    return 0;

}

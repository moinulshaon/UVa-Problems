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

int Set(int N,int pos){
    return N=N | (1<<pos);
}
int Reset(int N,int pos){
    return N= N & ~(1<<pos);
}
bool Check(int N,int pos){
    return (bool)(N & (1<<pos));
}
int shaon( int x ){
    if ( x==0 )return 0;
    else  return (x&1)+shaon( x>>1 );
}

int n,m;

int dp[1<<17];
int pre[20][20];

int func( int state ){

    if ( shaon(state)>=m )return 0;

    int &ret=dp[state];

    if ( ret!= -1 )return ret;

    ret = (1<<29);
    for (int i=0;i<n;++i){
        if ( Check( state ,i)==0 ){
            ret=min( ret, 1+func( Set(state,i) ) );
            for (int j=i+1;j<n;++j){
                if ( Check( state,j ) == 0 ){
                    ret= min( ret , 1+ func( state | pre[i][j]  ) );
                }
            }
        }
    }
    return ret;
}


struct mathv{
    mathv(){x=0;y=0;}
    mathv(int a,int b){x=a;y=b;}
    int x,y;

    mathv operator + (mathv & p){
        mathv tmp( x+p.x,y+p.y );
        return tmp;
    }
    mathv operator - (mathv & p){
        mathv tmp( x-p.x,y-p.y );
        return tmp;
    }

}point[20];

int cross2D(mathv v1, mathv v2){
    return v1.x * v2.y - v1.y * v2.x;
}



int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){


        scanf("%d %d",&n,&m);

        for (int i=0;i<n;++i){
            scanf("%d %d",&point[i].x,&point[i].y);
        }

        CLR(pre);
        for (int i=0;i<n;++i){
            for (int j=i+1;j<n;++j){
                int state = 0;
                //printf("%d %d ",i,j);
                for (int k=0;k<n;++k){
                    //if ( k==j )cout<<"shaon "<<dot2D( point[i]-point[j], point[i]-point[k] )<<endl;
                    if ( cross2D( point[i]-point[j], point[i]-point[k] ) == 0 ){
                        state=Set( state,k );
                        //printf(" o %d",k);
                    }
                }
                //printf("\n");
                pre[i][j] = state;
            }
        }

        NEG(dp);
        printf("Case #%d:\n%d\n",kk,func(0));

        if ( kase )printf("\n");
    }

    return 0;
}
